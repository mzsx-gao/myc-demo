#include<stdio.h>
#include<stdlib.h>

struct student {
    //�ṹ���Ա��Ҫƫ�ƶ���
    char name[21];
    int age;
    char sex;
    int score[3];
    char addr[51];
};

int main_stu03() {
    struct student stu[3] =
            {
                    {"��ĳ��", 22, 'M', 88,  99,  0,   "�ӱ���ɽ"},
                    {"��ĳ��", 18, 'F', 59,  59,  59,  "�ӱ�����"},
                    {"��ʦ", 30, 'M', 100, 100, 100, "����������"}
            };
    //sizeof()���������������ڴ���ռ���ֽڴ�С
    printf("�ṹ�������С��%d\n", sizeof(stu));
    printf("�ṹ��Ԫ�ش�С��%d\n", sizeof(stu[0]));
    printf("�ṹ��Ԫ�ظ�����%d\n", sizeof(stu) / sizeof(stu[0]));
    for (int i = 0; i < 3; i++) {
        printf("������%s\n", stu[i].name);
        printf("���䣺%d\n", stu[i].age);
        printf("�Ա�%s\n", stu[i].sex == 'M' ? "��" : "Ů");
        printf("�ɼ�1��%d\n", stu[i].score[0]);
        printf("�ɼ�2��%d\n", stu[i].score[1]);
        printf("�ɼ�3��%d\n", stu[i].score[2]);
        printf("��ַ��%s\n", stu[i].addr);
    }

    return EXIT_SUCCESS;
}

int main_stu04(void) {
    struct student stu[3] =
            {
                    {"��ĳ��", 22, 'M', 88,  99,  0,   "�ӱ���ɽ"},
                    {"��ĳ��", 18, 'F', 59,  59,  59,  "�ӱ�����"},
                    {"��ʦ", 30, 'M', 100, 100, 100, "����������"}
            };

    for (int i = 0; i < 3 - 1; i++) {
        for (int j = 0; j < 3 - 1 - i; j++) {
            if (stu[j].age < stu[j + 1].age) {
                //�ṹ�帳ֵ
                struct student temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        printf("������%s\n", stu[i].name);
        printf("���䣺%d\n", stu[i].age);
        printf("�Ա�%s\n", stu[i].sex == 'M' ? "��" : "Ů");
        printf("�ɼ�1��%d\n", stu[i].score[0]);
        printf("�ɼ�2��%d\n", stu[i].score[1]);
        printf("�ɼ�3��%d\n", stu[i].score[2]);
        printf("��ַ��%s\n", stu[i].addr);
    }
    return 0;
}

typedef struct student ss;

//���ٶѿռ�洢�ṹ��
int main_stu05() {
    //printf("%d\n", sizeof(struct student));
    ss *p = (ss *) malloc(sizeof(ss) * 3);
    printf("�ṹ��ָ���С��%d\n", sizeof(ss *));

    for (int i = 0; i < 3; i++) {
        scanf("%s%d,%c%d%d%d%s", p[i].name, &p[i].age, &p[i].sex,
              &p[i].score[0], &p[i].score[1], &p[i].score[2], p[i].addr);
    }

    for (int i = 0; i < 3; i++) {
        printf("������%s\n", p[i].name);
        printf("���䣺%d\n", p[i].age);
        printf("�Ա�%s\n", p[i].sex == 'M' ? "��" : "Ů");
        printf("�ɼ�1��%d\n", p[i].score[0]);
        printf("�ɼ�2��%d\n", p[i].score[1]);
        printf("�ɼ�3��%d\n", p[i].score[2]);
        printf("��ַ��%s\n", p[i].addr);
    }
    free(p);
    return EXIT_SUCCESS;
}