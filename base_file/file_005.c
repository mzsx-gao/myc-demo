#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <mem.h>

#define SIZE 1000

int fun1();
int fun2();
int fun3();

/**
 * 大文件排序
 */
int mainfile15() {
    //造数据
    fun1();
    //排序
    fun2();
    //直接插入排序
//    fun3();
    return EXIT_SUCCESS;
}

//造1000个随机数字
int fun1(){
    srand((size_t) time(NULL));
    FILE *fp = fopen("../base_file/filesource/数据.txt", "w");
    if (!fp)
        return -1;
    for (int i = 0; i < 1000; i++) {
        fprintf(fp, "%d\n", rand() % 256);
    }
    fclose(fp);
    return EXIT_SUCCESS;
}

//冒泡排序
void file_BubbleSort(int *src, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (src[j] > src[j + 1]) {
                int temp = src[j];
                src[j] = src[j + 1];
                src[j + 1] = temp;
            }
        }
    }
}

int fun2() {
    FILE *fp1 = fopen("../base_file/filesource/数据.txt", "r");
    FILE *fp2 = fopen("../base_file/filesource/数据冒泡版排序.txt", "w");
    if (!fp1 || !fp2)
        return -1;
    //冒泡版
    int *arr = (int *) malloc(sizeof(int) * SIZE);
    for (int i = 0; i < SIZE; i++) {
        fscanf(fp1, "%d\n", &arr[i]);
    }
    file_BubbleSort(arr, SIZE);

    for (int i = 0; i < SIZE; i++) {
        fprintf(fp2, "%d\n", arr[i]);
    }
    free(arr);
    fclose(fp1);
    fclose(fp2);
    return EXIT_SUCCESS;
}

int fun3(void) {
    FILE *fp1 = fopen("../base_file/filesource/数据.txt", "r");
    FILE *fp2 = fopen("../base_file/filesource/数据插入版排序.txt", "w");
    if (!fp1 || !fp2)
        return -1;
    int *arr = (int *) malloc(sizeof(int) * 256);
    memset(arr, 0, sizeof(int) * 256);
    for (int i = 0; i < 1000; i++) {
        int value;
        fscanf(fp1, "%d\n", &value);
        arr[value]++;//将数据的个数放在对应的下标里面
    }
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < arr[i]; j++) {
            fprintf(fp2, "%d\n", i);
        }
    }
    free(arr);
    fclose(fp1);
    fclose(fp2);
    return 0;
}
