#include <mysql/mysql.h>//有mysql编译和链接时，要添加库选项：gcc -o a a.c -lmysqlclient
#include <stdio.h>
#include <stdlib.h>

//改进代码：防止 SQL 注入攻击

void *clear_input_buffer() {
    char c;
    while((c = getchar()) != '\n' & c != EOF)
        ;
}

int select_user()
{
    int input;
    printf("-------------------------\n");
    printf("欢迎使用图书馆信息系统，您是：\n");
    printf("1.普通用户\n");
    printf("2.管理员\n");
    printf("-------------------------\n");
    if (scanf("%d", &input))
    {
        return input;
    }
    else
    {
        clear_input_buffer();
        return 0;
    }
}

int user_select_log_or_regist()
{
    int input;
    printf("**********************\n");
    printf("请选择：\n");
    printf("1.登陆用户\n");
    printf("2.注册账号\n");
    printf("3.找回密码\n");
    printf("**********************\n");
    if (scanf("%d", &input))
    {
        return input;
    }
    else
    {
        clear_input_buffer();
        return 0;
    }
}

int user_select_operate()
{
    int input;
    printf("**********************\n");
    printf("请选择您要进行的操作：\n");
    printf("1.浏览\n");
    printf("2.查询\n");
    printf("3.借书\n");
    printf("4.还书\n");
    printf("5.退出系统\n");
    printf("**********************\n");
    if (scanf("%d", &input))
    {
        return input;
    }
    else
    {
        clear_input_buffer();
        return 0;
    }
}

int management_select_operate()
{
    int input;
    printf("**********************\n");
    printf("请选择您要进行的操作：\n");
    printf("1.浏览\n");
    printf("2.查询\n");
    printf("3.新增图书\n");
    printf("4.删除图书\n");
    printf("5.修改图书\n");
    printf("6.退出系统\n");
    printf("**********************\n");
    if (scanf("%d", &input))
    {
        return input;
    }
    else
    {
        clear_input_buffer();
        return 0;
    }
}


void finish_with_error(MYSQL *con) {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
}


int register_fun(MYSQL *con, const char *RName, const char *RPassword) {
    char query[512];
    snprintf(query, sizeof(query), "INSERT INTO reader(RName, RPassword) VALUES('%s', '%s')", RName, RPassword);

    if(mysql_query(con, query)) {
        finish_with_error(con);
        return 0;
    }
    return 1;
}

