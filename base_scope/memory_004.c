#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

/*
 * 内存常见问题
 */

//数组下标越界
int main_mem002() {

    char *p = (char *) malloc(sizeof(char) * 11);
    strcpy(p, "hello world");

    printf("%s\n", p);
    free(p);
    return EXIT_SUCCESS;
}

int main_mem003(void) {
    //野指针
    //int* p = (int*)malloc(0);
    //开辟空间和类型对应
//    int *p = (int *) malloc(10);
    int *p = (int *) malloc(sizeof(int) * 10);
    //使用堆空间
    p[0] = 123;
    p[1] = 456;
    p[2] = 789;
    printf("%p\n", p);
    //*p = 100;
    printf("%d\n", *p);
    printf("%d\n", *(p + 1));
    printf("%d\n", *(p + 2));
    //释放堆空间
    free(p);
    return 0;
}

int main_mem004(void) {
    int *p = (int *) malloc(sizeof(int) * 10);
    int *temp = p;
    for (int i = 0; i < 10; i++) {
        *p = i;
        //指针叠加 不断改变指针方向 释放会出错
//        p++;
    }
    free(p);//堆空间不允许多次释放
    p = NULL;
    free(p);//空指针允许多次释放

    return 0;
}

void fun08(int *p) {
    p = (int *) malloc(sizeof(int) * 10);
    printf("形参：%p\n", p);
}

void fun09(int **p) {
    *p = (int *) malloc(sizeof(int) * 10);
    printf("形参：%p\n", *p);
}

//返回值
int *fun10() {
    int *p = (int *) malloc(sizeof(int) * 10);
    return p;
}

int main_mem005(void) {
    int *p = NULL;
    //值传递
//    fun08(p);
//    printf("实参：%p\n", p);

    //地址传递
//    fun09(&p);
//    printf("实参：%p\n", p);

    //返回值方式
    p = fun10();
    printf("实参：%p\n", p);

    for (int i = 0; i < 10; i++) {
        p[i] = i;
    }
    for (int i = 0; i < 10; i++) {
        printf("%d\n", p[i]);
    }
    free(p);
    return 0;
}


//开辟堆空间存储二维数组  指针数组
int main_mem006() {
    //int arr[5][3]
    //开辟二级指针对应的堆空间
    int **p = (int **) file070(sizeof(int *) * 5);

    for (int i = 0; i < 5; i++) {
        //开辟一级指针对应的堆空间
        p[i] = (int *) malloc(sizeof(int) * 3);
    }


    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &p[i][j]);
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", p[i][j]);
            //printf("%d ", *(p[i] + j));
            //printf("%d ", *(*(p + i) + j));
        }
        printf("\n");
    }


    for (int i = 0; i < 5; i++) {
        free(p[i]);
    }
    free(p);

    return EXIT_SUCCESS;
}
