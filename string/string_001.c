#include<stdio.h>
#include<stdlib.h>

int main0101() {
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

int main0102(void) {
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