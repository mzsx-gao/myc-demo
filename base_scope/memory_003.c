#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
 * 内存操作函数
 */

/*
 * void *memset(void *s, int c, size_t n);
    功能：将s的内存区域的前n个字节以参数c填入
    参数：
        s：需要操作内存s的首地址
        c：填充的字符，c虽然参数为int，但必须是unsigned char , 范围为0~255
        n：指定需要设置的大小
    返回值：s的首地址
 */
int main_1101() {
    int *p = (int *) malloc(sizeof(int) * 10);

    memset(p, 0, sizeof(int) * 10);
    for (int i = 0; i < 10; i++) {
        printf("%d\n", p[i]);
    }

    free(p);
    char ch[10];
    memset(ch, 'A', sizeof(char) * 10);
//    memset(ch, 0, sizeof(char)*10);

    printf("%s\n", ch);
    return EXIT_SUCCESS;
}

/*
 * void *memcpy(void *dest, const void *src, size_t n);
    功能：拷贝src所指的内存内容的前n个字节到dest所值的内存地址上。
    参数：
        dest：目的内存首地址
        src：源内存首地址，注意：dest和src所指的内存空间不可重叠，可能会导致程序报错
        n：需要拷贝的字节数
    返回值：dest的首地址
 */
int main_1102(void) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = (int *) malloc(sizeof(int) * 10);

    memcpy(p, arr, sizeof(int) * 10);

    for (int i = 0; i < 10; i++) {
        printf("%d\n", p[i]);
    }
    free(p);

    printf("======字符串拷贝========\n");
    char ch[] = "hello\0 world";
    char str[100];
    //字符串拷贝(strcpy(str, ch))遇到\0停止
    //内存拷贝  拷贝的内容和字节有关
    memcpy(str, ch, 12);
    printf("%s\n", str);
    for (int i = 0; i < 12; i++) {
        printf("%c", str[i]);
    }
    printf("\n");

    //如果拷贝的目标和源发生重叠 可能报错
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    memcpy(&arr2[5], &arr2[3], 20);
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr2[i]);
    }
    return 0;
}

/*
 * memmove()功能用法和memcpy()一样，
 * 区别在于：dest和src所指的内存空间重叠时，memmove()仍然能处理，不过执行效率比memcpy()低些
 */
int main_1103(void) {
    //对比上一个方法最后一个例子(memcpy(&arr2[5], &arr2[3], 20);)
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    memmove(&arr[5], &arr[3], 20);
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
}

/*
 * int memcmp(const void *s1, const void *s2, size_t n);
    功能：比较s1和s2所指向内存区域的前n个字节
    参数：
        s1：内存首地址1
        s2：内存首地址2
        n：需比较的前n个字节
    返回值：
        相等：=0
        大于：>0
        小于：<0
 */
int main_1104(void) {
    //int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
    //int arr2[] = { 1,2,3,4,5 };

    char arr1[] = "hello\0 world";
    char arr2[] = "hello\0 world";
    //strcmp();
    int value = memcmp(arr1, arr2, 13);

    printf("%d\n", value);

    return 0;
}