#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./io.c"

#define DEFAULT_SIZE 8

typedef struct List_Node
{
    int class;
    void *name;
    int num;
    struct List_Node *next;
} *LIST_NODE;

typedef struct Hash_Table
{
    int TableSize;
    LIST_NODE *listNodes;
} *HASH_TABLE;

HASH_TABLE create_hash(int TableSize)
{
    if (TableSize <= 0)
        TableSize = DEFAULT_SIZE;
    HASH_TABLE hTable = (HASH_TABLE)malloc(sizeof(struct Hash_Table));
    if (!hTable)
        return NULL;

    hTable->TableSize = TableSize;
    hTable->listNodes = (LIST_NODE *)malloc(sizeof(struct List_Node) * TableSize);

    if (!hTable->listNodes)
    {
        free(hTable);
        return NULL;
    }
    for (int i = 0; i < TableSize; i++)
    {
        hTable->listNodes[i] = NULL;
    }
    return hTable;
}

void remove_hash(HASH_TABLE hTable)
{
    if (hTable->TableSize > 0)
    {
        for (int i = 0; i < hTable->TableSize; i++)
        {
            LIST_NODE current = hTable->listNodes[i];
            while (current != NULL)
            {
                LIST_NODE next_node = current->next;
                free(current);
                current = next_node;
            }
            hTable->listNodes[i] = NULL;
        }
    }
    free(hTable->listNodes);
    free(hTable);
}

int hash(HASH_TABLE hTable, int class)
{
    return (class % hTable->TableSize);
}

int findnode(HASH_TABLE hTable, int class, void *name)
{
    int index = hash(hTable, class);
    LIST_NODE current = hTable->listNodes[index];
    if (current != NULL)
    {
        while (current != NULL)
        {
            if (current->class == class && strcmp((char *)current->name, (char *)name) == 0)
            {
                return current->class;
            }
            current = current->next;
        }
        return -2; //忽略了一种情况：return 0;如果这里是0,就分不清是index=0还是无匹配项，
    }    // 缺少一种情况：current != NULL,且没有与之完全相同的
    else // current==NULL当前类无任何书籍
        return -1;
}


void insert(HASH_TABLE hTable, int class, char *name, int num)
{
    int exist_class = findnode(hTable, class, name);
    LIST_NODE current = (LIST_NODE)malloc(sizeof(struct List_Node));
    int index = hash(hTable, class);

    if (current != NULL && exist_class < 0) // 内存分配成功+（当前类无任何书籍 || 当前类有书籍，但没有与之完全相同的）
    {
        current->num = 0;
        current->class = class;
        current->name = strdup(name);
        
        if(current->name ==NULL) {
            free(current);
            printf("插入失败，存储名称的内存分配失败\n");
            return;
        }

        if (hTable->listNodes[index] == NULL)
        {
            current->num+=num;
            current->next = NULL;
            hTable->listNodes[index] = current;
        }
        else
        {
            current->num+=num;
            current->next = hTable->listNodes[index]->next;
            hTable->listNodes[index]->next = current;
        }
        file_input(current->class, (char *)current->name, num);
        printf("添加成功,在第%d类添加书籍“%s”%d本\n", current->class, (char *)current->name, num);
    }
    else if(exist_class >= 0) {//已有该书籍，先找到，再修改num
        LIST_NODE current_node = hTable->listNodes[index];
        while(current_node != NULL) {
            if(current_node->class == class && strcmp((char *)current_node->name, (char *)name) == 0) {
                current_node->num+=num;
                file_input(current->class, (char *)current->name, num);
                printf("添加成功,在第%d类添加书籍“%s”%d本\n", current->class, (char *)current->name, num);
                return;
            }
            current_node = current_node->next;
        }
        
    }else
    {
        if(current == NULL) {
            printf("插入失败，插入时结点分配失败\n");
        }
        free(current);
        return;
    }
}


