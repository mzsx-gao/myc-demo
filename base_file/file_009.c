#include<stdio.h>
#include<stdlib.h>

/**
 * 删除文件
 * @return
 */
int main_del() {
    int value = remove("../base_file/filesource/test.txt");
    if (value == 0) {
        printf("删除成功\n");
    } else {
        printf("删除失败\n");
    }
    return EXIT_SUCCESS;
}

/**
 * 重命名文件
 * @return
 */
int main_rerame(void) {
    //重命名
    //int value = rename("D:/a.txt", "D:/abc.txt");
    //移动文件 剪切
    int value = rename("../base_file/filesource/rename.txt", "../base_file/filesource/re.txt");
    if (value == 0) {
        printf("成功\n");
    } else {
        printf("失败\n");
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
        //更新缓冲区，让缓冲区的数据立马写到文件中
        fflush(fp);
        fputc(ch, fp);
    }
    fclose(fp);
    return EXIT_SUCCESS;
}