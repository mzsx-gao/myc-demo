#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
 * �ļ��ж�д
 */
int main_file08() {
    FILE *fp = fopen("../base_file/filesource/a.txt", "r");
    if (!fp){
        printf("�ļ���ʧ��\n");
        return -1;
    }
    char *p = (char *) malloc(sizeof(char) * 1024);

    memset(p, 0, 5);
    fgets(p, 5, fp);
    printf("��һ�ζ�:%s\n", p);

    printf("=====\n");
    memset(p, 0, 5);
    fgets(p, 5, fp);
    printf("�ڶ��ζ�:%s\n", p);

    free(p);
    fclose(fp);

    return EXIT_SUCCESS;
}


int main_file09(void) {
    FILE *fp = fopen("../base_file/filesource/a.txt", "r");
    if (!fp){
        return -1;
    }
    char *p = (char *) malloc(sizeof(char) * 100);

    //feof���ļ�ָ�룩  �ж��ļ��Ƿ񵽽�β �����ж��ı��ļ�Ҳ�����ж϶������ļ�
    //������ļ���β����ֵΪ ��0��ֵ
    //���û���ļ���β����ֵΪ 0
    while (!feof(fp)) {
        memset(p, 0, 100);
        fgets(p, 100, fp);
        printf("%s", p);
    }
    free(p);
    fclose(fp);
    return 0;
}

//��str��ָ�����ַ���д�뵽streamָ�����ļ��У��ַ��������� '\0'  ��д���ļ�
int main_file10(void) {
    FILE *fp = fopen("../base_file/filesource/b.txt", "w");
    if (!fp)
        return -1;
    char ch[] = "���ɶ����զ����";
    fputs(ch, fp);
    fclose(fp);
    return 0;
}

int main(void) {
    FILE *fp = fopen("../base_file/filesource/b.txt", "w");
    if (!fp)
        return -1;

    char *p = (char *) malloc(sizeof(char) * 1024);

    while (1) {
        memset(p, 0, 1024);
        //scanf("%s", p);
        //fgets()
        scanf("%[^\n]", p);
        //���ɻس�\n
        getchar();
        //ֹͣ��������  comm=exit
        if (!strcmp(p, "comm=exit")){
            break;
        }
        //׷��\n
        strcat(p, "\n");
        fputs(p, fp);
    }
    free(p);
    fclose(fp);
}