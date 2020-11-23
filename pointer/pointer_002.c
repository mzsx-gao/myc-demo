#include "stdio.h"

/**
 * 指针与数组
 */
int main() {
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
