#include <string.h>
#include <libpq-fe.h>
#include <stdlib.h>


size_t
pgfs_list_tables(PGconn * conn, char const* sch, char ***ltables)
{
    char stm[] =
        "SELECT "
        " tablename "
        "FROM "
        "  pg_catalog.pg_tables "
        "WHERE "
        "  schemaname = $1 ";


    char const** param = &sch;

    PGresult *res = PQexecParams(conn, stm, 1, NULL, param, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        return 0;
    }

    int nrow =  PQntuples(res);
    *ltables = (char **) malloc( nrow * sizeof(char*) );
    for (int r = 0; r < nrow; r++) {
        char * table = PQgetvalue(res, r, 0);
        size_t len   = strlen(table);
        char * tmp   = (char *) malloc(len * sizeof(char) + 1);
        strcpy(tmp, table);
        (*ltables)[r] = tmp;
    }

    return nrow;

}


size_t
pgfs_read_table(PGconn *conn, char const *tname, char* buf, size_t size)
{

  char stm[100] = "SELECT * FROM ";
  strcat(stm, tname);

  PGresult *res = PQexec(conn, stm);

  if (PQresultStatus(res) != PGRES_TUPLES_OK) {
    return 0;
  }

  int ncol =  PQnfields(res);
  int nrow =  PQntuples(res);
  size_t rem = size;
  char * idx = buf;

  for (int r = 0; r < nrow; r++) {
    for (int c = 0; c < ncol; c++) {
        if (rem > 0) {
            char * field = PQgetvalue(res, r, c);
            size_t flen  = strlen(field);
            if (flen <= rem) {
                idx = memcpy(idx, field, flen) + flen;
                rem -= flen;
                if ((rem > 0) && (c + 1 < ncol) ) {
                    idx = memcpy(idx, ",", 1) + 1;
                    rem -= 1;
                }
            } else {
               idx = memcpy(idx, field, rem) + rem;
               rem = 0;
            }

        }
    }

    if (rem > 0) {
        idx = memcpy(idx, "\n", 1) + 1;
        rem -= 1;
    }else {
        return size;
    }
  }

  return size - rem;

}
