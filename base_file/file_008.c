#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//文件随机读写（带偏移量）
int main_radom1() {
    FILE *fp = fopen("../base_file/filesource/a.txt", "r");
    if (!fp)
        return -1;

    char arr[100];

    //读取一行
    memset(arr, 0, 100);
    fgets(arr, 100, fp);
    printf("%s", arr);

    //再读取一行
    memset(arr, 0, 100);
    fgets(arr, 100, fp);
    printf("%s", arr);

    printf("%s\n","=================文件随机读写===========");
    //文件随机读写
    fseek(fp, -6, SEEK_CUR);//从当前位置偏移
    memset(arr, 0, 100);
    fgets(arr, 100, fp);
    printf("第二行再读取一遍：%s", arr);


    //从文件起始位置开始偏移
    fseek(fp, 6, SEEK_SET);
    memset(arr, 0, 100);
    fgets(arr, 100, fp);
    printf("%s", arr);

    //从文件结尾位置开始偏移
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
    //获取文件流（文件光标）的读写位置
    long pos = ftell(fp);
    printf("%ld\n", pos);

    fseek(fp, 5, SEEK_CUR);
    //fseek(fp, -19, SEEK_END);
    pos = ftell(fp);
    printf("%ld\n", pos);

    fputs("瞅你咋地啦\n", fp);

    fclose(fp);
    return 0;
}

int main_radom3(void) {
    //以写方式打开文件(如果文件存在则清空文件，文件不存在则创建一个文件)
    FILE *fp = fopen("../base_file/filesource/b.txt", "w");
    if (!fp)
        return -1;
    char ch1[] = "hello nihao";
    char ch2[] = "world";

    fputs(ch1, fp);
    //光标向前移动10个字符
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
    //获取文件光标流所在位置
    long pos = ftell(fp);
    printf("%ld\n", pos);

    fgets(arr, 100, fp);
    fseek(fp, 8, SEEK_CUR);
    pos = ftell(fp);
    printf("%ld\n", pos);

    //重置文件光标在起始位置
    rewind(fp);//fseek(fp,0,SEEK_SET);
    memset(arr, 0, 100);
    fgets(arr, 100, fp);
    printf("%s", arr);

    return 0;
}