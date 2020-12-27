#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <mem.h>

/**
 * 文件格式化读写
 * @return
 */
//声明函数
int write_file();

int read_file();

int demo5(void);

int demo6(void);

int demo7(void);

int mainfile13() {
//    demo3();
//    return demo4();
    return demo5();
}

int demo3() {
    FILE *fp = fopen("../base_file/filesource/d.txt", "r");
    if (!fp)
        return -1;
    char *p = (char *) malloc(sizeof(char) * 100);

    int a;
    fscanf(fp, "%3d", &a);
    printf("%d\n", a);

    fscanf(fp, "%s", p);
    printf("%s", p);

    fscanf(fp, "%s", p);
    printf("%s", p);

    fscanf(fp, "%s", p);
    printf("%s", p);

    fscanf(fp, "%s", p);
    printf("%s", p);
    fscanf(fp, "%s", p);
    printf("%s", p);

    free(p);
    fclose(fp);


    return EXIT_SUCCESS;
}

int demo4(void) {
    FILE *fp = fopen("../base_file/filesource/d.txt", "r");
    if (!fp)
        return -1;
    //int a, b, c;
    //fscanf(fp, "%d+%d=%d", &a, &b, &c);
    char ch[20] = {0};
    //将ch的内存区域的前20个字节以参数0填入
    memset(ch, 0, 20);
//    fscanf(fp, "%[^\n]", ch);
    fscanf(fp, "%11c", ch);
//    fscanf(fp, "%3c", ch);
//    fscanf(fp, "%3s", ch);
    printf("%s\n", ch);
    //printf("%d\n", a);
    //printf("%d\n", b);
    //printf("%d\n", c);
}


int demo5(void) {
    write_file();
    read_file();
    return 0;
}

//写文件
int write_file() {
    FILE *fp = fopen("../base_file/filesource/d.txt", "w");
    if (!fp)
        return -1;
    printf("写文件开始...\n");
    int a = 10;
    int count = fprintf(fp, "%05x", a);
    printf("写入文件个数%d\n", count);
    fclose(fp);
    return 0;
}

//读文件
int read_file() {
    FILE *fp = fopen("../base_file/filesource/d.txt", "r");
    if (!fp)
        return -1;

    int a;
    printf("读文件开始...");
    fscanf(fp, "%x", &a);
    printf("%d\n", a);
    fclose(fp);

    return 0;
}


/**
 * 四则运算
 * @return
 */
int mainfile14(){
    demo6();
    demo7();
}
//生成四则运算题目
int demo6(void) {
    srand((size_t) time(NULL));
    FILE *fp = fopen("../base_file/filesource/四则运算.txt", "w");
    if (!fp)
        return -1;
    int a, b;
    char c;
    for (int i = 0; i < 100; i++) {
        a = rand() % 10 + 1;
        b = rand() % 10 + 1;
        switch (rand() % 4) {
            case 0:
                c = '+';
                break;
            case 1:
                c = '-';
                break;
            case 2:
                c = '*';
                break;
            case 3:
                c = '/';
                break;
        }
        fprintf(fp, "%d%c%d=\n", a, c, b);
    }
    fclose(fp);
}
//读取四则运算题目，生成四则运算结果
int demo7(void) {
    FILE *fp1 = fopen("../base_file/filesource/四则运算.txt", "r");
    FILE *fp2 = fopen("../base_file/filesource/四则运算结果.txt", "w");
    if (!fp1 || !fp2) {
        printf("打开文件失败\n");
        return -1;
    }
    int a, b, sum;
    char c;
    for (int i = 0; i < 100; i++) {
        fscanf(fp1, "%d%c%d=\n", &a, &c, &b);
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
        fprintf(fp2, "%d%c%d=%d\n", a, c, b, sum);
    }
    fclose(fp1);
    fclose(fp2);
}
//随机0-255  随机1000  以格式化方式写入文件中
//读取 1000个数  排序后存在新文件中