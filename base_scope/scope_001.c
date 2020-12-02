#include<stdio.h>
#include<stdlib.h>

/*
 * 静态局部变量
 */
void fun04() {
    //静态局部变量只会初始化一次  可以多次赋值
    //在数据区进程存储
    //作用域：只能在函数内部使用
    //生命周期：从程序创建到程序销毁
    static int b = 10;
    b++;
    printf("%d\n", b);
}

int main() {
    //静态局部变量
    //static int b = 10;
    for (int i = 0; i < 10; i++) {
        fun04();
    }
    //printf("%d\n", b);
    return EXIT_SUCCESS;
}
