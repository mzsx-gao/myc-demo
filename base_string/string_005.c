#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

/*
 * �ַ����ָ�:
 * strtok ���ƻ�Դ�ַ���,��\0�滻�ָ�ı�־λ
 * �ڵ�һ�ε���ʱ��strtok()����������s�ַ���;
 * ����ĵ����򽫲���s���ó�NULL��ÿ�ε��óɹ��򷵻�ָ�򱻷ָ��Ƭ�ε�ָ��
 */
int main_strtok1() {
    char ch[] = "www.csci.com";//www\0csci\0com

    char *p = strtok(ch, ".");
    printf("%s\n", p);

    p = strtok(NULL, ".");
    printf("%s\n", p);

    p = strtok(NULL, ".");
    printf("%s\n", p);
    return EXIT_SUCCESS;
}

int main_strtok2(void) {
    char ch[] = "123456@qq.com";
    char str[100] = {0};

    //�ַ�������
    strcpy(str, ch);

    char *p = strtok(str, "@");
    printf("%s\n", p);
    p = strtok(NULL, ".");
    printf("%s\n", p);
    return 0;

}

int main_strtok3(void) {
    char ch[] = "���ɶ\n����զ��\n�ٳ�һ������\n�Բ������Ҵ��\n������";

    char *p = strtok(ch, "\n");

    while (p) {
        printf("%s\n", p);
        p = strtok(NULL, "\n");
    }
    return 0;
}


/*
 * �ַ�������ת��atoi:
 * ɨ��nptr�ַ���������ǰ��Ŀո��ַ���ֱ���������ֻ������Ųſ�ʼ��ת���������������ֻ��ַ���������('\0')�Ž���ת����
 * ����������ط���ֵ
 */
int main_atoi() {
    char ch[] = "    -123-456abc123";
    int i = atoi(ch);
    printf("%d\n", i);
    return EXIT_SUCCESS;
}

//atof():��һ��С����ʽ���ַ���ת��Ϊһ��������
int main_atof() {
    char ch[] = "    -123.456-456abc123";
    double i = atof(ch);
    printf("%.2f\n", i);
    return EXIT_SUCCESS;
}

//atol()����һ���ַ���ת��Ϊlong����
int main_atol() {
    char ch[] = "    -123.456-456abc123";
    long i = atol(ch);
    printf("%ld\n", i);
    return EXIT_SUCCESS;
}