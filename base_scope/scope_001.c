#include<stdio.h>
#include<stdlib.h>

/*
 * 静态局部变量:
 * 静态局部变量只会初始化一次  可以多次赋值
 * 在数据区进程存储
 * 作用域：只能在函数内部使用
 * 生命周期：从程序创建到程序销毁
 */
void fun04() {
    static int b = 10;
    b++;
    printf("%d\n", b);
}

int main_sc001() {
    //静态局部变量
    static int b = 10;
    for (int i = 0; i < 10; i++) {
        fun04();
    }
    printf("%d\n", b);
    return EXIT_SUCCESS;
}


/**
 * 静态全局变量:
 * 作用域：可以在本文件中使用 不可以在其他文件中使用
 * 生命周期：从程序创建到程序销毁
 */
static int c = 10;

void fun05() {
    c = 20;
    printf("%d\n", c);
}

int main_sc002() {
    printf("%d\n", c);
    fun05();
    return EXIT_SUCCESS;
}


/**
 * 未初始化变量的默认值
 */
int abc;//未初始化的全局变量
static int abc2;//未初始化的静态全局变量
int main_sc003() {

    int abc3;  //局部变量未初始化值为乱码
    static int abc4;//未初始化的静态局部变量

    printf("%d\n", abc);
    printf("%d\n", abc2);
    printf("%d\n", abc3);
    printf("%d\n", abc4);
    return EXIT_SUCCESS;
}


//函数可以调用自己  成为递归函数
void BubbleSort(int *, int);

/*
 * 全局函数
 */
int main_sc004() {
    int arr[] = {9, 1, 5, 6, 8, 2, 7, 10, 4, 3};
    //全局函数的名称是作用域中唯一的
    //作用域：在整个项目中所有文件中使用
    //声明周期：从程序创建到程序销毁
    BubbleSort(arr, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }
    return EXIT_SUCCESS;
}

/*
 * 静态函数:
 * 静态函数可以和全局函数重名
 * 作用域：当前文件中
 * 声明周期：从程序创建到程序销毁
 */
static void fun07() {
    printf("hello world1\n");
}

int main_sc005(void) {
    fun07();
}