#include<stdio.h>
#include<stdlib.h>

int main_arr01() {
    //变量定义
    //数据类型 变量  = 值
    //数组定义
    //数据类型 数组名[元素个数]={值1，值2，值3}
    int arr[10] = {9, 4, 2, 1, 8, 5, 3, 6, 10, 7};

    //数组下标  数组名[下标]
    //数组下标是从0开始的到数组元素个数-1
    //printf("%d\n", arr[0]);

    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }

    return EXIT_SUCCESS;
}

int main_arr02(void) {
    //数组在内存中存储方式和大小
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //下标为0的元素地址
    //printf("%p\n", &arr[0]);
    //printf("%p\n", &arr[1]);
    //printf("%p\n", &arr[2]);
    //printf("%p\n", &arr[3]);
    //printf("%p\n", &arr[4]);
    //数组名是一个地址常量  指向数组首地址的常量

    //printf("%p\n", arr);


    printf("数组在内存中占的大小：%d\n", sizeof(arr));
    printf("数组元素大小：%d\n", sizeof(arr[0]));
    printf("数组元素个数：%d\n", sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}

#define SIZE 10

int main_arr03(void) {
    //int i = 10;
    //数组元素必须是常量 常量表达式
    //数组必须预先知道大小 动态数组-》开辟堆空间
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < SIZE; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}

int main_arr04(void) {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //printf("%d\n", arr[-1]);//err
    printf("%d\n", arr[10]);//err
    for (int i = 0; i < 20; i++) {
        //数组下标越界  0-9
        printf("%d\n", arr[i]);//err
    }
    return 0;
}

//数组倒叙排列
int main_arr05() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i = 0;
    int j = sizeof(arr) / sizeof(arr[0]) - 1;

    while (i < j) {
        //通过临时变量交换数据
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        i++;
        j--;
    }
    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }
    return EXIT_SUCCESS;
}

//冒泡排序
int main_arr06() {
    int arr[] = {9, 1, 5, 7, 2, 10, 8, 4, 6, 3};
    //外层控制行
    //外层执行元素个数-1次
    for (int i = 0; i < 9; i++) {
        //内层控制列
        //内层执行元素个数-1-执行次数
        for (int j = 0; j < 9 - i; j++) {
            //比较两个元素 满足条件交换
            //通过符号控制排序的方式
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }

    return EXIT_SUCCESS;
}