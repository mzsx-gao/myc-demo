#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*
 * main�����ǲ���ϵͳ���õģ���һ����������argc����ĳ�Ա������argv�����ÿ����Ա����char *����
 * argv�������в������ַ�������
 * argc���������в������������������ֱ�����һ������
 *
 * ������ӣ�����ʱ�ɴ���4����������Ч��������:  ./myc_demo a b c d
 */
int main_str001(int argc, char *argv[]) {
    //gcc
    if (argc < 3) {
        printf("ȱ�ٲ���\n");
        return -1;
    }
    printf("%s", "��������:\n");
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    return 0;
}


/*
 * ����strstr��׼�⺯���ҳ�һ���ַ�����substr���ֵĸ���
 */
char *my_str2(char *src, char *dest) {
    char *fsrc = src;//������ѭ��������ָ��
    char *tdest = dest;
    char *record = src;//��¼ÿ����ͬ���׵�ַ

    while (*fsrc) {
        record = fsrc;
        while (*fsrc == *tdest && *fsrc != '\0') {
            fsrc++;
            tdest++;
        }
        if (*tdest == '\0') {
            return record;
        }
        //�ع�
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
    int count = 0;//��¼����
    while (p) {
        count++;
        p += strlen(ch);
        p = my_str2(p, ch);
    }

    printf("abcd���ַ����г���:%d��\n", count);
    return EXIT_SUCCESS;
}

//do whileѭ����ʽ
int main_str003(void) {
    char *str = "11abcd111122abcd333abcd3322abcd3333322qqq";
    char ch[] = "abcd";
    char *p = my_str2(str, ch);
    int count = 0;//��¼����
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
 * �ǿո��ַ�������
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

//ͳ���ַ������ִ���
int main_str005(void) {
    char ch[] = "helloworldnichoushachounizadizaichouyigeshishi";//97 97+26
    //�洢�ַ������ִ���
    int arr[26] = {0};
    for (int i = 0; i < strlen(ch); i++) {
        arr[ch[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (arr[i])
            printf("��ĸ��%c���ִ�����%d\n", i + 'a', arr[i]);
    }
    return 0;
}