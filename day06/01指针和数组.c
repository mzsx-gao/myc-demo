#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int arr[] = {123456,2,3,4,5,6,7,8,9,10};
    //数组名是一个常量 不允许赋值
    //数组名是数组首元素地址
    //arr = 100;//err
    int* p;
    p = arr;
    //printf("%p\n", p);
    //printf("%p\n", arr);
    *p = 123;

    //p++;
    //printf("%p\n", arr);
    //printf("%p\n", p);
    //printf("%d\n", *p);
    for (int i = 0; i < 10; i++)
    {
        //*==[]??
        //printf("%d\n", *(arr+i));//arr[0]
        //printf("%d\n", p[i]);
        //printf("%d\n", *(p + i));
        printf("%d\n", *p++);
    }
    //printf("%p\n", arr);
    //printf("%p\n", p);


    //两个指针相减  等到的结果是两个指针的偏移量  （步长）
    //所有的指针类型 相减结果都是int类型
    int step = p - arr;//3c 40  +1  相当于  sizeof(int)   40/sizeof(int)

    printf("%d\n", step);

    return EXIT_SUCCESS;
}