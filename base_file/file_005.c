#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <mem.h>

#define SIZE 1000

int fun1();
int fun2();
int fun3();

/**
 * ���ļ�����
 */
int mainfile15() {
    //������
    fun1();
    //����
    fun2();
    //ֱ�Ӳ�������
//    fun3();
    return EXIT_SUCCESS;
}

//��1000���������
int fun1(){
    srand((size_t) time(NULL));
    FILE *fp = fopen("../base_file/filesource/����.txt", "w");
    if (!fp)
        return -1;
    for (int i = 0; i < 1000; i++) {
        fprintf(fp, "%d\n", rand() % 256);
    }
    fclose(fp);
    return EXIT_SUCCESS;
}

//ð������
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
    FILE *fp1 = fopen("../base_file/filesource/����.txt", "r");
    FILE *fp2 = fopen("../base_file/filesource/����ð�ݰ�����.txt", "w");
    if (!fp1 || !fp2)
        return -1;
    //ð�ݰ�
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
    FILE *fp1 = fopen("../base_file/filesource/����.txt", "r");
    FILE *fp2 = fopen("../base_file/filesource/���ݲ��������.txt", "w");
    if (!fp1 || !fp2)
        return -1;
    int *arr = (int *) malloc(sizeof(int) * 256);
    memset(arr, 0, sizeof(int) * 256);
    for (int i = 0; i < 1000; i++) {
        int value;
        fscanf(fp1, "%d\n", &value);
        arr[value]++;//�����ݵĸ������ڶ�Ӧ���±�����
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
