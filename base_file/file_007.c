#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

#define SIZE (1024*1024*8)//8MB

/**
 * ���ļ�����
 * 1.����:gcc -o copy.exe file_007.c
 * 2.����:copy.exe test.mp4 test1.mp4
 */
int main_filecopy(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    //�û��������ȱ��
    if (argc < 3) {
        printf("ȱ�ٲ���\n");
        return -1;
    }

    //D:/copy.exe  D:/test.avi D:/Code/test.avi
    //argv[0] ��������    �ļ���С��50M
    FILE *fp1 = fopen(argv[1], "rb");
    FILE *fp2 = fopen(argv[2], "wb");

    if (!fp1 || !fp2) {
        printf("�����ļ�����\n");
        return -2;
    }
    char *temp = NULL;
    int size = 0;
    struct stat st;
    //��ȡ�ļ�״̬
    stat(argv[1], &st);
    //�����ļ�ʵ�ʴ�С���ٿռ�
    if (st.st_size > SIZE) {
        temp = (char *) malloc(sizeof(char) * SIZE);
        size = SIZE;
    } else {
        temp = (char *) malloc(sizeof(char) * st.st_size + 10);
        size = st.st_size + 10;
    }
    int count = 0;
    while (!feof(fp1)) {
        memset(temp, 0, size);
        //countΪ��ȡ�ɹ�ʵ�ʸ���
        count = fread(temp, sizeof(char), size, fp1);
        fwrite(temp, sizeof(char), count, fp2);
    }
    free(temp);
    fclose(fp1);
    fclose(fp2);
    return EXIT_SUCCESS;
}

/*
    �ļ�״̬:
    struct stat {
        dev_t         st_dev;         //�ļ����豸���
        ino_t         st_ino;          //�ڵ�
        mode_t        st_mode;   //�ļ������ͺʹ�ȡ��Ȩ��
        nlink_t       st_nlink;     //�������ļ���Ӳ������Ŀ���ս������ļ�ֵΪ1
        uid_t         st_uid;         //�û�ID
        gid_t         st_gid;         //��ID
        dev_t         st_rdev;      //(�豸����)�����ļ�Ϊ�豸�ļ�����Ϊ���豸���
        off_t         st_size;        //�ļ��ֽ���(�ļ���С)
        unsigned long st_blksize;   //���С(�ļ�ϵͳ��I/O ��������С)
        unsigned long st_blocks;    //����
        time_t        st_atime;     //���һ�η���ʱ��
        time_t        st_mtime;    //���һ���޸�ʱ��
        time_t        st_ctime;     //���һ�θı�ʱ��(ָ����)
    }
 */
int main_filestatus() {
    //�ļ�״̬�ṹ�����
    struct stat st;
    stat("../base_file/filesource/e.txt", &st);

    printf("�ļ���С��%d\n", st.st_size);
    system("pause");
    return EXIT_SUCCESS;
}