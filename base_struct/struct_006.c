#include<stdio.h>
#include<stdlib.h>

/*
 * ������:
 * ����union��һ������ͬһ���洢�ռ�洢��ͬ�������ݵ����ͣ�
 * ��������ռ���ڴ泤�ȵ��������Ա�ĳ��ȱ�����Ҳ�н��������壻
 * ͬһ�ڴ�ο���������ż��ֲ�ͬ���͵ĳ�Ա����ÿһ˲ʱֻ��һ�������ã�
 * ����������������õĳ�Ա�����һ�δ�ŵĳ�Ա���ڴ���һ���µĳ�Ա��ԭ�еĳ�Ա��ֵ�ᱻ���ǣ�
 * ����������ĵ�ַ�����ĸ���Ա�ĵ�ַ����ͬһ��ַ
 */
union Var {
    int a;
    float b;
    double c;
    char d;
    short f[6];//12
};

int main_uni() {
    union Var var;
    var.a = 100;
    var.b = 3.14;
    printf("%d\n", var.a);
    printf("%f\n", var.b);
    printf("��С��%d\n", sizeof(var));
    printf("%p\n", &var);
    printf("%p\n", &var.a);
    printf("%p\n", &var.b);
    printf("%p\n", &var.c);
    return EXIT_SUCCESS;
}

/*
 * typedef:
 * 1��Ϊ�Ѵ��ڵ��������������
 * 2�����庯��ָ��
 */
typedef unsigned int ui;
typedef unsigned long long ull;

//typedef struct stu ss;
typedef struct stu {
    char name[21];
    int age;
    int score;
    char addr[51];
} ss;

int main_typedef() {
    ui a = 10;
    ull b = 20;
    ss stu;
    stu.name;
    printf("%d\n", a);
    printf("%d\n", b);
    return EXIT_SUCCESS;
}