#include "stdio.h"
#include<stdlib.h>

/**
 * 指针基础
 * 1.指针定义和使用
 * 2.野指针
 * 3.空指针
 * 4.万能指针
 * 5.const修饰的指针类型
 */

//指针定义和使用
int main001_01(void) {

    //示例1:
    //定义指针变量存储变量地址
    int a = 10;
    //指针类型  -> 数据类型*
    int *p = &a;
    //通过指针间接改变变量的值
    *p = 100;
    printf("%p\n", &a);
    printf("%p\n", p);

    printf("%d\n", a);
    printf("%d\n", *p);

    //示例2:
    //指针在内存中占的字节大小:32位系统占4个字节，64位系统占8个字节
//    printf("%d\n", sizeof(char *));
//    printf("%d\n", sizeof(int *));
//    printf("%d\n", sizeof(short *));
//    printf("%d\n", sizeof(long *));
//    printf("%d\n", sizeof(long long *));
//    printf("%d\n", sizeof(float *));
//    printf("%d\n", sizeof(double *));

    //示例3:
//    char ch = 97;
//    int *p = &ch;
//    *p = 96;
//    printf("%d\n", ch);
//    printf("%d\n", *p);
//    printf("%p\n", p);
//    printf("%p\n", &ch);

    return 0;
}

/**
 * 野指针:
 * 任意数值赋值给指针变量没有意义，因为这样的指针就成了野指针，此指针指向的区域是未知(操作系统不允许操作此指针指向的内存区域)。
 * 所以，野指针不会直接引发错误，操作野指针指向的内存区域才会出问题
 */
int main001_02() {
    //不建议将一个变量的值直接赋值给指针
    //野指针 -》指针变量指向一个未知的空间
    int *p = 100;
    //程序中允许存在野指针
    //操作系统将0-255作为系统占用不允许访问操作
    //操作野指针对应的内存空间可能报错

    printf("%d\n", *p);
    return EXIT_SUCCESS;
}

//空指针
int main001_03(void) {
    //空指针是指内存地址编号为0的空间
    int *p = NULL;
    //操作空指针对应的空间一定会报错
    *p = 100;//err
    printf("%d\n", *p);
    //空指针可以用在条件判断

    return 0;
}


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

    printf("修改前:%d\n", *p);
    //二级指针操作
    int **pp = &p;

    *pp = &b;//*pp是一级指针的值
    printf("修改一级指针的值后:%d\n", *p);

    **pp = 100;//**pp是变量的值
    printf("修改变量的值后%d\n", *p);

    return 0;
}