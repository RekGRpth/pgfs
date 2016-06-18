#ifndef PGFS_SCHEMA_H
#define PGFS_SCHEMA_H

struct PQconn;

size_t
pgfs_list_schemas(PGconn * conn, char ***schemas);


#endif /* PGFS_SCHEMA_H */
