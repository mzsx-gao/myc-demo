#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//�ļ������д����ƫ������
int main_radom1() {
    FILE *fp = fopen("../base_file/filesource/a.txt", "r");
    if (!fp)
        return -1;

    char arr[100];

    //��ȡһ��
    memset(arr, 0, 100);
    fgets(arr, 100, fp);
    printf("%s", arr);

    //�ٶ�ȡһ��
    memset(arr, 0, 100);
    fgets(arr, 100, fp);
    printf("%s", arr);

    printf("%s\n","=================�ļ������д===========");
    //�ļ������д
    fseek(fp, -6, SEEK_CUR);//�ӵ�ǰλ��ƫ��
    memset(arr, 0, 100);
    fgets(arr, 100, fp);
    printf("�ڶ����ٶ�ȡһ�飺%s", arr);


    //���ļ���ʼλ�ÿ�ʼƫ��
    fseek(fp, 6, SEEK_SET);
    memset(arr, 0, 100);
    fgets(arr, 100, fp);
    printf("%s", arr);

    //���ļ���βλ�ÿ�ʼƫ��
    fseek(fp, -8, SEEK_END);
    memset(arr, 0, 100);
    fgets(arr, 100, fp);
    printf("%s", arr);

    return EXIT_SUCCESS;
}

int main_radom2(void) {
    FILE *fp = fopen("../base_file/filesource/a.txt", "r+");
    if (!fp)
        return -1;
    //��ȡ�ļ������ļ���꣩�Ķ�дλ��
    long pos = ftell(fp);
    printf("%ld\n", pos);

    fseek(fp, 5, SEEK_CUR);
    //fseek(fp, -19, SEEK_END);
    pos = ftell(fp);
    printf("%ld\n", pos);

    fputs("����զ����\n", fp);

    fclose(fp);
    return 0;
}

int main_radom3(void) {
    //��д��ʽ���ļ�(����ļ�����������ļ����ļ��������򴴽�һ���ļ�)
    FILE *fp = fopen("../base_file/filesource/b.txt", "w");
    if (!fp)
        return -1;
    char ch1[] = "hello nihao";
    char ch2[] = "world";

    fputs(ch1, fp);
    //�����ǰ�ƶ�10���ַ�
    fseek(fp, -10, SEEK_CUR);
    fputs(ch2, fp);
    fclose(fp);
    return 0;
}

int main_radom4(void) {
    FILE *fp = fopen("../base_file/filesource/b.txt", "r");
    if (!fp) {
        return -1;
    }
    char arr[100];
    //��ȡ�ļ����������λ��
    long pos = ftell(fp);
    printf("%ld\n", pos);

    fgets(arr, 100, fp);
    fseek(fp, 8, SEEK_CUR);
    pos = ftell(fp);
    printf("%ld\n", pos);

    //�����ļ��������ʼλ��
    rewind(fp);//fseek(fp,0,SEEK_SET);
    memset(arr, 0, 100);
    fgets(arr, 100, fp);
    printf("%s", arr);

    return 0;
}