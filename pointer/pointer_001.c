#include "stdio.h"
#include<stdlib.h>

/**
 * ָ�����
 */

//����ָ��
int main001() {
    int a = 10;
    //����ָ����Խ����������ͱ������ڴ��ַ
    void *p = &a;

    //��ͨ������ָ���޸ı�����ֵʱ����Ҫ�ҵ�������Ӧ��ָ������
    *(int *) p = 100;
    printf("�޸�a��ֵ�Ժ�:%d\n", a);
    printf("%d\n", *(int *) p);

    printf("����ָ�����ڴ���ռ���ֽڴ�С:%d\n", sizeof(void *));
    return EXIT_SUCCESS;
}

/**
 * const���ε�ָ������
 */
//ָ�����޸ĳ�����ֵ
int main002() {
    //����
    const int a = 10;
    //a = 100;//err
    int *p = &a;
    *p = 100;
    printf("ָ����Լ���޸ĳ�����ֵ%d\n", a);

    //system("pause");
    return EXIT_SUCCESS;
}

//const����ָ�����ͣ�ָ��ָ���ڴ��������޸ģ�ָ��ָ����Ա�
int main003() {
    int a = 10;
    int b = 20;
    const int *p = &a;
    printf("%d\n", *p);
    //*p1 = 111; //err
    p = &b; //ok
    printf("%d\n", *p);
}

//const����ָ�����,�����޸�ָ��ָ���ڴ�ռ��ֵ���������޸�ָ�������ֵ
int main004() {
    int a = 10;
    int b = 20;
    int *const p = &a;
    //p = &b;//err
    *p = 200;
    printf("%d\n", a);
    return EXIT_SUCCESS;
}

//const����ָ������ ����ָ�����  ֻ��ָ��
int main005(void) {
    int a = 10;
    int b = 20;

    const int *const p = &a;

    //p = &b;//err
    //*p = 100;//err

    printf("�޸�ǰ:%d\n",*p);
    //����ָ�����
    int **pp = &p;

    *pp = &b;//*pp��һ��ָ���ֵ
    printf("�޸�һ��ָ���ֵ��:%d\n",*p);

    **pp = 100;//**pp�Ǳ�����ֵ
    printf("�޸ı�����ֵ��%d\n", *p);

    return 0;
}