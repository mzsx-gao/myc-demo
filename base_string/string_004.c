#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/**
 * 字符串追加
 */
//自定义实现
void consumer_strcat(char *dest, const char *src) {
    //找到dest字符串中\0位置
    while (*dest)dest++;
    while (*dest++ = *src++);
}

void consumer_strncat(char *dest, char *src, size_t n) {
    while (*dest)dest++;
    while ((*dest++ = *src++) && --n);
}

int main_cat() {
    char dest[100] = "hello";
    char src[] = "world";

    //字符串追加
//    strcat(dest, src);
    //字符串有限追加
    strncat(dest, src, 3);
    printf("%s\n", dest);

    return EXIT_SUCCESS;
}


/*
 * 字符串比较
 */
int main_strcmp() {
    char ch1[] = "hello world";
    char ch2[] = "hello world";
    int value = strcmp(ch1, ch2);//返回0代表相同
//    int value = strncmp(ch1, ch2, 3);
    printf("%d\n", value);
    if (strcmp(ch1, ch2)) {
        printf("不相同\n");
    } else {
        printf("相同\n");
    }

    return EXIT_SUCCESS;
}


/*
 * 字符串格式化
 */
int main_sprintf() {
    char ch[100];
//    sprintf(ch, "hello world");
//    sprintf(ch, "%d+%d=%d", 1, 2, 3);
    //%02d:默认情况下，数据数据宽度不够2位是用空格填补的，但是因为2d前面有0，表示，数据宽度不足时用0填补
    sprintf(ch, "%02d+%02d=%02d", 1, 2, 3);
//    sprintf(ch, "%x+%o=%d", 0xabc, 110, 17);

    printf("%s\n", ch);

    return EXIT_SUCCESS;
}

//sscanf:从str指定的字符串读取数据，并根据参数format字符串来转换并格式化数据
int main_sscanf(void) {
    char ch1[] = "abc+110=3";
    int a, b, c;
    sscanf(ch1, "%x+%o=%d", &a, &b, &c);
    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);


    printf("=========================\n");
    char ch[] = "helloworld";
    char str1[100];
    char str2[100];
    char str[100];

    sscanf(ch, "%[^\n]", str);
    printf("%s\n", str);

    printf("=========================\n");
    sscanf(ch, "%5s%s", str1, str2);
    printf("%s\n", str1);
    printf("%s\n", str2);

    return 0;
}


/*
 * 字符串查找
 * 1.strchr:字符串中查找字符
 * 2.strstr:字符串中查找字符串
 */
int main_strchr() {
    char ch[] = "hello world";
    char c = 'l';
    //在字符串ch中查找字母c出现的位置
    char* p = strchr(ch, c);
    printf("%s\n", p);

    return EXIT_SUCCESS;
}

int main_strstr(void) {
    char ch[] = "hello world";
    char str[] = "llo";
    //在字符串ch中查找字符串str出现的位置
    char *p = strstr(ch, str);
    printf("%c\n", *p);
    printf("%s\n", p);
    return 0;
}