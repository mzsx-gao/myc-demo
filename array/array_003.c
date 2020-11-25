#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


/**
 * 字符数组与字符串
 */
int main1001() {
    //定义字符数组
    char arr[100] = {110, 111, 112, 101, 123, 98, 99};

    //char arr[] = { "hello"};
    printf("%s\n", arr);
    //char arr[6] = {'h','e','l','l','o'};
    //字符
    //char ch = 'a';
    //字符串 字符串结束标志为\0  数字0等同于\0  但是不等同于'0'
    //char * arr = "hello";
    //char arr[] = "hello";
    //char arr[] = { 'h','e','l','l','o','\0' };

    printf("%s", arr);
    //printf("%d\n", sizeof(arr));//sizeof(数据类型)

    //for (int i = 0; i < sizeof(arr); i++)
    //{
    //	printf("%c", arr[i]);
    //}
    return EXIT_SUCCESS;
}

int main1002() {
    //定义字符数组存储字符串
    char ch[11];
    scanf("%10s", ch);
    printf("%s", ch);
    return 0;
}

int main1003(void) {
    //字符串拼接
    char ch1[] = "hello";
    char ch2[] = "world";
    char ch3[20];

    int i = 0;
    int j = 0;
    while (ch1[i] != '\0') {
        ch3[i] = ch1[i];
        i++;
    }
    while (ch2[j] != '\0') {
        ch3[i + j] = ch2[j];
        j++;
    }
    ch3[i + j] = '\0';
    printf("%s", ch3);
    return 0;
}


int main1101() {
    char ch[100];
    //通过键盘获取一个字符串
    //gets接收字符串可以带空格
    gets(ch);
    //通过正则表达式  获取带空格字符串
    //scanf("%[^\n]", ch);
    printf("%s\n", ch);
    return EXIT_SUCCESS;
}

int main1102(void) {
    char ch[10];
    //"hello\n\0"
    //fgets可以接收空格
    //fgets获取字符串少于元素个数会有\n  大于等于 没有\n
    fgets(ch, sizeof(ch), stdin);

    printf("%s", ch);
    return 0;
}

int main1103(void) {
    char ch[] = "hello world";
    //puts自带换行
    //puts(ch);
    //puts("hello\0 world");
    //puts("");换行
    return 0;
}

int main1104(void) {
    char ch[] = "hello world";
    fputs(ch, stdout);
    //printf("%s", ch);
    return 0;
}

int main1201() {
    //计算字符串有效个数
    char ch[] = "hello world";
    printf("数组大小：%d", sizeof(ch));
    printf("字符串长度：%d", strlen(ch));
    return EXIT_SUCCESS;
}

int main1202(void) {
    char ch[] = "hello world";
    int len = 0;
    while (ch[len] != '\0') {
        len++;
    }
    printf("字符串长度：%d", len);
    return 0;
}