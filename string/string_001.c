#include<stdio.h>
#include<stdlib.h>

int main0101() {
    char ch[] = "hello world";//栈区字符串
    char *p = "hello world";//数据区常量区字符串,不允许修改

    ch[2] = 'm';
    //p[2] = 'm';//err
    //*(p + 2) = 'm';//err
    printf("%c\n", p[2]);
    printf("%s\n", ch);
    printf("%s\n", p);
    return EXIT_SUCCESS;
}

int main0102(void) {
    //字符串数组
    //指针数组
    //char ch1[] = "hello";
    //char ch2[] = "world";
    //char ch3[] = "dabaobei";
    //char* arr[] = { ch1, ch2, ch3 };
    //字符串数组  指针数组
    char *arr[] = {"hello", "world", "dabaobei"};

    //字符串排序
    for (int i = 0; i < 3 - 1; i++) {
        for (int j = 0; j < 3 - 1 - i; j++) {
            //找首字符进行比较
            if (arr[j][0] > arr[j + 1][0]) {
                //交换指针数组元素进行排序

                char *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}