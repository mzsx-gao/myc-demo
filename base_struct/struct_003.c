#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
 * �ṹ��Ƕ�׽ṹ��
 */
struct scores {
    int cl;//c����
    int cpp;//C++
    int cs;//C#
};

typedef struct student stu;
struct student {
    char name[21];
    int age;
    struct scores ss;
    char addr[51];
};


int main_stu06(void) {
    //struct student stu;
    stu s;
    printf("ѧ���ṹ���С��%d\n", sizeof(stu));
    printf("�ɼ��ṹ���С��%d\n", sizeof(s.ss));
    printf("���������С��%d\n", sizeof(s.name));
}

int main_stu07() {
    //struct student stu = { "����",18,99,99,99,"����" };

    struct student stu;
    strcpy(stu.name, "С��");
    stu.age = 20;
    stu.ss.cl = 88;
    stu.ss.cpp = 88;
    stu.ss.cs = 88;
    strcpy(stu.addr, "����");

    printf("%s\n%d\n%d\n%d\n%d\n%s\n",
           stu.name, stu.age, stu.ss.cl, stu.ss.cpp, stu.ss.cs, stu.addr);

    return EXIT_SUCCESS;
}

/*
 * �ṹ�帳ֵ
 */
struct student2 {
    char name[21];
    //char *name;
    int age;
    int score;
    char addr[51];
};

int main_stu08() {
    struct student2 stu = {"������", 26, 60, "����"};
    struct student2 s1 = stu;

    //�����ǳ����
    strcpy(s1.name, "�ʷ���");
    s1.age = 28;
    s1.score = 80;

    //��s1�ĸ�ֵ����Ӱ�쵽stu��ֵ�������������������ڴ�ռ�
    printf("%s\n", stu.name);
    printf("%d\n", stu.age);
    printf("%d\n", stu.score);

    return EXIT_SUCCESS;
}