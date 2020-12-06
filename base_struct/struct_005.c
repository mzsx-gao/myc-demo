#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

/*
 * �ṹ���뺯��
 */
typedef struct student ss;
struct student {
    char name[21];
//    char *name;
    int age;
    int score[3];
    char addr[51];
};

void stu_fun01(ss stu1) {
//    stu1.name = (char*)malloc(sizeof(char)*21);
    strcpy(stu1.name, "¬����");
    printf("�β�:%s\n", stu1.name);
}

int main_stu12() {
    ss stu = {NULL, 50, 101, "ˮ����ɽ"};
    // ע�⵱student��name��ָ�����ʱ���ſ�����һ�У���ʱ�βκ�ʵ��һ��;
    // ����벻һ�����ſ�stu_fun01�����ĵ�һ��
//    stu.name = (char*)malloc(sizeof(char) * 21);
    strcpy(stu.name, "�ν�");
    stu_fun01(stu);
    printf("ʵ��:%s\n", stu.name);
    return EXIT_SUCCESS;
}


/*
 * �ṹ��ָ����Ϊ��������,��ַ����
 */
void stu_fun02(ss *p) {
    strcpy(p->name, "����ʤ");
    printf("%s\n", p->name);
}

int main_stu13(void) {
    ss stu = {"����", 50, 101, "ˮ����ɽ"};
    stu_fun02(&stu);
    printf("%s\n", stu.name);
    return 0;
}

//������Ϊ���������˻�Ϊָ�� ��ʧԪ�ؾ��� ��Ҫ���ݸ���
void stu_BubbleSort(ss *stu, int len) {
    printf("%d\n", sizeof(stu));//ָ�������32λ����ϵͳ4���ֽڣ�64λ����ϵͳ8���ֽ�
    for (int i = 0; i < len - 1; i++)
        for (int j = 0; j < len - i - 1; j++) {
            //if (stu[j].age>stu[j + 1].age)
            if ((stu + j)->age > (stu + j + 1)->age) {
                ss temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
}

int main_stu14(void) {
    ss stu[3] = {
            {"³����", 30, 33, 33, 33, "��̨ɽ"},
            {"������", 45, 44, 44, 44, "�꾩"},
            {"�˴�ɩ", 28, 33, 33, 33, "�꾩"},
    };
    stu_BubbleSort(stu, 3);
    for (int i = 0; i < 3; i++) {
        printf("������%s\n", stu[i].name);
        printf("���䣺%d\n", stu[i].age);
        printf("�ɼ�1��%d\n", stu[i].score[0]);
        printf("�ɼ�2��%d\n", stu[i].score[1]);
        printf("�ɼ�3��%d\n", stu[i].score[2]);
        printf("��ַ��%s\n", stu[i].addr);
    }
}


/*
 * const ���νṹ��ָ��
 */
//const���νṹ��ָ������
int main_stu15() {
    ss stu1 = {"�����", 700, 101, 101, 101, "����ɽ"};
    ss stu2 = {"��˽�", 1200, 1000, 1000, 1000, "����ׯ"};

    const ss *p = &stu1;
    p = &stu2;//OK �����޸Ľṹ��ָ�������ֵ�������޸Ľṹ��ָ���Ӧ�ڴ�ռ��ֵ
    //p->age = 888;//err
    //(*p).age = 888;//err

    return EXIT_SUCCESS;
}

//const ���νṹ��ָ�����,�����޸�ָ���ָ��
int main_stu16(void) {
    ss stu1 = {"�����", 700, 101, 101, 101, "����ɽ"};
    ss stu2 = {"��˽�", 1200, 1000, 1000, 1000, "����ׯ"};

    ss *const p = &stu1;
    //p = &stu2;//err�������޸�ָ���ָ��
    p->age = 888;
    strcpy(p->name, "ɳ��");
    printf("%s\n",stu1.name);
}


int main_stu17(void) {
    ss stu1 = {"�����", 700, 101, 101, 101, "����ɽ"};
    ss stu2 = {"��˽�", 1200, 1000, 1000, 1000, "����ׯ"};

    //const ���νṹ��ָ������
    //const ���νṹ��ָ�����
    const ss *const p = &stu1;
    //p = &stu2;//err;
    //p->age = 888;//err
    ss **pp = &p;

    //*pp = &stu2;
    (*pp)->age = 888;
    (**pp).age = 888;
}