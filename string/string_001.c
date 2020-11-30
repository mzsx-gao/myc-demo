#include<stdio.h>
#include<stdlib.h>

/*
 * �ַ�ָ��
 */
int main_str0101() {
    char ch[] = "hello world";//ջ���ַ���
    char *p = "hello world";//�������������ַ���,�������޸�

    ch[2] = 'm';
    //p[2] = 'm';//err
    //*(p + 2) = 'm';//err
    printf("%c\n", p[2]);
    printf("%s\n", ch);
    printf("%s\n", p);
    return EXIT_SUCCESS;
}

int main_str0102(void) {
    //�ַ�������
    //ָ������
    //char ch1[] = "hello";
    //char ch2[] = "world";
    //char ch3[] = "dabaobei";
    //char* arr[] = { ch1, ch2, ch3 };
    //�ַ�������  ָ������
    char *arr[] = {"hello", "world", "dabaobei"};

    //�ַ�������
    for (int i = 0; i < 3 - 1; i++) {
        for (int j = 0; j < 3 - 1 - i; j++) {
            //�����ַ����бȽ�
            if (arr[j][0] > arr[j + 1][0]) {
                //����ָ������Ԫ�ؽ�������

                char *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        printf("%s\n", arr[i]);
    }
    return 0;
}


/*
 * �ַ�ָ������������
 */
int my_strlen01(char *ch) {
    //�����ַ�����Ч����
    int i = 0;
    while (ch[i])i++;
    return i;
}

int my_strlen(const char *ch) {
    if (ch == NULL)
        return 0;

    char *temp = ch;
    while (*temp)temp++;
    return temp - ch;
}

int main_str0103() {
    char ch[] = "hello world";
    printf("%s\n", ch);
//    int len = my_strlen01(ch);
    int len = my_strlen(ch);
    printf("%d\n", len);
    return EXIT_SUCCESS;
}


/*
 * const���ε�ָ��
 */
//ͨ��һ��ָ�����޸ı�����ֵ
int main_str0104() {
    const int a = 10;
    //a = 100;//err

    int *p = &a;
    *p = 100;
    return EXIT_SUCCESS;
}

//ָ������ָ��
//�����޸�ָ�������ֵ  �������޸�ָ�����ָ���ڴ�ռ��ֵ
int main_str0105(void) {
    char ch1[] = "hello";
    char ch2[] = "world";
    const char *p = ch1;
    //*p = 'm';//err
    //p[2] = 'm';//*(p+2)='m';//err
    p = ch2;//ok

    return 0;
}

//����ָ��
//�����޸�ָ�����ָ���ڴ�ռ��ֵ���������޸�ָ�������ֵ
int main_str0106(void) {
    char ch1[] = "hello";
    char ch2[] = "world";

    char *const p = ch1;

    //p = ch2;//err
    //p[2] = 'm';//ok
    *(p + 2) = 'm';//ok
    printf("%s\n", p);
    printf("%s\n", ch1);
    return 0;
}

//const����ָ������ ����ָ�����  ֻ��ָ�롣��ͨ������ָ���޸�
int main_str0107(void) {
    char ch1[] = "hello";
    char ch2[] = "world";

    const char *const p = ch1;

    //p = ch2;//err
    //*p = 'm';//err
    //p[2]='m'//err

    char **p1 = &p;

    //*p1 = ch2;//ok
    *(*p1 + 1) = 'm';//ok
    printf("%s\n", p);
    return 0;
}