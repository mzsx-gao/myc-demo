#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <mem.h>

/**
 * �ļ���ʽ����д
 * @return
 */
//��������
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
    //��ch���ڴ������ǰ20���ֽ��Բ���0����
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

//д�ļ�
int write_file() {
    FILE *fp = fopen("../base_file/filesource/d.txt", "w");
    if (!fp)
        return -1;
    printf("д�ļ���ʼ...\n");
    int a = 10;
    int count = fprintf(fp, "%05x", a);
    printf("д���ļ�����%d\n", count);
    fclose(fp);
    return 0;
}

//���ļ�
int read_file() {
    FILE *fp = fopen("../base_file/filesource/d.txt", "r");
    if (!fp)
        return -1;

    int a;
    printf("���ļ���ʼ...");
    fscanf(fp, "%x", &a);
    printf("%d\n", a);
    fclose(fp);

    return 0;
}


/**
 * ��������
 * @return
 */
int mainfile14(){
    demo6();
    demo7();
}
//��������������Ŀ
int demo6(void) {
    srand((size_t) time(NULL));
    FILE *fp = fopen("../base_file/filesource/��������.txt", "w");
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
//��ȡ����������Ŀ����������������
int demo7(void) {
    FILE *fp1 = fopen("../base_file/filesource/��������.txt", "r");
    FILE *fp2 = fopen("../base_file/filesource/����������.txt", "w");
    if (!fp1 || !fp2) {
        printf("���ļ�ʧ��\n");
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
//���0-255  ���1000  �Ը�ʽ����ʽд���ļ���
//��ȡ 1000����  �����������ļ���