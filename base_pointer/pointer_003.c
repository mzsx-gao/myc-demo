#include<stdio.h>
#include<stdlib.h>

/**
 * ָ������
 */
//��һ�ַ�ʽ
void my_strcpy01(char *dest, char *ch) {
    int i = 0;
    //while (ch[i] != '\0');
    //while (ch[i] != 0);
    while (ch[i]) {
        dest[i] = ch[i];
        i++;
    }
    dest[i] = 0;
}

//�ڶ��ַ�ʽ���� *(ch + i) ����ͬ�ڡ� ch[i] ��
void my_strcpy02(char *dest, char *ch) {
    int i = 0;
    while (*(ch + i)) {
        *(dest + i) = *(ch + i);
        i++;
    }
    *(dest + i) = 0;
}

//�����ַ�ʽ
void my_strcpy03(char *dest, char *ch) {
    while (*ch) {
        *dest = *ch;//*ch�����������Ԫ��
        dest++;//ָ��+1  �൱��ָ��������һ��Ԫ��  �ڴ��ַ�仯��sizeof(char)
        ch++;
    }
    *dest = 0;
}

//�����ַ�ʽ
void my_strcpy(char *dest, char *ch) {
    while (*dest++ = *ch++);
}

//�ַ�������
int main0201() {
    char ch[] = "hello world";
    char dest[100];

    my_strcpy(dest, ch);
    printf("%s\n", dest);
    printf("%p", dest);
    return EXIT_SUCCESS;
}

//ָ���������
int main0202(void) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = &arr[3];
    printf("ָ��p��ַ:%p\n", p);
    //p--;//ָ��ļӼ������ָ��������й�
    //p--;
    //p--;
    //�ڴ��ַ�����12,Ȼ�����sizeof(int) = ƫ����
    int step = p - arr;
    printf("%p\n", p);
    printf("%p\n", arr);
    printf("p��arr�������%d��Ԫ��\n", step);

    //ָ���������ʱ�±������Ǹ���
    printf("p[-2]��ֵ:%d\n", p[-2]);//*(p-2);
    return 0;
}

int main0203(void) {
    //ָ���������Ĳ���
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = arr;
    p = &arr[3];
    //Ұָ��
    //p = p + arr;//err
    //p = p*arr;//err
    //p = p*4;//err
    //p = p / arr;
    //int len = p % 4;//err

    if (p > arr) {
        printf("��\n");
    }
    if (p || arr) {

    }
    return 0;
}

/**
 * ָ������
 */
int main0301() {

    //��������  ��������  ������[Ԫ�ظ���] ={ֵ1,ֵ2}
    //����ָ������
    int a = 10;
    int b = 20;
    int c = 30;
    int *arr[3] = {&a, &b, &c};
    //arr[0] arr[1] arr[2]
    //printf("%d\n", *arr[0]);
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d\n", *arr[i]);
    }

    printf("ָ�������С��%d\n", sizeof(arr));
    printf("ָ��Ԫ�ش�С��%d\n", sizeof(arr[0]));
    return EXIT_SUCCESS;
}

int main0302(void) {
    //ָ����������Ԫ�ش洢����ָ��
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    int c[] = {7, 8, 9};
    //ָ��������һ������Ķ�ά����ģ��
    //ָ�������Ӧ�ڶ���ָ��
    int *arr[] = {a, b, c};

    //arr��ָ��������׵�ַ
    printf("%p\n", arr);
    printf("%p\n", &arr[0]);

    printf("=======================\n");
    printf("%d\n", arr[0][1]);
    printf("%p\n", arr[0]);
    printf("%p\n", a);//a[1]
    printf("%p\n", &a[0]);//a[1]

    printf("=======================\n");
    for (int i = 0; i < 3; i++) {
        printf("%d\n", *arr[i]);
    }

    printf("=======================\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            //��ά����
            //printf("%d ", arr[i][j]);
            //printf("%d ", *(arr[i] + j));
            printf("%d ", *(*(arr + i) + j));
        }
        puts("");
    }
    return 0;
}

//�༶ָ��
int main0303() {

    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    int c[] = {7, 8, 9};
    //ָ��������һ������Ķ�ά����ģ��
    //ָ�������Ӧ�ڶ���ָ��
    int *arr[] = {a, b, c};

    //ָ������Ͷ���ָ�뽨����ϵ
    int **p = arr;

    printf("����ָ��%d\n", **p);
    //����ָ���ƫ���� �൱��������һ��һά�����С
    printf("%d\n", **(p + 1));//arr[1][0]
    //һ��ָ���ƫ���� �൱��������һ��Ԫ��
    printf("%d\n", *(*p + 1));//arr[0][1]

    printf("%d\n", *(*(p + 1) + 1));//arr[1][1]

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            //printf("%d ", p[i][j]);
            //printf("%d ", *(p[i] + j));
            printf("%d ", *(*(p + i) + j));
        }
        puts("");
    }
    return EXIT_SUCCESS;
}

//����ָ�����һ��ָ��ĵ�ַ������ָ���*����һ��ָ���ֵ����**���ڱ�����ֵ
int main0304(void) {
    int a = 10;
    int *p = &a;
    int **pp = &p;
    int ***ppp = &pp;

    //*pp = 100;//err
    //*pp = &b;//�ȼ���p=&b;
    **pp = 100;

    printf("%d\n", *p);
    printf("%d\n", a);
    return 0;
}