#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*
 * main函数是操作系统调用的，第一个参数标明argc数组的成员数量，argv数组的每个成员都是char *类型
 * argv是命令行参数的字符串数组
 * argc代表命令行参数的数量，程序名字本身算一个参数
 *
 * 这个例子，运行时可传递4个参数看看效果，比如:  ./myc_demo a b c d
 */
int main_str001(int argc, char *argv[]) {
    //gcc
    if (argc < 3) {
        printf("缺少参数\n");
        return -1;
    }
    printf("%s", "参数内容:\n");
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    return 0;
}


/*
 * 利用strstr标准库函数找出一个字符串中substr出现的个数
 */
char *my_str2(char *src, char *dest) {
    char *fsrc = src;//用作于循环遍历的指针
    char *tdest = dest;
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
        fsrc = record;
        tdest = dest;
        fsrc++;
    }
    return NULL;
}

int main_str002() {
    char *str = "11abcd111122abcd333abcd3322abcd3333322qqq";
    char ch[] = "abcd";
    char *p = my_str2(str, ch);
    int count = 0;//记录个数
    while (p) {
        count++;
        p += strlen(ch);
        p = my_str2(p, ch);
    }

    printf("abcd在字符串中出现:%d次\n", count);
    return EXIT_SUCCESS;
}

//do while循环方式
int main_str003(void) {
    char *str = "11abcd111122abcd333abcd3322abcd3333322qqq";
    char ch[] = "abcd";
    char *p = my_str2(str, ch);
    int count = 0;//记录个数
    do {
        if (p) {
            count++;
            p += strlen(ch);
            p = my_str2(p, ch);
        }
    } while (p);
    printf("%d\n", count);
    return 0;
}


/*
 * 非空格字符串个数
 */
int getstrcount01(char *ch) {
    int i = 0;
    int count = 0;
    while (ch[i]) {
        if (ch[i] != ' ') {
            count++;
        }
        i++;
    }
    return count;
}

int getstrcount(char *ch) {
    int count = 0;
    while (*ch) {
        if (*ch != ' ')count++;
        ch++;
    }
    return count;
}

int main_str004() {
    char ch[] = "    hello world   ";
    int len = getstrcount(ch);
    printf("%d\n", len);
    return EXIT_SUCCESS;
}

//统计字符串出现次数
int main_str005(void) {
    char ch[] = "helloworldnichoushachounizadizaichouyigeshishi";//97 97+26
    //存储字符串出现次数
    int arr[26] = {0};
    for (int i = 0; i < strlen(ch); i++) {
        arr[ch[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (arr[i])
            printf("字母：%c出现次数：%d\n", i + 'a', arr[i]);
    }
    return 0;
}