#include<stdio.h>
#include<stdlib.h>


/*
 * �ṹ�嶨���ʹ��
 */
struct student {
    char name[21];
    int age;
    int score;
    char addr[51];
};

//��������ͬʱ�������
//struct student {
//    char name[21];
//    int age;
//    int score;
//    char addr[51];
//}stu = { "����",18,100,"�����в�ƽ������·22��" };
int main_stu01() {
    //�����ṹ�����
    //�ṹ������ �ṹ�����
    //struct student stu;
    ////stu.name = "����";
    //strcpy(stu.name, "����");
    //stu.age = 18;
    //stu.score = 100;
    //strcpy(stu.addr, "�����в�ƽ������·22��");

    struct student stu = {"����", 18, 100, "�����в�ƽ������·22��"};
    printf("������%s\n", stu.name);
    printf("���䣺%d\n", stu.age);
    printf("�ɼ���%d\n", stu.score);
    printf("��ַ��%s\n", stu.addr);

    return EXIT_SUCCESS;
}

int main_stu02(void) {
    struct student stu;
    scanf("%s%d%d%s", stu.name, &stu.age, &stu.score, stu.addr);
    printf("������%s\n", stu.name);
    printf("���䣺%d\n", stu.age);
    printf("�ɼ���%d\n", stu.score);
    printf("��ַ��%s\n", stu.addr);
    return 0;
}