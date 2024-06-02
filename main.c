#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include "lms.c"
#include "register_and_login.c"

#define DEFAULT_SIZE 8

int main()
{
    HASH_TABLE hTable = create_hash(DEFAULT_SIZE);

    while (1)
    {
        int user = select_user();
        if (user == 1)
        { // 普通用户
            while (1) {
                int user_select = user_select_log_or_regist();
                if (user_select == 1)
                { // 登陆
                    printf("登录\n");
                    if(login_user() == 1) {
                        printf("登录成功\n");
                        break;
                    }else {
                        printf("登录失败，请输入正确信息\n");
                    }
                }
                else if (user_select == 2)
                { // 注册
                    printf("注册\n");
                    if(register_user() ==1) {
                        printf("注册成功\n");
                    }else {
                        printf("注册失败\n");
                    }
                }else if(user_select == 3) {
                    printf("找回密码");
                }else {
                    printf("无效的选择，请重新选择。\n");
                }
            }

            // 验证帐号密码是否正确，若已正确：

            while (1)
            { // 用户操作界面
                int user_operate = user_select_operate();
                if (user_operate == 1)
                { // 浏览
                    printf("浏览\n");
                    printf_hash(hTable);
                }
                else if (user_operate == 2)
                { // 查询
                    printf("查询\n");
                    administrator_inquiry_book(hTable);
                }
                else if (user_operate == 3)
                { // 借书
                    printf("借书\n");  
                    user_borrow__book(hTable); //借书时返回借书成功。。
                }
                else if (user_operate == 4)
                { // 还书
                    printf("还书\n");
                    user_return_book(hTable);
                }
                else if (user_operate == 5)
                { // 退出系统
                    printf("退出系统\n");
                    break;
                }
                else
                {
                    printf("请输入正确编码(1~5)!\n");
                }
            }
        }
        else if (user == 2)
        { // 管理员用户
            printf("登陆管理员\n");
            // 验证帐号密码是否正确，若已正确：

            while (1)
            {
                int management_operate = management_select_operate();
                if (management_operate == 1)
                { // 浏览
                    printf("浏览\n");
                    printf_hash(hTable);
                }
                else if (management_operate == 2)
                { // 查询
                    printf("查询\n");
                    administrator_inquiry_book(hTable);
                }
                else if (management_operate == 3)
                { // 新增图书
                    printf("新增图书\n");
                    administrator_adds_book(hTable);
                }
                else if (management_operate == 4)
                { // 删除图书
                    printf("删除图书\n");
                    administrator_delete_book(hTable); 
                }
                else if (management_operate == 5)
                { // 修改图书
                    printf("修改图书\n");
                    administrator_revise_book(hTable);
                }
                else if (management_operate == 6)
                { // 退出系统
                    printf("退出系统\n");
                    break;
                }
                else
                {
                    printf("请输入正确编码(1~6)!\n");
                }
            }
        }
        else
        { // 其他
            printf("请输入正确编码(1或2)!\n");
        }
    }

    remove_hash(hTable);
    return 0;
}