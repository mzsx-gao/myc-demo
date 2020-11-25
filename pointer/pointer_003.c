#include<stdio.h>
#include<stdlib.h>

/**
 * 指针运算
 */
//第一种方式
void my_strcpy01(char *dest, char *ch) {
    int i = 0;
    //while (ch[i] != '\0');
    //while (ch[i] != 0);
    while (ch[i]) {
        dest[i] = ch[i];
        i++;
    }
    dest[i] = 0;
}

//第二种方式：“ *(ch + i) ”等同于“ ch[i] ”
void my_strcpy02(char *dest, char *ch) {
    int i = 0;
    while (*(ch + i)) {
        *(dest + i) = *(ch + i);
        i++;
    }
    *(dest + i) = 0;
}

//第三种方式
void my_strcpy03(char *dest, char *ch) {
    while (*ch) {
        *dest = *ch;//*ch就是数组的首元素
        dest++;//指针+1  相当于指向数组下一个元素  内存地址变化了sizeof(char)
        ch++;
    }
    *dest = 0;
}

//第四种方式
void my_strcpy(char *dest, char *ch) {
    while (*dest++ = *ch++);
}

//字符串拷贝
int main0201() {
    char ch[] = "hello world";
    char dest[100];

    my_strcpy(dest, ch);
    printf("%s\n", dest);
    printf("%p", dest);
    return EXIT_SUCCESS;
}

//指针减法运算
int main0202(void) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = &arr[3];
    printf("指针p地址:%p\n", p);
    //p--;//指针的加减运算和指针的类型有关
    //p--;
    //p--;
    //内存地址相差是12,然后除以sizeof(int) = 偏移量
    int step = p - arr;
    printf("%p\n", p);
    printf("%p\n", arr);
    printf("p与arr两者相差%d个元素\n", step);

    //指针操作数组时下标允许是负数
    printf("p[-2]的值:%d\n", p[-2]);//*(p-2);
    return 0;
}

int main(void) {
    //指针和运算符的操作
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = arr;
    p = &arr[3];
    //野指针
    //p = p + arr;//err
    //p = p*arr;//err
    //p = p*4;//err
    //p = p / arr;
    //int len = p % 4;//err

    if (p > arr) {
        printf("真\n");
    }
    if (p || arr) {

    }
    return 0;
}