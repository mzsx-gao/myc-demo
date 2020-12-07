#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
 * 文件打开与关闭
 */
int main_file01() {
    FILE *fp = fopen("D:/a.txt", "r");
    //1、找不到文件
    //2、文件权限（读 写 执行）
    //3、程序打开文件超出上限 65535
    if (fp == NULL) {
        printf("打开文件失败\n");
        return -1;
    }
    //fp为文件指针
    printf("文件打开成功:%p\n", fp);

    fclose(fp);
    return EXIT_SUCCESS;
}

/*
 * 文件字符读写
 */
int main_file02() {
    FILE *fp = fopen("../base_file/filesource/a.txt", "r");
    if (!fp) {
        printf("文件打开失败\n");
        return -1;
    }
    char ch;
    //文件的字符读取
    //文件默认结尾为-1
    ch = fgetc(fp);
    printf("%c\n", ch);
    //不能修改文件指针  文件在读取时光标流会自动向下移动
    //fp++;//err
    ch = fgetc(fp);
    printf("%c\n", ch);
    //关闭文件
    fclose(fp);

    return EXIT_SUCCESS;
}

/*
 * EOF表示文件结束符(end of file)。在while循环中以EOF作为文件结束标志，
 * 这种以EOF作为文件结束标志的文件，必须是文本文件。在文本文件中，数据都是以字符的ASCII代码值的形式存放。
 * 我们知道，ASCII代码值的范围是0~127，不可能出现-1，因此可以用EOF作为文件结束标志
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

//文件字符写入
int main_file04(void) {
    //以写的方式打开文件 如果文件不存会创建一个新文件  如果文件存在 会清空内容
    FILE *fp = fopen("../base_file/filesource/b.txt", "w");
    if (!fp)
        return -1;
    char ch = 'b';
    //字符写入
    fputc(ch, fp);
    fclose(fp);
    return 0;
}

int main_file05(void) {
    FILE *fp = fopen("../base_file/filesource/c.txt", "w");
    if (!fp) {
        printf("文件打开失败\n");
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
 * 简单的加密解密
 */
//加密
int main_file06() {
    FILE *fp1 = fopen("../base_file/filesource/解密.txt", "r");
    FILE *fp2 = fopen("../base_file/filesource/加密.txt", "w");
    if (!fp1 || !fp2) {
        return -1;
    }
    char ch;
    while ((ch = fgetc(fp1)) != EOF) {
        //加密
        ch++;
        fputc(ch, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    return EXIT_SUCCESS;
}
//解密
int main_file07(void) {
    FILE *fp1 = fopen("../base_file/filesource/加密.txt", "r");
    FILE *fp2 = fopen("../base_file/filesource/解密.txt", "w");
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