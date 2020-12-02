#include<stdio.h>
#include<stdlib.h>

/**
 * 指针运算
 */
//第一种方式
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

//第二种方式：“ *(ch + i) ”等同于“ ch[i] ”
void my_strcpy02(char *dest, char *ch) {
    int i = 0;
    while (*(ch + i)) {
        *(dest + i) = *(ch + i);
        i++;
    }
    *(dest + i) = 0;
}

//第三种方式
void my_strcpy03(char *dest, char *ch) {
    while (*ch) {
        *dest = *ch;//*ch就是数组的首元素
        dest++;//指针+1  相当于指向数组下一个元素  内存地址变化了sizeof(char)
        ch++;
    }
    *dest = 0;
}

//第四种方式
void my_strcpy(char *dest, char *ch) {
    while (*dest++ = *ch++);
}

//字符串拷贝
int main0201() {
    char ch[] = "hello world";
    char dest[100];

    my_strcpy(dest, ch);
    printf("%s\n", dest);
    printf("%p", dest);
    return EXIT_SUCCESS;
}

//指针减法运算
int main0202(void) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = &arr[3];
    printf("指针p地址:%p\n", p);
    //p--;//指针的加减运算和指针的类型有关
    //p--;
    //p--;
    //内存地址相差是12,然后除以sizeof(int) = 偏移量
    int step = p - arr;
    printf("%p\n", p);
    printf("%p\n", arr);
    printf("p与arr两者相差%d个元素\n", step);

    //指针操作数组时下标允许是负数
    printf("p[-2]的值:%d\n", p[-2]);//*(p-2);
    return 0;
}

int main0203(void) {
    //指针和运算符的操作
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = arr;
    p = &arr[3];
    //野指针
    //p = p + arr;//err
    //p = p*arr;//err
    //p = p*4;//err
    //p = p / arr;
    //int len = p % 4;//err

    if (p > arr) {
        printf("真\n");
    }
    if (p || arr) {

    }
    return 0;
}

/**
 * 指针数组
 */
int main0301() {

    //定义数组  数据类型  数据名[元素个数] ={值1,值2}
    //定义指针数组
    int a = 10;
    int b = 20;
    int c = 30;
    int *arr[3] = {&a, &b, &c};
    //arr[0] arr[1] arr[2]
    //printf("%d\n", *arr[0]);
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d\n", *arr[i]);
    }

    printf("指针数组大小：%d\n", sizeof(arr));
    printf("指针元素大小：%d\n", sizeof(arr[0]));
    return EXIT_SUCCESS;
}

int main0302(void) {
    //指针数组里面元素存储的是指针
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    int c[] = {7, 8, 9};
    //指针数组是一个特殊的二维数组模型
    //指针数组对应于二级指针
    int *arr[] = {a, b, c};

    //arr是指针数组的首地址
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
            //二维数组
            //printf("%d ", arr[i][j]);
            //printf("%d ", *(arr[i] + j));
            printf("%d ", *(*(arr + i) + j));
        }
        puts("");
    }
    return 0;
}

//多级指针
int main0303() {

    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    int c[] = {7, 8, 9};
    //指针数组是一个特殊的二维数组模型
    //指针数组对应于二级指针
    int *arr[] = {a, b, c};

    //指针数组和二级指针建立关系
    int **p = arr;

    printf("二级指针%d\n", **p);
    //二级指针加偏移量 相当于跳过了一个一维数组大小
    printf("%d\n", **(p + 1));//arr[1][0]
    //一级指针加偏移量 相当于跳过了一个元素
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

//二级指针等于一级指针的地址，二级指针加*等于一级指针的值，加**等于变量的值
int main0304(void) {
    int a = 10;
    int *p = &a;
    int **pp = &p;
    int ***ppp = &pp;

    //*pp = 100;//err
    //*pp = &b;//等价于p=&b;
    **pp = 100;

    printf("%d\n", *p);
    printf("%d\n", a);
    return 0;
}