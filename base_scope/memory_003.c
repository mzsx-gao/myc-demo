#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
 * �ڴ��������
 */

/*
 * void *memset(void *s, int c, size_t n);
    ���ܣ���s���ڴ������ǰn���ֽ��Բ���c����
    ������
        s����Ҫ�����ڴ�s���׵�ַ
        c�������ַ���c��Ȼ����Ϊint����������unsigned char , ��ΧΪ0~255
        n��ָ����Ҫ���õĴ�С
    ����ֵ��s���׵�ַ
 */
int main_1101() {
    int *p = (int *) malloc(sizeof(int) * 10);

    memset(p, 0, sizeof(int) * 10);
    for (int i = 0; i < 10; i++) {
        printf("%d\n", p[i]);
    }

    free(p);
    char ch[10];
    memset(ch, 'A', sizeof(char) * 10);
//    memset(ch, 0, sizeof(char)*10);

    printf("%s\n", ch);
    return EXIT_SUCCESS;
}

/*
 * void *memcpy(void *dest, const void *src, size_t n);
    ���ܣ�����src��ָ���ڴ����ݵ�ǰn���ֽڵ�dest��ֵ���ڴ��ַ�ϡ�
    ������
        dest��Ŀ���ڴ��׵�ַ
        src��Դ�ڴ��׵�ַ��ע�⣺dest��src��ָ���ڴ�ռ䲻���ص������ܻᵼ�³��򱨴�
        n����Ҫ�������ֽ���
    ����ֵ��dest���׵�ַ
 */
int main_1102(void) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = (int *) malloc(sizeof(int) * 10);

    memcpy(p, arr, sizeof(int) * 10);

    for (int i = 0; i < 10; i++) {
        printf("%d\n", p[i]);
    }
    free(p);

    printf("======�ַ�������========\n");
    char ch[] = "hello\0 world";
    char str[100];
    //�ַ�������(strcpy(str, ch))����\0ֹͣ
    //�ڴ濽��  ���������ݺ��ֽ��й�
    memcpy(str, ch, 12);
    printf("%s\n", str);
    for (int i = 0; i < 12; i++) {
        printf("%c", str[i]);
    }
    printf("\n");

    //���������Ŀ���Դ�����ص� ���ܱ���
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    memcpy(&arr2[5], &arr2[3], 20);
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr2[i]);
    }
    return 0;
}

/*
 * memmove()�����÷���memcpy()һ����
 * �������ڣ�dest��src��ָ���ڴ�ռ��ص�ʱ��memmove()��Ȼ�ܴ�������ִ��Ч�ʱ�memcpy()��Щ
 */
int main_1103(void) {
    //�Ա���һ���������һ������(memcpy(&arr2[5], &arr2[3], 20);)
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    memmove(&arr[5], &arr[3], 20);
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
}

/*
 * int memcmp(const void *s1, const void *s2, size_t n);
    ���ܣ��Ƚ�s1��s2��ָ���ڴ������ǰn���ֽ�
    ������
        s1���ڴ��׵�ַ1
        s2���ڴ��׵�ַ2
        n����Ƚϵ�ǰn���ֽ�
    ����ֵ��
        ��ȣ�=0
        ���ڣ�>0
        С�ڣ�<0
 */
int main_1104(void) {
    //int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
    //int arr2[] = { 1,2,3,4,5 };

    char arr1[] = "hello\0 world";
    char arr2[] = "hello\0 world";
    //strcmp();
    int value = memcmp(arr1, arr2, 13);

    printf("%d\n", value);

    return 0;
}