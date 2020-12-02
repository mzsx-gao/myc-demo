#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/**
 * ָ����Ϊ��������ֵ
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
        printf("δ�ҵ�\n");
    } else {
        printf("%s\n", p);
    }
    return EXIT_SUCCESS;
}


/**
 * �ַ����в����ַ���
 */
char *my_strstr(char *src, char *dest) {
    char *fsrc = src;//������ѭ��������ָ�루������ַ�����Ѱ�ң�
    char *tdest = dest;//�����ҵ��ַ���
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
        fsrc = record;//�����ַ����޸�Ϊrecordָ�뱾�μ�¼��λ��
        tdest = dest;//Ŀ���ַ����޸ĵ���ʼλ��
        fsrc++;//�����ַ���������һ��
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