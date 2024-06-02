#include <stdio.h>
#include <stdlib.h>

int file_input(int class, char *name, int num) {
    FILE *file = fopen("./books.txt", "r");
    FILE *tmp = fopen("./tmp.txt", "w");
    char line[256];
    char line_copy[256+1];
    char *token;
    char *saveptr;

    char class_str[50];
    sprintf(class_str, "%d", class);

    if(file == NULL) {
        fprintf(stderr, "Error opening file!\n");
        return 0;
    }
    if(fgets(line ,sizeof(line), file) == NULL) {
        fprintf(tmp, "%d %s %d\n", class, (char *)name, num);
    }else {
        rewind(file);

        int found = 0;

        while(fgets(line ,sizeof(line), file) != NULL) {
            
            strcpy(line_copy, line);
            token = strtok_r(line, " ", &saveptr);
            
            if(token && strcmp(class_str, token) == 0) {
                token = strtok_r(NULL, " ", &saveptr);
                if(token && strcmp(name, token) == 0) {
                    found = 1;
                    fprintf(tmp, "%s %s", class_str, name);
                    if((token = strtok_r(NULL, " ", &saveptr))) {//token打印%s是4,要让4-1=3,先把字符串转化成int，再把int转换成字符数组
                    
                        int token_int = atoi(token);
                        char token_num[50];

                        sprintf(token_num, "%d", token_int + num);
                        fputc(' ', tmp);
                        fputs(token_num, tmp);
                        fputc('\n', tmp);
                    }

                    continue;
                }
            }
            fputs(line_copy, tmp);        
        }
        if(!found) {
            fprintf(tmp, "%d %s %d\n", class, name, num);
        }
    }

    fclose(file);
    fclose(tmp);

    remove("./books.txt");
    rename("tmp.txt", "books.txt");
    return 1;
}

int file_revise(int class, char *name, char *new_name) {
    FILE *file = fopen("./books.txt", "r");
    FILE *tmp = fopen("./tmp.txt", "w");

    char line[256];
    char copy_line[256+1];
    char *token;
    char class_str[50];
    sprintf(class_str, "%d", class);

    char *saveptr = NULL;

    if(file == NULL) {
        fprintf(stderr, "Error opening file!\n");
        return 0;
    }
    
    while(fgets(line, sizeof(line), file)) {
        strcpy(copy_line, line);
        token = strtok_r(line, " ", &saveptr);

        if(token && strcmp(token, class_str) == 0) {
            token = strtok_r(NULL, " ", &saveptr);
            if(token && strcmp(token, name) == 0) {
                fprintf(tmp, "%s %s", class_str, new_name);
                while((token = strtok_r(NULL, "\n", &saveptr))) {
                    fputc(' ', tmp);
                    fputs(token, tmp);
                }
                fputc('\n', tmp);
                continue;
            }
        }
        fputs(copy_line, tmp);
    }

    fclose(file);
    fclose(tmp);

    remove("./books.txt");
    rename("./tmp.txt", "./books.txt");

    return 1;
}

int file_delete(int class, char *name, int num) {

    FILE *file = fopen("./books.txt", "r");
    FILE *tmp = fopen("./tmp.txt", "w");
    char line[256];
    char line_copy[256+1];
    char *token;
    char *saveptr;

    char class_str[50];
    sprintf(class_str, "%d", class);

    if(file == NULL) {
        fprintf(stderr, "Error opening file!\n");
        return 0;
    }

    while((fgets(line ,sizeof(line), file))) {
        strcpy(line_copy, line);
        token = strtok_r(line, " ", &saveptr);
        
        if(token && strcmp(class_str, token) == 0) {
            token = strtok_r(NULL, " ", &saveptr);
            if(token && strcmp(name, token) == 0) {

                fprintf(tmp, "%s %s", class_str, name);
                if((token = strtok_r(NULL, " ", &saveptr))) {//token打印%s是4,要让4-1=3,先把字符串转化成int，再把int转换成字符数组
                 
                    int token_int = atoi(token);
                    char token_num[50];

                    sprintf(token_num, "%d", token_int - num);
                    fputc(' ', tmp);
                    fputs(token_num, tmp);
                    fputc('\n', tmp);
                }

                continue;
            }
        }

        fputs(line_copy, tmp);        
    }
    fclose(file);
    fclose(tmp);

    remove("./books.txt");
    rename("tmp.txt", "books.txt");
    return 1;
}