int register_user() {
    char R_name[45];
    char R_password[45];
    

    printf("请输入你的用户名：\n");
    while((scanf("%46s", R_name)) != 1) {
        printf("格式错误，请重新输入！\n");
        clear_input_buffer();
        return 0;
    }

    printf("请输入你的密码：\n");
    while((scanf("%46s", R_password)) != 1) {
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
    
    if(register_fun(con, R_name, R_password)) {
        mysql_close(con);
        return 1;
    } else {
        mysql_close(con);
        return 0;
    }
}

int login_fun(MYSQL *con, const char *RName, const char *RPassword) {
    char query[512];
    snprintf(query, sizeof(query), "SELECT * FROM reader WHERE RName = '%s' AND RPassword = '%s'", RName, RPassword);

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
    char R_password[45];
    char R_name[45];

    printf("请输入你的用户名：\n");
    while((scanf("%45s", R_name)) != 1) {
        printf("格式错误，请重新输入！\n");
        clear_input_buffer();
        return 0;
    }

    printf("请输入你的密码：\n");
    while((scanf("%45s", R_password)) != 1) {
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
    
    if(login_fun(con, R_name, R_password)) {
        mysql_close(con);
        return 1;
    }else {
        mysql_close(con);
        return 0;
    }
   
}

int insert_or_return_book_fun(MYSQL *con, int isbn, char *bname, int bcategory, float price, int bcount, char *pubdate, char *author, char *pubcomp) {
    char query1[512];
    snprintf(query1, sizeof(query1), "SELECT * FROM book WHERE ISBN='%d' AND BName='%s' AND BCategory='%d' AND ABS(Price-'%f') < 0.001 AND PubDate='%s' AND Author='%s' AND PubComp='%s'", isbn, bname, bcategory, price, pubdate, author, pubcomp);
    
    
    if(mysql_query(con, query1)) { //如果查询成功，返回0。如果出现错误，返回非0值
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
        char query3[512];
        snprintf(query3, sizeof(query3), "UPDATE `new_schema`.`book` SET `Bcount` = `Bcount`+'%d' WHERE (`ISBN` = '%d')", bcount, isbn);
        if(mysql_query(con, query3)) {
            finish_with_error(con);
            return 0;
        }
        return 1;
    }else {
        char query2[512];
        snprintf(query2, sizeof(query2), "INSERT INTO `new_schema`.`book` (`ISBN`, `BName`, `BCategory`, `Price`, `Bcount`, `PubDate`, `Author`, `PubComp`) VALUES ('%d', '%s', '%d', '%f', '%d', '%s', '%s', '%s')", isbn, bname, bcategory, price, bcount, pubdate, author, pubcomp);
        if(mysql_query(con, query2)) {
            finish_with_error(con);
            return 0;
        }
        return 1;
    }

}

int insert_or_return_book() {
    int isbn;
    char bname[45];
    int bcategory;
    float price;
    int bcount;
    char pubdate[45];
    char author[45];
    char pubcomp[45];


    printf("请输入你要添加/归还的图书ISBN:\n");
    if(scanf("%d", &isbn) != 1) {
        printf("ISBN输入错误，请输入一个整数\n");
        clear_input_buffer();
        return 0;
    }

    printf("请输入你要添加/归还的图书名称:\n");
    if(scanf("%45s", bname) != 1) {
        printf("书名输入错误，请输入一个字符串\n");
        clear_input_buffer();
        return 0;
    }

    printf("请输入你要添加/归还的图书类别:\n");
    if(scanf("%d", &bcategory) != 1) {
        printf("类别输入错误，请输入一个数字\n");
        clear_input_buffer();
        return 0;
    }

    printf("请输入你要添加/归还的图书价格:\n");
    if(scanf("%f", &price) != 1) {
        printf("价格输入错误，请输入一个浮点数\n");
        clear_input_buffer();
        return 0;
    }

    printf("请输入你要添加/归还的图书数量:\n");
    if(scanf("%d", &bcount) != 1) {
        printf("数量输入错误，请输入一个整数\n");
        clear_input_buffer();
        return 0;
    }

    printf("请输入你要添加/归还的图书出版时间，输入格式为24/3/2:\n");
    if(scanf("%45s", pubdate) != 1) {
        printf("出版时间输入错误，请输入一个字符串\n");
        clear_input_buffer();
        return 0;
    }

    printf("请输入你要添加/归还的图书作者:\n");
    if(scanf("%45s", author) != 1) {
        printf("作者输入错误，请输入一个字符串\n");
        clear_input_buffer();
        return 0;
    }

    printf("请输入你要添加/归还的图书出版社名称:\n");
    if(scanf("%45s", pubcomp) != 1) {
        printf("出版社名称输入错误，请输入一个字符串\n");
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

    if(insert_or_return_book_fun(con, isbn, bname, bcategory, price, bcount, pubdate, author,pubcomp)) {
        mysql_close(con);
        return 1;
    }else {
        mysql_close(con);
        return 0;
    }

    
}

int delete_or_borrow_book_fun(MYSQL *con, int isbn, int bcount) {
    char query[512];
    snprintf(query, sizeof(query), "SELECT * FROM book WHERE ISBN='%d'", isbn);

    if(mysql_query(con, query)) {
        finish_with_error(con);
        return 0;
    }

    MYSQL_RES *result = mysql_store_result(con);
    if(result == NULL) {
        finish_with_error(con);
        return 0;
    }

    int num_rows = mysql_num_rows(result);
    mysql_free_result(result);


    char query2[512];
    int bcount_num;
    snprintf(query2, sizeof(query2), "SELECT Bcount FROM book WHERE ISBN='%d'", isbn);
    if(mysql_query(con, query2)) {
        finish_with_error(con);
        return 0;
    }
    MYSQL_RES *result2 = mysql_store_result(con);
    if(result2 == NULL) {
        finish_with_error(con);
        return 0;
    }
    MYSQL_ROW row2 = mysql_fetch_row(result2);
    mysql_free_result(result2);
    
    if(num_rows > 0 && atoi(row2[0])-bcount >= 0) {
        char query3[512];
        snprintf(query3, sizeof(query3), "UPDATE `new_schema`.`book` SET `Bcount` = `Bcount`-'%d' WHERE (`ISBN` = '%d')", bcount, isbn);
        
        if(mysql_query(con, query3)) {
            finish_with_error(con);
            return 0;
        }

        return 1;
    }else {
        return 0;
    }

}

int delete_or_borrow_book() {
    int isbn;
    int bcount;

    printf("请输入你要删除/借阅的图书ISBN:\n");
    if(scanf("%d", &isbn) != 1) {
        printf("ISBN输入错误，请输入一个整数\n");
        clear_input_buffer();
        return 0;
    }

    printf("请输入你要删除/借阅的图书数量:\n");
    if(scanf("%d", &bcount) != 1) {
        printf("数量输入错误，请输入一个整数\n");
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

    if(delete_or_borrow_book_fun(con, isbn, bcount)) {
        mysql_close(con);
        return 1;
    }else {
        mysql_close(con);
        return 0;
    }
    
}

int browse_book() {
    MYSQL *con = mysql_init(NULL);
    if(con == NULL) {
        finish_with_error(con);
        return 0;
    }

    if(mysql_real_connect(con, "localhost", "test", "1352963880Cl@", "new_schema", 0, NULL, 0) == NULL) {
        finish_with_error(con);
        return 0;
    }

    char query[150];
    snprintf(query, sizeof(query), "SELECT * FROM new_schema.book");

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

    printf("num_rows:%d\n", num_rows);

    int line_number = 1;
    if(num_rows > 0) {
        printf("     ISBN    BName    BCategory    Price    Bcount    PubDate    Author    PubComp\n");
        while((row = mysql_fetch_row(result))) {
            printf("%d    %s    %s    %s    %s    %s    %s    %s    %s\n", line_number, row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
            line_number+=1;
        }
        mysql_free_result(result);
        mysql_close(con);
        return 1;
    }else {
        mysql_free_result(result);
        mysql_close(con);
        return 0;
    }
}

int inquire_book() {
    char bname[45];

    printf("请输入你要c查询的图书名称:\n");
    if(scanf("%45s", bname) != 1) {
        printf("书名输入错误，请输入一个字符串\n");
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
    
    char query[512];
    snprintf(query, sizeof(query), "SELECT * FROM book WHERE BName LIKE '%%%s%%'", bname);//%%转义成%

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
    int line_number = 1;
    if(num_rows > 0) {
        printf("     ISBN    BName    BCategory    Price    Bcount    PubDate    Author    PubComp\n");
        while((row = mysql_fetch_row(result))) {
            printf("%d    %s    %s    %s    %s    %s    %s    %s    %s\n", line_number, row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
            line_number+=1;
        }
        mysql_free_result(result);
        mysql_close(con);
        return 1;
    }else {
        mysql_free_result(result);
        mysql_close(con);
        return 0;
    }


}

int revise_book_op() {
    int input;
    printf("**********************\n");
    printf("你要修改图书哪些信息：\n");
    printf("1.ISBN\n");
    printf("2.BNAME-书名\n");
    printf("3.BCategory-图书类别\n");
    printf("4.Price-图书价格\n");
    printf("5.Bcount-图书数量\n");
    printf("6.PubDate-出版时间\n");
    printf("7.Author-作者\n");
    printf("8.PubComp-出版社\n");
    printf("**********************\n");
    if (scanf("%d", &input))
    {
        return input;
    }
    else
    {
        clear_input_buffer();
        return 0;
    }
}

int revise_book() {
    int isbn;
    int selection;

    printf("请输入你要修改的图书ISBN：\n");
    if(scanf("%d", &isbn) != 1) {
        printf("ISBN输入错误，请输入一个数字\n");
        clear_input_buffer();
        return 0;
    }

    selection = revise_book_op();
    MYSQL *con = mysql_init(NULL);
    if(con ==NULL) {
        finish_with_error(con);
        return 0;
    }

    if(mysql_real_connect(con, "localhost", "test", "1352963880Cl@", "new_schema", 0, NULL, 0) == NULL) {
        finish_with_error(con);
        return 0;
    }

    char query[512];
    char revise_after[45];
        
    switch (selection)
    {
        case 1:
            printf("你要将该书ISBN修改为：\n");
            if(scanf("%s"    , revise_after) != 1) {
                return 0;
            }else {
                snprintf(query, sizeof(query), "UPDATE `new_schema`.`book` SET `ISBN` = '%s' WHERE (`ISBN` = '%d')", revise_after, isbn);
                break;
            }
        case 2:
            printf("你要将该书名修改为：\n");
            if(scanf("%s", revise_after) != 1) {
                return 0;
            }else {
                snprintf(query, sizeof(query), "UPDATE `new_schema`.`book` SET `BName` = '%s' WHERE (`ISBN` = '%d')", revise_after, isbn);
                break;
            }
        case 3:
            printf("你要将该书类别修改为：\n");
            if(scanf("%s", revise_after) != 1) {
                return 0;
            }else {
                snprintf(query, sizeof(query), "UPDATE `new_schema`.`book` SET `BCategory` = '%s' WHERE (`ISBN` = '%d')", revise_after, isbn);
                break;
            }
        case 4:
            printf("你要将该书价格修改为：\n");
            if(scanf("%s", revise_after) != 1) {
                return 0;
            }else {
                snprintf(query, sizeof(query), "UPDATE `new_schema`.`book` SET `Price` = '%s' WHERE (`ISBN` = '%d')", revise_after, isbn);
                break;
            }
        case 5:
            printf("你要将该书数量修改为：\n");
            if(scanf("%s", revise_after) != 1) {
                return 0;
            }else {
                snprintf(query, sizeof(query), "UPDATE `new_schema`.`book` SET `Bcount` = '%s' WHERE (`ISBN` = '%d')", revise_after, isbn);
                break;
            }
        case 6:
            printf("你要将该书出版时间修改为：\n");
            if(scanf("%s", revise_after) != 1) {
                return 0;
            }else {
                snprintf(query, sizeof(query), "UPDATE `new_schema`.`book` SET `PubDate` = '%s' WHERE (`ISBN` = '%d')", revise_after, isbn);
                break;
            }
        case 7:
            printf("你要将该书作者修改为：\n");
            if(scanf("%s", revise_after) != 1) {
                return 0;
            }else {
                snprintf(query, sizeof(query), "UPDATE `new_schema`.`book` SET `Author` = '%s' WHERE (`ISBN` = '%d')", revise_after, isbn);
                break;
            }
        case 8:
            printf("你要将该书出版社修改为：\n");
            if(scanf("%s", revise_after) != 1) {
                return 0;
            }else {
                snprintf(query, sizeof(query), "UPDATE `new_schema`.`book` SET `PubComp` = '%s' WHERE (`ISBN` = '%d')", revise_after, isbn);
                break;
            }
        default:
            return 0;
    }
    
    if(mysql_query(con, query)) {
        finish_with_error(con);
        return 0;
    }
    mysql_close(con);

    return 1; 
    

}