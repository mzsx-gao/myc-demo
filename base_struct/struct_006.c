#include<stdio.h>
#include<stdlib.h>

/*
 * 联合体:
 * 联合union是一个能在同一个存储空间存储不同类型数据的类型；
 * 联合体所占的内存长度等于其最长成员的长度倍数，也有叫做共用体；
 * 同一内存段可以用来存放几种不同类型的成员，但每一瞬时只有一种起作用；
 * 共用体变量中起作用的成员是最后一次存放的成员，在存入一个新的成员后原有的成员的值会被覆盖；
 * 共用体变量的地址和它的各成员的地址都是同一地址
 */
union Var {
    int a;
    float b;
    double c;
    char d;
    short f[6];//12
};

int main_uni() {
    union Var var;
    var.a = 100;
    var.b = 3.14;
    printf("%d\n", var.a);
    printf("%f\n", var.b);
    printf("大小：%d\n", sizeof(var));
    printf("%p\n", &var);
    printf("%p\n", &var.a);
    printf("%p\n", &var.b);
    printf("%p\n", &var.c);
    return EXIT_SUCCESS;
}

/*
 * typedef:
 * 1、为已存在的数据类型起别名
 * 2、定义函数指针
 */
typedef unsigned int ui;
typedef unsigned long long ull;

//typedef struct stu ss;
typedef struct stu {
    char name[21];
    int age;
    int score;
    char addr[51];
} ss;

int main_typedef() {
    ui a = 10;
    ull b = 20;
    ss stu;
    stu.name;
    printf("%d\n", a);
    printf("%d\n", b);
    return EXIT_SUCCESS;
}