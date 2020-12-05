#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10

/**
 * 堆空间开辟和使用
 */
int main_m0901() {
    //栈区大小  1M
    //int arr[210000] = {0};

    //开辟堆空间存储数据
    int *p = (int *) malloc(sizeof(int));

    printf("%p\n", p);
    //使用堆空间
    *p = 123;
    printf("%d\n", *p);
    //释放堆空间
    free(p);
    p = NULL;
    //p 野指针
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
    //	printf("程序异常\n");
    //	return -1;
    //}
    return 0;
}


void BubbleSort(int *src, int len);

//练习
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

    //指针叠加 不断改变指针方向，直接释放(free)会出错,所以p-=10就是把指针重新改回开辟空间时的指向地址
    free(p);
    return EXIT_SUCCESS;
}