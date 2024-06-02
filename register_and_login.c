#include <mysql/mysql.h> //有mysql编译和链接时，要添加库选项：gcc -o a a.c -lmysqlclient
#include <stdio.h>
#include <stdlib.h>

//改进代码：防止 SQL 注入攻击

void finish_with_error(MYSQL *con) {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
}

int register_fun(MYSQL *con, int userid, const char *userpassword, const char *username) {
    char query[512];
    snprintf(query, sizeof(query), "INSERT INTO user_information(user_id, user_password, user_name) VALUES('%d', '%s', '%s')", userid, userpassword, username);

    if(mysql_query(con, query)) {
        finish_with_error(con);
        return 0;
    }
    return 1;
}

int register_user() {
    int user_id;
    char user_password[50];
    char user_name[150];

    printf("请输入你的id：\n");
    if(scanf("%d", &user_id) != 1) {
        printf("格式错误，请输入整数！\n");
        clear_input_buffer();
        return 0;
    }

    printf("请输入你的用户名：\n");
    while((scanf("%149s", user_name)) != 1) {
        printf("格式错误，请重新输入！\n");
        clear_input_buffer();
        return 0;
    }

    printf("请输入你的密码：\n");
    while((scanf("%49s", user_password)) != 1) {
        printf("格式错误，请重新输入！\n");
        clear_input_buffer();
        return 0;
    }

    MYSQL *con = mysql_init(NULL);
    
    if(con == NULL) {
        finish_with_error(con);
        return 0;
    }

    if(mysql_real_connect(con, "localhost", "test", "1352963880Cl@", "new_schema", 0, NULL, 0) == NULL) {
        finish_with_error(con);
        return 0;
    }
    
    if(register_fun(con, user_id, user_password, user_name)) {
        mysql_close(con);
        return 1;
    } else {
        mysql_close(con);
        return 0;
    }
}

int login_fun(MYSQL *con, int userid, const char *userpassword, const char *username) {
    char query[512];
    snprintf(query, sizeof(query), "SELECT * FROM user_information WHERE user_id = %d AND user_password = '%s' AND user_name = '%s'", userid, userpassword, username);

    if(mysql_query(con, query)) {
        finish_with_error(con);
        return 0;
    }

    MYSQL_RES *result = mysql_store_result(con);
    if(result == NULL) {
        finish_with_error(con);
        return 0;
    }

    MYSQL_ROW row;
    int num_rows = mysql_num_rows(result);
    mysql_free_result(result);

    if(num_rows > 0) {
        return 1;
    }else {
        return 0;
    }
}

int login_user() {
    int user_id;
    char user_password[50];
    char user_name[150];

    printf("请输入你的id：\n");
    if(scanf("%d", &user_id) != 1) {
        printf("格式错误，请输入整数！\n");
        clear_input_buffer();
        return 0;
    }

    printf("请输入你的用户名：\n");
    while((scanf("%149s", user_name)) != 1) {
        printf("格式错误，请重新输入！\n");
        clear_input_buffer();
        return 0;
    }

    printf("请输入你的密码：\n");
    while((scanf("%49s", user_password)) != 1) {
        printf("格式错误，请重新输入！\n");
        clear_input_buffer();
        return 0;
    }

    MYSQL *con = mysql_init(NULL);
    
    if(con == NULL) {
        finish_with_error(con);
        return 0;
    }

    if(mysql_real_connect(con, "localhost", "test", "1352963880Cl@", "new_schema", 0, NULL, 0) == NULL) {
        finish_with_error(con);
        return 0;
    }
    
    if(login_fun(con, user_id, user_password, user_name)) {
        mysql_close(con);
        return 1;
    }else {
        mysql_close(con);
        return 0;
    }
   
}