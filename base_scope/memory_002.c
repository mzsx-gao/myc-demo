#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10

/**
 * �ѿռ俪�ٺ�ʹ��
 */
int main_m0901() {
    //ջ����С  1M
    //int arr[210000] = {0};

    //���ٶѿռ�洢����
    int *p = (int *) malloc(sizeof(int));

    printf("%p\n", p);
    //ʹ�öѿռ�
    *p = 123;
    printf("%d\n", *p);
    //�ͷŶѿռ�
    free(p);
    p = NULL;
    //p Ұָ��
    //printf("%p\n", p);
    //*p = 456;
    //printf("%d\n", *p);

    return EXIT_SUCCESS;
}

int main_m0902(void) {
    //int* p = (int*)malloc(sizeof(int) * 8200000*66);
    //printf("%p\n", p);

    //free(p);
    int *p = (int *) malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++) {
        p[i] = i;
    }
    for (int i = 0; i < 10; i++) {
        printf("%d\n", *(p + i));
    }

    free(p);
    //if (!p)
    //{
    //	printf("�����쳣\n");
    //	return -1;
    //}
    return 0;
}


void BubbleSort(int *src, int len);

//��ϰ
int main_m0903() {
    srand((size_t) time(NULL));

    int *p = (int *) malloc(sizeof(int) * MAX);

    printf("%p\n", p);
    for (int i = 0; i < MAX; i++) {
        p[i] = rand() % 100;
        printf("%d ", p[i]);
    }
    printf("\n");
    BubbleSort(p, MAX);

    for (int i = 0; i < MAX; i++) {
        //printf("%d\n", p[i]);
        printf("%d\n", *p);
        p++;
    }
    printf("%p\n", p);
    p -= 10;
    printf("%p\n", p);

    //ָ����� ���ϸı�ָ�뷽��ֱ���ͷ�(free)�����,����p-=10���ǰ�ָ�����¸Ļؿ��ٿռ�ʱ��ָ���ַ
    free(p);
    return EXIT_SUCCESS;
}