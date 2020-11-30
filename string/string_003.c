#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
 * �ַ�������
 */
void inverse01(char *ch) {
    int i = 0;
    int j = strlen(ch) - 1;
    while (i < j) {
        char temp = ch[i];
        ch[i] = ch[j];
        ch[j] = temp;

        i++;
        j--;
    }
    return;
}

void inverse(char *ch) {
    char *ftemp = ch;
    char *btemp = ch + strlen(ch) - 1;
    //printf("%c\n", *btemp);
    while (ftemp < btemp) {
        char temp = *ftemp;
        *ftemp = *btemp;
        *btemp = temp;
        ftemp++;
        btemp--;
    }
    return;
}

int main_str00301() {
    char ch[] = "hello world";
    inverse(ch);
    printf("%s\n", ch);
    return EXIT_SUCCESS;
}

//�����ַ���
//abcba abccba  abcbdcba
int symm(char *ch) {
    char *ftemp = ch;
    char *btemp = ch + strlen(ch) - 1;

    while (ftemp < btemp) {
        if (*ftemp != *btemp)
            return 1;
        ftemp++;
        btemp--;
    }
    return 0;
}

int main_str00302(void) {
//    char ch[] = "abcba";
    char ch[] = "abcbdcba";
    int value = symm(ch);
    if (!value) {
        printf("��ͬ\n");
    } else {
        printf("����ͬ\n");
    }
    return 0;
}

/*
 * �ַ�������,����ʵ��
 */
void strcpyall(char *dest, const char *src) {
    while (*dest++ = *src++);
}

void partstrncpy01(char *dest, const char *src, size_t n) {
    while ((*dest++ = *src++) && --n);
}

void partstrncpy02(char *dest, const char *src, size_t n) {
    int i = 0;
    for (int i = 0; i < n && src[i]; i++) {
        dest[i] = src[i];
    }
}

void partstrncpy03(char *dest, const char *src, size_t n) {
    int i = 0;
    while (i < n && src[i]) {
        *(dest + i) = *(src + i);
        i++;
    }
}

void partstrncpy04(char *dest, const char *src, size_t n) {
    while (n-- && *src) {
        *dest = *src;
        dest++;
        src++;
    }
}

int main_main_str00303() {
    char ch[] = "hello world";
    char str[100] = {0};

//    strcpyall(str, ch);//�Զ��巽��
//    strcpy(str,ch);//ϵͳʵ�ֵķ���
//    printf("�ַ����������:%s\n",str);

    //�ַ������޿���
//    partstrncpy04(str, ch, 5);//�Զ��巽��
    strncpy(str, ch, 5);//ϵͳ�ṩ�ķ���
    printf("�ַ������޿���:%s\n", str);

    return EXIT_SUCCESS;
}