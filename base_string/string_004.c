#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/**
 * �ַ���׷��
 */
//�Զ���ʵ��
void consumer_strcat(char *dest, const char *src) {
    //�ҵ�dest�ַ�����\0λ��
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

    //�ַ���׷��
//    strcat(dest, src);
    //�ַ�������׷��
    strncat(dest, src, 3);
    printf("%s\n", dest);

    return EXIT_SUCCESS;
}


/*
 * �ַ����Ƚ�
 */
int main_strcmp() {
    char ch1[] = "hello world";
    char ch2[] = "hello world";
    int value = strcmp(ch1, ch2);//����0������ͬ
//    int value = strncmp(ch1, ch2, 3);
    printf("%d\n", value);
    if (strcmp(ch1, ch2)) {
        printf("����ͬ\n");
    } else {
        printf("��ͬ\n");
    }

    return EXIT_SUCCESS;
}


/*
 * �ַ�����ʽ��
 */
int main_sprintf() {
    char ch[100];
//    sprintf(ch, "hello world");
//    sprintf(ch, "%d+%d=%d", 1, 2, 3);
    //%02d:Ĭ������£��������ݿ�Ȳ���2λ���ÿո���ģ�������Ϊ2dǰ����0����ʾ�����ݿ�Ȳ���ʱ��0�
    sprintf(ch, "%02d+%02d=%02d", 1, 2, 3);
//    sprintf(ch, "%x+%o=%d", 0xabc, 110, 17);

    printf("%s\n", ch);

    return EXIT_SUCCESS;
}

//sscanf:��strָ�����ַ�����ȡ���ݣ������ݲ���format�ַ�����ת������ʽ������
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
 * �ַ�������
 * 1.strchr:�ַ����в����ַ�
 * 2.strstr:�ַ����в����ַ���
 */
int main_strchr() {
    char ch[] = "hello world";
    char c = 'l';
    //���ַ���ch�в�����ĸc���ֵ�λ��
    char* p = strchr(ch, c);
    printf("%s\n", p);

    return EXIT_SUCCESS;
}

int main_strstr(void) {
    char ch[] = "hello world";
    char str[] = "llo";
    //���ַ���ch�в����ַ���str���ֵ�λ��
    char *p = strstr(ch, str);
    printf("%c\n", *p);
    printf("%s\n", p);
    return 0;
}