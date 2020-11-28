#include<stdio.h>
#include<stdlib.h>


//指针作为函数参数
void swap2(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main0401() {
    int a = 10;
    int b = 20;
    //地址传递  形参可以改变实参的值
    swap2(&a, &b);
    printf("%d\n", a);
    printf("%d\n", b);
    return EXIT_SUCCESS;
}

void my_strcat01(char *ch1, char *ch2) {
    int i = 0;
    while (ch1[i] != '\0') {
        i++;
    }

    int j = 0;
    while (ch2[j] != '\0') {
        ch1[i + j] = ch2[j];
        j++;
    }
}

void my_strcat02(char *ch1, char *ch2) {
    int i = 0;
    while (*(ch1 + i) != '\0') {
        i++;
    }
    int j = 0;
    while (*(ch2 + j) != '\0') {
        *(ch1 + i + j) = *(ch2 + j);
        j++;
    }
}

void my_strcat03(char *ch1, char *ch2) {
    while (*ch1)ch1++;
    while (*ch2) {
        *ch1 = *ch2;
        ch1++;
        ch2++;
    }
}

void my_strcat(char *ch1, char *ch2) {
    while (*ch1)ch1++;
    while (*ch1++ = *ch2++);
}

//字符串拼接
int main0601() {
    char ch1[100] = "hello";
    char ch2[] = "world";
    my_strcat(ch1, ch2);
    printf("%s\n", ch1);

    return EXIT_SUCCESS;
}


void remove_space01(char *ch) {
    char str[100] = {0};
    char *temp = str;
    int i = 0;
    int j = 0;
    while (ch[i] != '\0') {
        if (ch[i] != ' ') {
            str[j] = ch[i];
            j++;
        }
        i++;
    }
    while (*ch++ = *temp++);
}

void remove_space(char *ch) {
    //用来遍历字符串
    char *ftemp = ch;
    //记录非空格字符串
    char *rtemp = ch;
    while (*ftemp) {
        if (*ftemp != ' ') {
            *rtemp = *ftemp;
            rtemp++;
        }
        ftemp++;
    }
    *rtemp = 0;
}

//删除字符串空格
int main0602(void) {
    char ch[] = "   h   e    ll  o  w o   r lld    ";

    remove_space(ch);
    printf("%s\n", ch);
    return 0;
}
