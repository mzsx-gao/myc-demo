#include<stdio.h>
#include<stdlib.h>

/**
 * ɾ���ļ�
 * @return
 */
int main_del() {
    int value = remove("../base_file/filesource/test.txt");
    if (value == 0) {
        printf("ɾ���ɹ�\n");
    } else {
        printf("ɾ��ʧ��\n");
    }
    return EXIT_SUCCESS;
}

/**
 * �������ļ�
 * @return
 */
int main_rerame(void) {
    //������
    //int value = rename("D:/a.txt", "D:/abc.txt");
    //�ƶ��ļ� ����
    int value = rename("../base_file/filesource/rename.txt", "../base_file/filesource/re.txt");
    if (value == 0) {
        printf("�ɹ�\n");
    } else {
        printf("ʧ��\n");
    }
}

int main() {
    FILE *fp = fopen("../base_file/filesource/a.txt", "w+");
    if (!fp)
        return -1;
    char ch;
    while (1) {
        scanf("%c", &ch);
        if (ch == '@')
            break;
        //���»��������û���������������д���ļ���
        fflush(fp);
        fputc(ch, fp);
    }
    fclose(fp);
    return EXIT_SUCCESS;
}