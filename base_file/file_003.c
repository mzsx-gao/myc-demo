#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

/**
 * 四则运算
 */
enum opt {
    add, sub, mlt, dive
};

int demo1();
int demo2();

int mainfile12(){
//    demo1();
   return demo2();
}

int demo1() {
    srand((size_t) time(NULL));
    FILE *fp = fopen("../base_file/filesource/四则运算.txt", "w");
    if (!fp)
        return -1;
    int a, b;
    char c;//+ - * /
    char *p = (char *) malloc(sizeof(char) * 20);
    for (int i = 0; i < 100; i++) {
        a = rand() % 10 + 1;
        b = rand() % 10 + 1;

        switch (rand() % 4) {
            case add:
                c = '+';
                break;
            case sub:
                c = '-';
                break;
            case mlt:
                c = '*';
                break;
            case dive:
                c = '/';
                break;
        }
        memset(p, 0, 20);
        sprintf(p, "%d%c%d=\n", a, c, b);
        fputs(p, fp);
    }
    free(p);
    fclose(fp);
    //p = NULL;
    //fp = NULL;
    return EXIT_SUCCESS;
}

int demo2(){
    FILE *fp1 = fopen("../base_file/filesource/四则运算.txt", "r");
    FILE *fp2 = fopen("../base_file/filesource/四则运算结果.txt", "w");
    if (!fp1 || !fp2) {
        printf("打开文件失败\n");
        return -1;
    }
    //!feof(fp);  EOF -1
    int a, b, sum;
    char c;
    char *p = (char *) malloc(sizeof(char) * 20);
    for (int i = 0; i < 100; i++) {
        memset(p, 0, 20);
        //从文件中读取数据存入字符串p中
        fgets(p, 20, fp1);

        //6*6=\n
        //从字符串p中读取数据，格式化后赋值给a,b,c
        sscanf(p, "%d%c%d=\n", &a, &c, &b);
        switch (c) {
            case '+':
                sum = a + b;
                break;
            case '-':
                sum = a - b;
                break;
            case '*':
                sum = a * b;
                break;
            case '/':
                sum = a / b;
                break;
        }

        memset(p, 0, 20);
        //根据参数format字符串来转换并格式化数据，然后将结果输出到str指定的空间中
        sprintf(p, "%d%c%d=%d\n", a, c, b, sum);
        //字符串写入文件中
        fputs(p, fp2);
    }

    free(p);
    fclose(fp1);
    fclose(fp2);

    return EXIT_SUCCESS;
}