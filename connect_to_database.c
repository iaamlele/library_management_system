#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>

void finish_with_error(MYSQL *con) {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

int main() {
    MYSQL *con = mysql_init(NULL);
    if(con ==NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

    if(mysql_real_connect(con, "localhost", "test", "1352963880Cl@", "new_schema", 0, NULL, 0) == NULL) {
        finish_with_error(con);
    }

    if(mysql_query(con, "SELECT * FROM new_schema.user_information")) {
        finish_with_error(con);
    }

    MYSQL_RES *result = mysql_store_result(con);

    if(result == NULL) {
        finish_with_error(con);
    }

    int num_field = mysql_num_fields(result);

    MYSQL_ROW row; // row数组包含了当前行的每个列的值。每个列的值可以通过数组的索引访问。

    while((row = mysql_fetch_row(result))) {
        for(int i = 0; i < num_field; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);
    mysql_close(con);

    return 0;
}