#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

/**
 * ��������
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
    FILE *fp = fopen("../base_file/filesource/��������.txt", "w");
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
    FILE *fp1 = fopen("../base_file/filesource/��������.txt", "r");
    FILE *fp2 = fopen("../base_file/filesource/����������.txt", "w");
    if (!fp1 || !fp2) {
        printf("���ļ�ʧ��\n");
        return -1;
    }
    //!feof(fp);  EOF -1
    int a, b, sum;
    char c;
    char *p = (char *) malloc(sizeof(char) * 20);
    for (int i = 0; i < 100; i++) {
        memset(p, 0, 20);
        //���ļ��ж�ȡ���ݴ����ַ���p��
        fgets(p, 20, fp1);

        //6*6=\n
        //���ַ���p�ж�ȡ���ݣ���ʽ����ֵ��a,b,c
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
        //���ݲ���format�ַ�����ת������ʽ�����ݣ�Ȼ�󽫽�������strָ���Ŀռ���
        sprintf(p, "%d%c%d=%d\n", a, c, b, sum);
        //�ַ���д���ļ���
        fputs(p, fp2);
    }

    free(p);
    fclose(fp1);
    fclose(fp2);

    return EXIT_SUCCESS;
}