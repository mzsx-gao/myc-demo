#include<stdio.h>
#include<stdlib.h>

/**
 * �ļ����д
 */
int write() {
    //�����ݿ�ķ�ʽ���ļ�д������
    FILE *fp = fopen("../base_file/filesource/e.txt", "wb");
    if (!fp)
        return -1;
    //int a = 5678;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    fwrite(arr, sizeof(int), 10, fp);
    fclose(fp);
    return 0;
}

int read() {
    FILE *fp = fopen("../base_file/filesource/e.txt", "rb");
    if (!fp)
        return -1;
    //int value;
    //fread(&value, sizeof(int), 1, fp);
    int arr[10] = {0};
    //�����ݿ�ķ�ʽ���ļ��ж�ȡ����
    fread(arr, sizeof(int), 10, fp);
    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }
    fclose(fp);
    return 0;
}

int mainfile16() {
    write();
    read();
}

/**
 * �ļ���д�ṹ��
 */
typedef struct student {
    char name[21];
    int age;
    int score;
    char addr[51];
} stu;

int stuc_write() {
    stu ss[3] =
            {
                    {"��ĳ��", 9,  10,   "�ӱ���ɽ"},
                    {"��ĳ��", 3,  1000, "�ӱ�����"},
                    {"��ʦ", 30, 1,    "����������"}
            };

    FILE *fp = fopen("../base_file/filesource/f.txt", "wb");
    if (!fp)return -1;
    for (int i = 0; i < 3; i++) {
        fwrite(&ss[i], sizeof(stu), 1, fp);
    }
    fclose(fp);
    return EXIT_SUCCESS;
}

int stuc_read(void) {
    FILE *fp = fopen("../base_file/filesource/f.txt", "rb");
    if (!fp)return -1;
    stu *ss = (stu *) malloc(sizeof(stu) * 3);
    int i = 0;
    while (1) {
        if (feof(fp))
            break;
        fread(&ss[i], sizeof(stu), 1, fp);
        i++;
    }
    for (int i = 0; i < 3; i++) {
        printf("������%s\n", ss[i].name);
        printf("���䣺%d\n", ss[i].age);
        printf("�ɼ���%d\n", ss[i].score);
        printf("��ַ��%s\n", ss[i].addr);
    }
    free(ss);
    fclose(fp);
    return 0;
}

int main() {
    stuc_write();
    stuc_read();
}