void delete(HASH_TABLE hTable, int class, char *name, int num)
{
    int exist_class = findnode(hTable, class, name);
    int index = hash(hTable, class);
    LIST_NODE pre_node = hTable->listNodes[index];

    if (pre_node != NULL && exist_class >= 0)
    {
        LIST_NODE current = pre_node->next;
        if(current == NULL) { //只有一个节点时
            if (pre_node->class == class && strcmp((char *)pre_node->name, (char *)name) == 0 && pre_node->num >= num)
            {
                if(pre_node->num == num) {
                    hTable->listNodes[index] = NULL;
                }else {
                    pre_node->num-=num;
                }
                file_delete(pre_node->class, (char *)pre_node->name, pre_node->num);
                printf("删除成功,类别为：%d,图书名：“%s” 已被删除\n", pre_node->class, (char *)pre_node->name);
                return;
            }else if(pre_node->num < num){
                printf("删除失败,类别为：%d,图书名：“%s” 数量不够, 只有%d本\n", pre_node->class, (char *)pre_node->name, pre_node->num);
                return;
            }
        }else {//有多个节点，删除的是第一个节点时
            if (pre_node->class == class && strcmp((char *)pre_node->name, (char *)name) == 0 && pre_node->num >= num)
            {
                if(pre_node->num == num) {
                    hTable->listNodes[index] = pre_node->next;
                }else {
                    pre_node->num-=num;
                }
                file_delete(pre_node->class, (char *)pre_node->name, pre_node->num);
                printf("删除成功,类别为：%d,图书名：“%s” 已被删除\n", pre_node->class, (char *)pre_node->name);
                return;
            }else if(pre_node->num < num){
                printf("删除失败,类别为：%d,图书名：“%s” 数量不够, 只有%d本\n", pre_node->class, (char *)pre_node->name, pre_node->num);
                return;
            }
        }
        while (current != NULL)//有多个节点，删除的非第一个节点
        {
            if (current->class == class && strcmp((char *)current->name, (char *)name) == 0)
            {
                if(current->num >= num) {
                    if(current->num == num) {
                        pre_node->next = current->next;
                    }else {
                        current->num-=num;
                    }
                    file_delete(current->class, (char *)current->name, current->num);
                    printf("删除成功,类别为：%d,图书名：“%s” 已被删除\n", current->class, (char *)current->name);
                    return;
                }else {
                    printf("删除失败,类别为：%d,图书名：“%s” 数量不够, 只有%d本\n", current->class, (char *)current->name, current->num);
                    return;
                }
                
            }
            else
            {
                pre_node = pre_node->next;
                current = pre_node->next;
            }

        }
    }
    else
    {
        if(exist_class == -1) {
            printf("删除失败，您要修改的书籍所在类别为空\n");
        }else if(exist_class == -2) {
            printf("删除失败，第%d类中, “%s”这本书不存在!\n", class, (char *)name);
        }
        return;
    }
}



void revise(HASH_TABLE hTable, int class, char *name, char *new_name)
{
    int exist_class = findnode(hTable, class, name);
    int index = hash(hTable, class);
    LIST_NODE current = hTable->listNodes[index];
    if(current != NULL && exist_class >= 0) { // 结点分配成功+非空+有相同书籍
        while (current != NULL)
        {
            if (current->class == class && strcmp((char *)current->name, (char *)name) == 0)
            {
                current->name = strdup(new_name);
                file_revise(current->class, (char *)name, (char *)new_name);
                printf("修改成功，第%d类中, 成功将书籍“%s”修改成”%s“!\n", current->class, (char *)name, (char *)new_name);
            }
            else
            {
                current = current->next;
            }
        }
        
    }else {
        if(exist_class == -1) {
            printf("修改失败，您要修改的书籍所在类别为空\n");
        }else if(exist_class == -2) {
            printf("修改失败，没有这本书\n");
        }
        return;
    }
}


void printf_hash(HASH_TABLE hTable)
{
    if (hTable->TableSize > 0)
    {
        printf("您要查询的图书列表如下:\n");
        for (int i = 0; i < hTable->TableSize; i++)
        {
            LIST_NODE current = hTable->listNodes[i];
            while (current != NULL)
            {
                printf("第%d类, 图书名：“%s”, 数量: %d本\n", current->class, (char *)current->name, current->num);
                current = current->next;
            }
        }
    }
    else
    {
        return;
    }
}

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
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

void administrator_adds_book(HASH_TABLE hTable) {
    int class;
    char name[1024];
    int num;

    printf("请输入你要添加的图书类别:\n");
    if(scanf("%d", &class) != 1) {
        printf("类别输入错误，请输入一个整数\n");
        clear_input_buffer();
        return;
    }

    printf("请输入你要添加的图书名称:\n");
    if(scanf("%1023s", name) != 1) {
        printf("书名输入错误，请输入一个字符串\n");
        clear_input_buffer();
        return;
    }

    printf("请输入你要添加几本该书籍:\n");
    if(scanf("%d", &num) != 1) {
        printf("数量输入错误，请输入一个整数\n");
        clear_input_buffer();
        return;
    }
    insert(hTable, class, name, num);
    clear_input_buffer();
}

