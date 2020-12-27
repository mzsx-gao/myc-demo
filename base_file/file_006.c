#include<stdio.h>
#include<stdlib.h>

/**
 * 文件块读写
 */
int write() {
    //以数据块的方式给文件写入内容
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
    //以数据块的方式从文件中读取内容
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
 * 文件读写结构体
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
                    {"黄某航", 9,  10,   "河北唐山"},
                    {"马某羊", 3,  1000, "河北邯郸"},
                    {"大法师", 30, 1,    "黑龙江大庆"}
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
        printf("姓名：%s\n", ss[i].name);
        printf("年龄：%d\n", ss[i].age);
        printf("成绩：%d\n", ss[i].score);
        printf("地址：%s\n", ss[i].addr);
    }
    free(ss);
    fclose(fp);
    return 0;
}

int main() {
    stuc_write();
    stuc_read();
}