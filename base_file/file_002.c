#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
 * 文件行读写
 */
int main_file08() {
    FILE *fp = fopen("../base_file/filesource/a.txt", "r");
    if (!fp){
        printf("文件打开失败\n");
        return -1;
    }
    char *p = (char *) malloc(sizeof(char) * 1024);

    memset(p, 0, 5);
    fgets(p, 5, fp);
    printf("第一次读:%s\n", p);

    printf("=====\n");
    memset(p, 0, 5);
    fgets(p, 5, fp);
    printf("第二次读:%s\n", p);

    free(p);
    fclose(fp);

    return EXIT_SUCCESS;
}


int main_file09(void) {
    FILE *fp = fopen("../base_file/filesource/a.txt", "r");
    if (!fp){
        return -1;
    }
    char *p = (char *) malloc(sizeof(char) * 100);

    //feof（文件指针）  判断文件是否到结尾 可以判断文本文件也可以判断二进制文件
    //如果到文件结尾返回值为 非0的值
    //如果没到文件结尾返回值为 0
    while (!feof(fp)) {
        memset(p, 0, 100);
        fgets(p, 100, fp);
        printf("%s", p);
    }
    free(p);
    fclose(fp);
    return 0;
}

//将str所指定的字符串写入到stream指定的文件中，字符串结束符 '\0'  不写入文件
int main_file10(void) {
    FILE *fp = fopen("../base_file/filesource/b.txt", "w");
    if (!fp)
        return -1;
    char ch[] = "你瞅啥瞅你咋地拉";
    fputs(ch, fp);
    fclose(fp);
    return 0;
}

int main(void) {
    FILE *fp = fopen("../base_file/filesource/b.txt", "w");
    if (!fp)
        return -1;

    char *p = (char *) malloc(sizeof(char) * 1024);

    while (1) {
        memset(p, 0, 1024);
        //scanf("%s", p);
        //fgets()
        scanf("%[^\n]", p);
        //吞噬回车\n
        getchar();
        //停止输入命令  comm=exit
        if (!strcmp(p, "comm=exit")){
            break;
        }
        //追加\n
        strcat(p, "\n");
        fputs(p, fp);
    }
    free(p);
    fclose(fp);
}