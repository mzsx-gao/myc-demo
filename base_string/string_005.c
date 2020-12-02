#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

/*
 * 字符串分割:
 * strtok 会破坏源字符串,用\0替换分割的标志位
 * 在第一次调用时：strtok()必需给予参数s字符串;
 * 往后的调用则将参数s设置成NULL，每次调用成功则返回指向被分割出片段的指针
 */
int main_strtok1() {
    char ch[] = "www.csci.com";//www\0csci\0com

    char *p = strtok(ch, ".");
    printf("%s\n", p);

    p = strtok(NULL, ".");
    printf("%s\n", p);

    p = strtok(NULL, ".");
    printf("%s\n", p);
    return EXIT_SUCCESS;
}

int main_strtok2(void) {
    char ch[] = "123456@qq.com";
    char str[100] = {0};

    //字符串备份
    strcpy(str, ch);

    char *p = strtok(str, "@");
    printf("%s\n", p);
    p = strtok(NULL, ".");
    printf("%s\n", p);
    return 0;

}

int main_strtok3(void) {
    char ch[] = "你瞅啥\n瞅你咋啦\n再瞅一个试试\n对不起大哥我错喽\n瓜娃子";

    char *p = strtok(ch, "\n");

    while (p) {
        printf("%s\n", p);
        p = strtok(NULL, "\n");
    }
    return 0;
}


/*
 * 字符串类型转换atoi:
 * 扫描nptr字符串，跳过前面的空格字符，直到遇到数字或正负号才开始做转换，而遇到非数字或字符串结束符('\0')才结束转换，
 * 并将结果返回返回值
 */
int main_atoi() {
    char ch[] = "    -123-456abc123";
    int i = atoi(ch);
    printf("%d\n", i);
    return EXIT_SUCCESS;
}

//atof():把一个小数形式的字符串转化为一个浮点数
int main_atof() {
    char ch[] = "    -123.456-456abc123";
    double i = atof(ch);
    printf("%.2f\n", i);
    return EXIT_SUCCESS;
}

//atol()：将一个字符串转化为long类型
int main_atol() {
    char ch[] = "    -123.456-456abc123";
    long i = atol(ch);
    printf("%ld\n", i);
    return EXIT_SUCCESS;
}