#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
 * �ṹ����ָ��
 */
//�ṹ���ԱΪָ������
struct student {
    char *name;
    int age;
    int *scores;
    char *addr;
};

int main0701() {

    struct student stu;
    //stu.name = "����";
    stu.name = (char *) malloc(sizeof(char) * 21);
    stu.scores = (int *) malloc(sizeof(int) * 3);
    stu.addr = (char *) malloc(sizeof(char) * 51);
    strcpy(stu.name, "����");
    stu.age = 18;
    stu.scores[0] = 88;
    stu.scores[1] = 99;
    stu.scores[2] = 100;
    strcpy(stu.addr, "������");

    printf("%s\n", stu.name);
    printf("%d\n", stu.age);
    printf("%d\n", stu.scores[0]);
    printf("%d\n", stu.scores[1]);
    printf("%d\n", stu.scores[2]);
    printf("%s\n", stu.addr);

    free(stu.name);
    free(stu.scores);
    free(stu.addr);

    return EXIT_SUCCESS;
}

struct stu {
    char name[21];
    int age;
    int scores[3];
    char addr[51];
};

int main0702(void) {
    //�ṹ��ָ��
    struct stu ss = {"�ֳ�", 30, 100, 100, 100, "�꾩"};
    struct stu *p = &ss;
    //printf("%s\n", (*p).name);
    //printf("%d\n", (*p).age);

    //�ṹ��ָ��->��Ա
    //�ṹ�����.��Ա
    printf("%s\n", p->name);
    printf("%d\n", p->age);
    printf("%d\n", p->scores[0]);
    printf("%d\n", p->scores[1]);
    printf("%d\n", p->scores[2]);
    printf("%s\n", p->addr);

    return 0;
}