#include "stdio.h"

/**
 * 指针与数组
 */
int main002_01() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //数组名是一个常量 不允许赋值
    //数组名是数组首元素地址
    //arr = 100;//err

    int *p = arr;
    printf("指针变量p的值:%p\n", p);
    printf("数组名就是首元素的地址:%p\n", arr);

    *p = 123;//改变数组首元素的值

    //指针加一等同于内存地址加了一个sizeof(指针类型)的大小
//    p++;
//    printf("数据原地址:%p\n", arr);
//    printf("指针加一后:%p\n", p);


    //以下几种取值方式效果一样
    printf("=======打印数组========\n");
    for (int i = 0; i < 10; i++) {
//        printf("%d\n", arr[i]);//arr[0]
//        printf("%d\n", *(arr + i));//arr是地址，地址+偏移量还是地址
//        printf("%d\n", p[i]);
//        printf("%d\n", *(p + i));
        printf("%d\n", *p++);
    }

    //p连续++以后p与arr已经不再相等了
    printf("p == arr结果:%d\n", p == arr);


    //两个指针相减得到的结果是两个指针的偏移量(步长）
    //所有的指针类型相减结果都是int类型
    int step = p - arr;

    printf("指针相减(p-arr)的结果是:%d\n", step);

    return 0;
}

int main002_02() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //指向数组的指针
    int *p = arr;
    //p是变量  arr是常量
    //p是一个指针 4个字节大小
    //arr是一个数组 40字节大小
    printf("指针类型大小：%d\n", sizeof(p));
    printf("数组大小：%d\n", sizeof(arr));

    //p[i];
    //*(p+i);
    return 0;
}

//数组作为函数参数会退化为指针 丢失数组的精度(不知道数组的长度，需要调用方作为参数传递过来)
void BubbleSort2(int *arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (*(arr + j) > *(arr + j + 1)) {//*(p + j)写法等同于arr[j]
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int main0103(void) {
    int arr[] = {9, 1, 5, 6, 3, 8, 10, 2, 7, 4};

    BubbleSort2(arr, 10);

    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}