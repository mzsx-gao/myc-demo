#include<stdio.h>
#include<stdlib.h>

/*
 * 字符指针
 */
int main_str0101() {
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

int main_str0102(void) {
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


/*
 * 字符指针做函数参数
 */
int my_strlen01(char *ch) {
    //计算字符串有效长度
    int i = 0;
    while (ch[i])i++;
    return i;
}

int my_strlen(const char *ch) {
    if (ch == NULL)
        return 0;

    char *temp = ch;
    while (*temp)temp++;
    return temp - ch;
}

int main_str0103() {
    char ch[] = "hello world";
    printf("%s\n", ch);
//    int len = my_strlen01(ch);
    int len = my_strlen(ch);
    printf("%d\n", len);
    return EXIT_SUCCESS;
}


/*
 * const修饰的指针
 */
//通过一级指针间接修改变量的值
int main_str0104() {
    const int a = 10;
    //a = 100;//err

    int *p = &a;
    *p = 100;
    return EXIT_SUCCESS;
}

//指向常量的指针
//可以修改指针变量的值  不可以修改指针变量指向内存空间的值
int main_str0105(void) {
    char ch1[] = "hello";
    char ch2[] = "world";
    const char *p = ch1;
    //*p = 'm';//err
    //p[2] = 'm';//*(p+2)='m';//err
    p = ch2;//ok

    return 0;
}

//常量指针
//可以修改指针变量指向内存空间的值，不可以修改指针变量的值
int main_str0106(void) {
    char ch1[] = "hello";
    char ch2[] = "world";

    char *const p = ch1;

    //p = ch2;//err
    //p[2] = 'm';//ok
    *(p + 2) = 'm';//ok
    printf("%s\n", p);
    printf("%s\n", ch1);
    return 0;
}

//const修饰指针类型 修饰指针变量  只读指针。可通过二级指针修改
int main_str0107(void) {
    char ch1[] = "hello";
    char ch2[] = "world";

    const char *const p = ch1;

    //p = ch2;//err
    //*p = 'm';//err
    //p[2]='m'//err

    char **p1 = &p;

    //*p1 = ch2;//ok
    *(*p1 + 1) = 'm';//ok
    printf("%s\n", p);
    return 0;
}