void administrator_inquiry_book(HASH_TABLE hTable) {
    int class;
    char name[1024];
    printf("请输入你要查询的图书类别:\n");
    if(scanf("%d", &class) != 1) {
        printf("类别输入错误，请输入一个整数\n");
        clear_input_buffer();
        return;
    }

    printf("请输入你要查询的图书名称:\n");
    if(scanf("%1023s", name) != 1) {
        printf("书名输入错误，请输入一个字符串\n");
        clear_input_buffer();
        return;
    }
    int inquiry_result = findnode(hTable, class, name);
    if(inquiry_result == -1) {
        printf("无此书，当前类无任何书籍\n");
    }else if(inquiry_result == -2) {
        printf("无此书\n");
    }else {
        printf("查询成功，“%s”这本书属于第%d类\n", name, inquiry_result);
    }
    clear_input_buffer();
}

void administrator_delete_book(HASH_TABLE hTable) {
    int class;
    char name[1024];
    int num;

    printf("请输入你要删除的图书类别:\n");
    if(scanf("%d", &class) != 1) {
        printf("类别输入错误，请输入一个整数\n");
        clear_input_buffer();
        return;
    }

    printf("请输入你要删除的图书名称:\n");
    if(scanf("%1023s", name) != 1) {
        printf("书名输入错误，请输入一个字符串\n");
        clear_input_buffer();
        return;
    }

    printf("请输入你要删除的图书数量:\n");
    if(scanf("%d", &num) != 1) {
        printf("数量输入错误，请输入一个整数\n");
        clear_input_buffer();
        return;
    }

    delete(hTable, class, name, num);
    clear_input_buffer();
}

void administrator_revise_book(HASH_TABLE hTable) {
    int class;
    char name[1024];
    char new_name[1024];

    printf("请输入你要修改的图书类别:\n");
    if(scanf("%d", &class) != 1) {
        printf("类别输入错误，请输入一个整数\n");
        clear_input_buffer();
        return;
    }

    printf("请输入你要修改的图书名称:\n");
    if(scanf("%1023s", name) != 1) {
        printf("书名输入错误，请输入一个字符串\n");
        clear_input_buffer();
        return;
    }

    printf("请输入你要将此图书名修改成:\n");
    if(scanf("%1023s", new_name) != 1) {
        printf("书名输入错误，请输入一个字符串\n");
        clear_input_buffer();
        return;
    }

    revise(hTable, class, name, new_name);
    clear_input_buffer();
}

void user_return_book(HASH_TABLE hTable) {
    int class;
    char name[1024];
    int num;

    printf("请输入你要归还的图书类别:\n");
    if(scanf("%d", &class) != 1) {
        printf("类别输入错误，请输入一个整数\n");
        clear_input_buffer();
        return;
    }

    printf("请输入你要归还的图书名称:\n");
    if(scanf("%1023s", name) != 1) {
        printf("书名输入错误，请输入一个字符串\n");
        clear_input_buffer();
        return;
    }

    printf("请输入你要归还几本该图书:\n");
    if(scanf("%d", &num) != 1) {
        printf("数量输入错误，请输入一个整数\n");
        clear_input_buffer();
        return;
    }

    insert(hTable, class, name, num);
    clear_input_buffer();
}


void user_borrow__book(HASH_TABLE hTable) {
    int class;
    char name[1024];
    int num; 

    printf("请输入你要借阅的图书类别:\n");
    if(scanf("%d", &class) != 1) {
        printf("类别输入错误，请输入一个整数\n");
        clear_input_buffer();
        return;
    }

    printf("请输入你要借阅的图书名称:\n");
    if(scanf("%1023s", name) != 1) {
        printf("书名输入错误，请输入一个字符串\n");
        clear_input_buffer();
        return;
    }

    printf("请输入你要借阅的图书数量:\n");
    if(scanf("%d", &num) != 1) {
        printf("数量输入错误，请输入一个整数\n");
        clear_input_buffer();
        return;
    }

    delete(hTable, class, name, num);
    clear_input_buffer();
}