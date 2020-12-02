#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>


//函数声明
int add01(int a, int b);

//函数定义
//函数调用
int main_f006() {
    //函数调用
    int a = add01(10, 20);
    printf("%d\n", a);
    return EXIT_SUCCESS;
}

//函数定义  只能定义一次
int add01(int a, int b) {
    return a + b;
}


void fun03() {
    printf("hello world1\n");
    printf("hello world1\n");
    printf("hello world1\n");
    //终止程序执行
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