#include "stdio.h"
#include<stdlib.h>

/**
 * 指针基础
 */

//万能指针
int main001() {
    int a = 10;
    //万能指针可以接收任意类型变量的内存地址
    void *p = &a;

    //在通过万能指针修改变量的值时，需要找到变量对应的指针类型
    *(int *) p = 100;
    printf("修改a的值以后:%d\n", a);
    printf("%d\n", *(int *) p);

    printf("万能指针在内存中占的字节大小:%d\n", sizeof(void *));
    return EXIT_SUCCESS;
}

/**
 * const修饰的指针类型
 */
//指针间接修改常量的值
int main002() {
    //常量
    const int a = 10;
    //a = 100;//err
    int *p = &a;
    *p = 100;
    printf("指针可以间接修改常量的值%d\n", a);

    //system("pause");
    return EXIT_SUCCESS;
}

//const修饰指针类型，指针指向内存区域不能修改，指针指向可以变
int main003() {
    int a = 10;
    int b = 20;
    const int *p = &a;
    printf("%d\n", *p);
    //*p1 = 111; //err
    p = &b; //ok
    printf("%d\n", *p);
}

//const修饰指针变量,可以修改指针指向内存空间的值，不可以修改指针变量的值
int main004() {
    int a = 10;
    int b = 20;
    int *const p = &a;
    //p = &b;//err
    *p = 200;
    printf("%d\n", a);
    return EXIT_SUCCESS;
}

//const修饰指针类型 修饰指针变量  只读指针
int main005(void) {
    int a = 10;
    int b = 20;

    const int *const p = &a;

    //p = &b;//err
    //*p = 100;//err

    printf("修改前:%d\n",*p);
    //二级指针操作
    int **pp = &p;

    *pp = &b;//*pp是一级指针的值
    printf("修改一级指针的值后:%d\n",*p);

    **pp = 100;//**pp是变量的值
    printf("修改变量的值后%d\n", *p);

    return 0;
}