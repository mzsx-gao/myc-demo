#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

/*
 * �ڴ泣������
 */

//�����±�Խ��
int main_mem002() {

    char *p = (char *) malloc(sizeof(char) * 11);
    strcpy(p, "hello world");

    printf("%s\n", p);
    free(p);
    return EXIT_SUCCESS;
}

int main_mem003(void) {
    //Ұָ��
    //int* p = (int*)malloc(0);
    //���ٿռ�����Ͷ�Ӧ
//    int *p = (int *) malloc(10);
    int *p = (int *) malloc(sizeof(int) * 10);
    //ʹ�öѿռ�
    p[0] = 123;
    p[1] = 456;
    p[2] = 789;
    printf("%p\n", p);
    //*p = 100;
    printf("%d\n", *p);
    printf("%d\n", *(p + 1));
    printf("%d\n", *(p + 2));
    //�ͷŶѿռ�
    free(p);
    return 0;
}

int main_mem004(void) {
    int *p = (int *) malloc(sizeof(int) * 10);
    int *temp = p;
    for (int i = 0; i < 10; i++) {
        *p = i;
        //ָ����� ���ϸı�ָ�뷽�� �ͷŻ����
//        p++;
    }
    free(p);//�ѿռ䲻�������ͷ�
    p = NULL;
    free(p);//��ָ���������ͷ�

    return 0;
}

void fun08(int *p) {
    p = (int *) malloc(sizeof(int) * 10);
    printf("�βΣ�%p\n", p);
}

void fun09(int **p) {
    *p = (int *) malloc(sizeof(int) * 10);
    printf("�βΣ�%p\n", *p);
}

//����ֵ
int *fun10() {
    int *p = (int *) malloc(sizeof(int) * 10);
    return p;
}

int main_mem005(void) {
    int *p = NULL;
    //ֵ����
//    fun08(p);
//    printf("ʵ�Σ�%p\n", p);

    //��ַ����
//    fun09(&p);
//    printf("ʵ�Σ�%p\n", p);

    //����ֵ��ʽ
    p = fun10();
    printf("ʵ�Σ�%p\n", p);

    for (int i = 0; i < 10; i++) {
        p[i] = i;
    }
    for (int i = 0; i < 10; i++) {
        printf("%d\n", p[i]);
    }
    free(p);
    return 0;
}


//���ٶѿռ�洢��ά����  ָ������
int main_mem006() {
    //int arr[5][3]
    //���ٶ���ָ���Ӧ�Ķѿռ�
    int **p = (int **) file070(sizeof(int *) * 5);

    for (int i = 0; i < 5; i++) {
        //����һ��ָ���Ӧ�Ķѿռ�
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
