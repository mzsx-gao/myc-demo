#include<stdio.h>
#include<stdlib.h>

int main_arr01() {
    //��������
    //�������� ����  = ֵ
    //���鶨��
    //�������� ������[Ԫ�ظ���]={ֵ1��ֵ2��ֵ3}
    int arr[10] = {9, 4, 2, 1, 8, 5, 3, 6, 10, 7};

    //�����±�  ������[�±�]
    //�����±��Ǵ�0��ʼ�ĵ�����Ԫ�ظ���-1
    //printf("%d\n", arr[0]);

    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }

    return EXIT_SUCCESS;
}

int main_arr02(void) {
    //�������ڴ��д洢��ʽ�ʹ�С
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //�±�Ϊ0��Ԫ�ص�ַ
    //printf("%p\n", &arr[0]);
    //printf("%p\n", &arr[1]);
    //printf("%p\n", &arr[2]);
    //printf("%p\n", &arr[3]);
    //printf("%p\n", &arr[4]);
    //��������һ����ַ����  ָ�������׵�ַ�ĳ���

    //printf("%p\n", arr);


    printf("�������ڴ���ռ�Ĵ�С��%d\n", sizeof(arr));
    printf("����Ԫ�ش�С��%d\n", sizeof(arr[0]));
    printf("����Ԫ�ظ�����%d\n", sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}

#define SIZE 10

int main_arr03(void) {
    //int i = 10;
    //����Ԫ�ر����ǳ��� �������ʽ
    //�������Ԥ��֪����С ��̬����-�����ٶѿռ�
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < SIZE; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}

int main_arr04(void) {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //printf("%d\n", arr[-1]);//err
    printf("%d\n", arr[10]);//err
    for (int i = 0; i < 20; i++) {
        //�����±�Խ��  0-9
        printf("%d\n", arr[i]);//err
    }
    return 0;
}

//���鵹������
int main_arr05() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i = 0;
    int j = sizeof(arr) / sizeof(arr[0]) - 1;

    while (i < j) {
        //ͨ����ʱ������������
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        i++;
        j--;
    }
    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }
    return EXIT_SUCCESS;
}

//ð������
int main_arr06() {
    int arr[] = {9, 1, 5, 7, 2, 10, 8, 4, 6, 3};
    //��������
    //���ִ��Ԫ�ظ���-1��
    for (int i = 0; i < 9; i++) {
        //�ڲ������
        //�ڲ�ִ��Ԫ�ظ���-1-ִ�д���
        for (int j = 0; j < 9 - i; j++) {
            //�Ƚ�����Ԫ�� ������������
            //ͨ�����ſ�������ķ�ʽ
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }

    return EXIT_SUCCESS;
}