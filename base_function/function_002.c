#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>


//��������
int add01(int a, int b);

//��������
//��������
int main_f006() {
    //��������
    int a = add01(10, 20);
    printf("%d\n", a);
    return EXIT_SUCCESS;
}

//��������  ֻ�ܶ���һ��
int add01(int a, int b) {
    return a + b;
}


void fun03() {
    printf("hello world1\n");
    printf("hello world1\n");
    printf("hello world1\n");
    //��ֹ����ִ��
    exit(0);
    return;
    printf("hello world1\n");
    printf("hello world1\n");
    return;
}

int main_f007() {
    fun03();
    printf("hello world1\n");
    printf("hello world1\n");
    printf("hello world1\n");
    exit(0);
    return -1;
    printf("hello world1\n");
    printf("hello world1\n");
    return EXIT_SUCCESS;
}