#include<stdio.h>
#include<stdlib.h>

/*
 * ��̬�ֲ�����
 */
void fun04() {
    //��̬�ֲ�����ֻ���ʼ��һ��  ���Զ�θ�ֵ
    //�����������̴洢
    //������ֻ���ں����ڲ�ʹ��
    //�������ڣ��ӳ��򴴽�����������
    static int b = 10;
    b++;
    printf("%d\n", b);
}

int main() {
    //��̬�ֲ�����
    //static int b = 10;
    for (int i = 0; i < 10; i++) {
        fun04();
    }
    //printf("%d\n", b);
    return EXIT_SUCCESS;
}
