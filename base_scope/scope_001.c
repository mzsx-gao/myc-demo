#include<stdio.h>
#include<stdlib.h>

/*
 * ��̬�ֲ�����:
 * ��̬�ֲ�����ֻ���ʼ��һ��  ���Զ�θ�ֵ
 * �����������̴洢
 * ������ֻ���ں����ڲ�ʹ��
 * �������ڣ��ӳ��򴴽�����������
 */
void fun04() {
    static int b = 10;
    b++;
    printf("%d\n", b);
}

int main_sc001() {
    //��̬�ֲ�����
    static int b = 10;
    for (int i = 0; i < 10; i++) {
        fun04();
    }
    printf("%d\n", b);
    return EXIT_SUCCESS;
}


/**
 * ��̬ȫ�ֱ���:
 * �����򣺿����ڱ��ļ���ʹ�� �������������ļ���ʹ��
 * �������ڣ��ӳ��򴴽�����������
 */
static int c = 10;

void fun05() {
    c = 20;
    printf("%d\n", c);
}

int main_sc002() {
    printf("%d\n", c);
    fun05();
    return EXIT_SUCCESS;
}


/**
 * δ��ʼ��������Ĭ��ֵ
 */
int abc;//δ��ʼ����ȫ�ֱ���
static int abc2;//δ��ʼ���ľ�̬ȫ�ֱ���
int main_sc003() {

    int abc3;  //�ֲ�����δ��ʼ��ֵΪ����
    static int abc4;//δ��ʼ���ľ�̬�ֲ�����

    printf("%d\n", abc);
    printf("%d\n", abc2);
    printf("%d\n", abc3);
    printf("%d\n", abc4);
    return EXIT_SUCCESS;
}


//�������Ե����Լ�  ��Ϊ�ݹ麯��
void BubbleSort(int *, int);

/*
 * ȫ�ֺ���
 */
int main_sc004() {
    int arr[] = {9, 1, 5, 6, 8, 2, 7, 10, 4, 3};
    //ȫ�ֺ�������������������Ψһ��
    //��������������Ŀ�������ļ���ʹ��
    //�������ڣ��ӳ��򴴽�����������
    BubbleSort(arr, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }
    return EXIT_SUCCESS;
}

/*
 * ��̬����:
 * ��̬�������Ժ�ȫ�ֺ�������
 * �����򣺵�ǰ�ļ���
 * �������ڣ��ӳ��򴴽�����������
 */
static void fun07() {
    printf("hello world1\n");
}

int main_sc005(void) {
    fun07();
}