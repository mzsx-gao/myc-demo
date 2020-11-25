#include "stdio.h"
#include<stdlib.h>

/**
 * ָ�����
 * 1.ָ�붨���ʹ��
 * 2.Ұָ��
 * 3.��ָ��
 * 4.����ָ��
 * 5.const���ε�ָ������
 */

//ָ�붨���ʹ��
int main001_01(void) {

    //ʾ��1:
    //����ָ������洢������ַ
    int a = 10;
    //ָ������  -> ��������*
    int *p = &a;
    //ͨ��ָ���Ӹı������ֵ
    *p = 100;
    printf("%p\n", &a);
    printf("%p\n", p);

    printf("%d\n", a);
    printf("%d\n", *p);

    //ʾ��2:
    //ָ�����ڴ���ռ���ֽڴ�С:32λϵͳռ4���ֽڣ�64λϵͳռ8���ֽ�
//    printf("%d\n", sizeof(char *));
//    printf("%d\n", sizeof(int *));
//    printf("%d\n", sizeof(short *));
//    printf("%d\n", sizeof(long *));
//    printf("%d\n", sizeof(long long *));
//    printf("%d\n", sizeof(float *));
//    printf("%d\n", sizeof(double *));

    //ʾ��3:
//    char ch = 97;
//    int *p = &ch;
//    *p = 96;
//    printf("%d\n", ch);
//    printf("%d\n", *p);
//    printf("%p\n", p);
//    printf("%p\n", &ch);

    return 0;
}

/**
 * Ұָ��:
 * ������ֵ��ֵ��ָ�����û�����壬��Ϊ������ָ��ͳ���Ұָ�룬��ָ��ָ���������δ֪(����ϵͳ�����������ָ��ָ����ڴ�����)��
 * ���ԣ�Ұָ�벻��ֱ���������󣬲���Ұָ��ָ����ڴ�����Ż������
 */
int main001_02() {
    //�����齫һ��������ֱֵ�Ӹ�ֵ��ָ��
    //Ұָ�� -��ָ�����ָ��һ��δ֪�Ŀռ�
    int *p = 100;
    //�������������Ұָ��
    //����ϵͳ��0-255��Ϊϵͳռ�ò�������ʲ���
    //����Ұָ���Ӧ���ڴ�ռ���ܱ���

    printf("%d\n", *p);
    return EXIT_SUCCESS;
}

//��ָ��
int main001_03(void) {
    //��ָ����ָ�ڴ��ַ���Ϊ0�Ŀռ�
    int *p = NULL;
    //������ָ���Ӧ�Ŀռ�һ���ᱨ��
    *p = 100;//err
    printf("%d\n", *p);
    //��ָ��������������ж�

    return 0;
}


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

    printf("�޸�ǰ:%d\n", *p);
    //����ָ�����
    int **pp = &p;

    *pp = &b;//*pp��һ��ָ���ֵ
    printf("�޸�һ��ָ���ֵ��:%d\n", *p);

    **pp = 100;//**pp�Ǳ�����ֵ
    printf("�޸ı�����ֵ��%d\n", *p);

    return 0;
}