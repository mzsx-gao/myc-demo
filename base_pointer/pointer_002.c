#include "stdio.h"

/**
 * ָ��������
 */
int main002_01() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //��������һ������ ������ֵ
    //��������������Ԫ�ص�ַ
    //arr = 100;//err

    int *p = arr;
    printf("ָ�����p��ֵ:%p\n", p);
    printf("������������Ԫ�صĵ�ַ:%p\n", arr);

    *p = 123;//�ı�������Ԫ�ص�ֵ

    //ָ���һ��ͬ���ڴ��ַ����һ��sizeof(ָ������)�Ĵ�С
//    p++;
//    printf("����ԭ��ַ:%p\n", arr);
//    printf("ָ���һ��:%p\n", p);


    //���¼���ȡֵ��ʽЧ��һ��
    printf("=======��ӡ����========\n");
    for (int i = 0; i < 10; i++) {
//        printf("%d\n", arr[i]);//arr[0]
//        printf("%d\n", *(arr + i));//arr�ǵ�ַ����ַ+ƫ�������ǵ�ַ
//        printf("%d\n", p[i]);
//        printf("%d\n", *(p + i));
        printf("%d\n", *p++);
    }

    //p����++�Ժ�p��arr�Ѿ����������
    printf("p == arr���:%d\n", p == arr);


    //����ָ������õ��Ľ��������ָ���ƫ����(������
    //���е�ָ����������������int����
    int step = p - arr;

    printf("ָ�����(p-arr)�Ľ����:%d\n", step);

    return 0;
}

int main002_02() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //ָ�������ָ��
    int *p = arr;
    //p�Ǳ���  arr�ǳ���
    //p��һ��ָ�� 4���ֽڴ�С
    //arr��һ������ 40�ֽڴ�С
    printf("ָ�����ʹ�С��%d\n", sizeof(p));
    printf("�����С��%d\n", sizeof(arr));

    //p[i];
    //*(p+i);
    return 0;
}

//������Ϊ�����������˻�Ϊָ�� ��ʧ����ľ���(��֪������ĳ��ȣ���Ҫ���÷���Ϊ�������ݹ���)
void BubbleSort2(int *arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (*(arr + j) > *(arr + j + 1)) {//*(p + j)д����ͬ��arr[j]
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int main0103(void) {
    int arr[] = {9, 1, 5, 6, 3, 8, 10, 2, 7, 4};

    BubbleSort2(arr, 10);

    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}