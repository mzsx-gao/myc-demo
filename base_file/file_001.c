#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
 * �ļ�����ر�
 */
int main_file01() {
    FILE *fp = fopen("D:/a.txt", "r");
    //1���Ҳ����ļ�
    //2���ļ�Ȩ�ޣ��� д ִ�У�
    //3��������ļ��������� 65535
    if (fp == NULL) {
        printf("���ļ�ʧ��\n");
        return -1;
    }
    //fpΪ�ļ�ָ��
    printf("�ļ��򿪳ɹ�:%p\n", fp);

    fclose(fp);
    return EXIT_SUCCESS;
}

/*
 * �ļ��ַ���д
 */
int main_file02() {
    FILE *fp = fopen("../base_file/filesource/a.txt", "r");
    if (!fp) {
        printf("�ļ���ʧ��\n");
        return -1;
    }
    char ch;
    //�ļ����ַ���ȡ
    //�ļ�Ĭ�Ͻ�βΪ-1
    ch = fgetc(fp);
    printf("%c\n", ch);
    //�����޸��ļ�ָ��  �ļ��ڶ�ȡʱ��������Զ������ƶ�
    //fp++;//err
    ch = fgetc(fp);
    printf("%c\n", ch);
    //�ر��ļ�
    fclose(fp);

    return EXIT_SUCCESS;
}

/*
 * EOF��ʾ�ļ�������(end of file)����whileѭ������EOF��Ϊ�ļ�������־��
 * ������EOF��Ϊ�ļ�������־���ļ����������ı��ļ������ı��ļ��У����ݶ������ַ���ASCII����ֵ����ʽ��š�
 * ����֪����ASCII����ֵ�ķ�Χ��0~127�������ܳ���-1����˿�����EOF��Ϊ�ļ�������־
 */
int main_file03(void) {
    FILE *fp = fopen("../base_file/filesource/a.txt", "r");
    if (!fp)
        return -1;
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }
    fclose(fp);
}

//�ļ��ַ�д��
int main_file04(void) {
    //��д�ķ�ʽ���ļ� ����ļ�����ᴴ��һ�����ļ�  ����ļ����� ���������
    FILE *fp = fopen("../base_file/filesource/b.txt", "w");
    if (!fp)
        return -1;
    char ch = 'b';
    //�ַ�д��
    fputc(ch, fp);
    fclose(fp);
    return 0;
}

int main_file05(void) {
    FILE *fp = fopen("../base_file/filesource/c.txt", "w");
    if (!fp) {
        printf("�ļ���ʧ��\n");
        return -1;
    }
    char ch;
    while (1) {
        scanf("%c", &ch);
        if (ch == '@') {
            break;
        }
        fputc(ch, fp);
    }
    fclose(fp);
    return 0;
}

/*
 * �򵥵ļ��ܽ���
 */
//����
int main_file06() {
    FILE *fp1 = fopen("../base_file/filesource/����.txt", "r");
    FILE *fp2 = fopen("../base_file/filesource/����.txt", "w");
    if (!fp1 || !fp2) {
        return -1;
    }
    char ch;
    while ((ch = fgetc(fp1)) != EOF) {
        //����
        ch++;
        fputc(ch, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    return EXIT_SUCCESS;
}
//����
int main_file07(void) {
    FILE *fp1 = fopen("../base_file/filesource/����.txt", "r");
    FILE *fp2 = fopen("../base_file/filesource/����.txt", "w");
    if (!fp1 || !fp2)
        return -1;
    char ch;
    while ((ch = fgetc(fp1)) != EOF) {
        ch--;
        fputc(ch, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}