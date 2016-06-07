#ifndef PGFS_TABLE_H
#define PGFS_TABLE_H

struct PQconn;

size_t
pgfs_list_tables(PGconn * conn, char const* schema, char ***tables);


size_t
pgfs_read_table(PGconn *conn, char const *tname, char* buf, size_t size);



#endif /* PGFS_TABLE_H */
