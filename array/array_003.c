#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


/**
 * �ַ��������ַ���
 */
int main1001() {
    //�����ַ�����
    char arr[100] = {110, 111, 112, 101, 123, 98, 99};

    //char arr[] = { "hello"};
    printf("%s\n", arr);
    //char arr[6] = {'h','e','l','l','o'};
    //�ַ�
    //char ch = 'a';
    //�ַ��� �ַ���������־Ϊ\0  ����0��ͬ��\0  ���ǲ���ͬ��'0'
    //char * arr = "hello";
    //char arr[] = "hello";
    //char arr[] = { 'h','e','l','l','o','\0' };

    printf("%s", arr);
    //printf("%d\n", sizeof(arr));//sizeof(��������)

    //for (int i = 0; i < sizeof(arr); i++)
    //{
    //	printf("%c", arr[i]);
    //}
    return EXIT_SUCCESS;
}

int main1002() {
    //�����ַ�����洢�ַ���
    char ch[11];
    scanf("%10s", ch);
    printf("%s", ch);
    return 0;
}

int main1003(void) {
    //�ַ���ƴ��
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
    //ͨ�����̻�ȡһ���ַ���
    //gets�����ַ������Դ��ո�
    gets(ch);
    //ͨ��������ʽ  ��ȡ���ո��ַ���
    //scanf("%[^\n]", ch);
    printf("%s\n", ch);
    return EXIT_SUCCESS;
}

int main1102(void) {
    char ch[10];
    //"hello\n\0"
    //fgets���Խ��տո�
    //fgets��ȡ�ַ�������Ԫ�ظ�������\n  ���ڵ��� û��\n
    fgets(ch, sizeof(ch), stdin);

    printf("%s", ch);
    return 0;
}

int main1103(void) {
    char ch[] = "hello world";
    //puts�Դ�����
    //puts(ch);
    //puts("hello\0 world");
    //puts("");����
    return 0;
}

int main1104(void) {
    char ch[] = "hello world";
    fputs(ch, stdout);
    //printf("%s", ch);
    return 0;
}

int main1201() {
    //�����ַ�����Ч����
    char ch[] = "hello world";
    printf("�����С��%d", sizeof(ch));
    printf("�ַ������ȣ�%d", strlen(ch));
    return EXIT_SUCCESS;
}

int main1202(void) {
    char ch[] = "hello world";
    int len = 0;
    while (ch[len] != '\0') {
        len++;
    }
    printf("�ַ������ȣ�%d", len);
    return 0;
}