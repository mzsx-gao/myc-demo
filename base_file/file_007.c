#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

#define SIZE (1024*1024*8)//8MB

/**
 * 大文件拷贝
 * 1.编译:gcc -o copy.exe file_007.c
 * 2.运行:copy.exe test.mp4 test1.mp4
 */
int main_filecopy(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    //用户输入参数缺少
    if (argc < 3) {
        printf("缺少参数\n");
        return -1;
    }

    //D:/copy.exe  D:/test.avi D:/Code/test.avi
    //argv[0] 程序名称    文件大小是50M
    FILE *fp1 = fopen(argv[1], "rb");
    FILE *fp2 = fopen(argv[2], "wb");

    if (!fp1 || !fp2) {
        printf("复制文件出错\n");
        return -2;
    }
    char *temp = NULL;
    int size = 0;
    struct stat st;
    //获取文件状态
    stat(argv[1], &st);
    //根据文件实际大小开辟空间
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
        //count为读取成功实际个数
        count = fread(temp, sizeof(char), size, fp1);
        fwrite(temp, sizeof(char), count, fp2);
    }
    free(temp);
    fclose(fp1);
    fclose(fp2);
    return EXIT_SUCCESS;
}

/*
    文件状态:
    struct stat {
        dev_t         st_dev;         //文件的设备编号
        ino_t         st_ino;          //节点
        mode_t        st_mode;   //文件的类型和存取的权限
        nlink_t       st_nlink;     //连到该文件的硬连接数目，刚建立的文件值为1
        uid_t         st_uid;         //用户ID
        gid_t         st_gid;         //组ID
        dev_t         st_rdev;      //(设备类型)若此文件为设备文件，则为其设备编号
        off_t         st_size;        //文件字节数(文件大小)
        unsigned long st_blksize;   //块大小(文件系统的I/O 缓冲区大小)
        unsigned long st_blocks;    //块数
        time_t        st_atime;     //最后一次访问时间
        time_t        st_mtime;    //最后一次修改时间
        time_t        st_ctime;     //最后一次改变时间(指属性)
    }
 */
int main_filestatus() {
    //文件状态结构体变量
    struct stat st;
    stat("../base_file/filesource/e.txt", &st);

    printf("文件大小：%d\n", st.st_size);
    system("pause");
    return EXIT_SUCCESS;
}