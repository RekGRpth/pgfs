#include <string.h>
#include <libpq-fe.h>
#include <stdlib.h>


size_t
pgfs_list_schemas(PGconn * conn, char ***schemas)
{

    // fake implementation (meanwhile)
    *schemas = (char **) malloc( sizeof(char*) );
    **schemas = (char *) malloc( strlen("public") + 1);
    strcpy(**schemas, "public");

    return 1;
}
