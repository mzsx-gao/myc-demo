#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//����������ʹ��
int add(int a, int b) {
    int sum = a + b;
    return sum;
}

void print() {
    printf("hello world\n");
}

int main_f001() {
    int a = 10;
    int b = 20;
    int c;
    //��������
    c = add(a, b);

    printf("%d\n", c);

    print();
    return EXIT_SUCCESS;
}

void swap(int a, int b) {
    printf("����ǰ���ݣ�\n");
    printf("a=%d\n", a);
    printf("b=%d\n", b);

    int temp = a;
    a = b;
    b = temp;

    printf("���������ݣ�\n");
    printf("a=%d\n", a);
    printf("b=%d\n", b);
}

int main_f002(void) {
    int a = 10;
    int b = 20;
    //��������
    swap(a, b);
    return 0;
}


//#################�ַ����Ƚ�############################
//��������
int my_strcmp(char ch1[], char ch2[]) {
    int i = 0;
    while (ch1[i] == ch2[i]) {
        //�Ƿ��ַ�����β
        if (ch1[i] == '\0') {
            return 0;
        }
        i++;
    }

    return ch1[i] > ch2[i] ? 1 : -1;
}

int main_f003() {

    //�Ƚ������ַ��� �����ͬ����0  �����ͬ���� 1�� -1
    char ch1[] = "hello";
    char ch2[] = "hello";

    int value = my_strcmp(ch1, ch2);
    if (value == 0) {
        printf("�����ַ�����ͬ");
    } else {
        printf("�����ַ�������ͬ");
    }

    return EXIT_SUCCESS;
}


//############������ʽ#################
//�޲κ���
int fun01() {
    return rand() % 10;
}

int main_f004() {
    srand((unsigned int) time(NULL));
    fun01();
    return EXIT_SUCCESS;
}

//ð����������  �вκ���
void BubbleSort(int arr[], int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return;
}

int main_f005(void) {
    int arr[] = {9, 1, 7, 4, 2, 10, 3, 8, 6, 5};
    BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }
    //void  ������
    int a = 10;
    float b = 20.f;
    //void���� ������ֱ�Ӷ�������
    //void���Ϳ�����Ϊ�����ķ���ֵ���� ��ʾû�з���ֵ
    //void c = 30;
    return 0;
}