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

int main(void) {
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