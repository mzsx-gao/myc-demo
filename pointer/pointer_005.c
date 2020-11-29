#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/**
 * 指针作为函数返回值
 */
char *my_strchr01(char *str, char ch) {
    int i = 0;
    while (str[i]) {
        if (str[i] == ch) {
            return &str[i];
        }
        i++;
    }
    return NULL;
}

char *my_strchr(char *str, char ch) {
    while (*str) {
        if (*str == ch)
            return str;
        str++;
    }
    return NULL;
}

int main0501() {
    char str[] = "hell worldll";
    char *p = my_strchr01(str, 'o');
    if (p == NULL) {
        printf("未找到\n");
    } else {
        printf("%s\n", p);
    }
    return EXIT_SUCCESS;
}


/**
 * 字符串中查找字符串
 */
char *my_strstr(char *src, char *dest) {
    char *fsrc = src;//用作于循环遍历的指针（从这个字符串中寻找）
    char *tdest = dest;//被查找的字符串
    char *record = src;//记录每次相同的首地址
    while (*fsrc) {
        record = fsrc;
        while (*fsrc == *tdest && *fsrc != '\0') {
            fsrc++;
            tdest++;
        }
        if (*tdest == '\0') {
            return record;
        }
        //回滚
        fsrc = record;//查找字符串修改为record指针本次记录的位置
        tdest = dest;//目标字符串修改到起始位置
        fsrc++;//查找字符串往下走一个
    }
    return NULL;
}

int main0502() {
    char src[] = "llllhelle worldllo";
    char dest[] = "lle";

    char *p = my_strstr(src, dest);
    printf("%s\n", p);
    return EXIT_SUCCESS;
}