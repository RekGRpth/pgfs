#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>
#include "table.h"


int
main(int argc, char **argv)
{

  PGconn * conn = PQconnectdb("dbname=lolo");
  if (PQstatus(conn) != CONNECTION_OK) {
    fprintf(stderr, "Connection to database failed: %s",
            PQerrorMessage(conn));

  }

  /* size_t N = 96; */
  /* char * buf = (char * ) malloc(N * sizeof(char)); */
  /* size_t r = pgfs_read_table(conn, "constraintdescription", buf, N); */
  /* printf("%.*s", r, buf); */


  /* char ** ls; */
  /* size_t l =  pgfs_list_tables(conn, "public", &ls); */
  /* printf("LIST %d" , l); */
  /* for (size_t i = 0 ; i < l; i++) { */
  /*     puts(ls[i]); */
  /* } */
  return 0;
}
