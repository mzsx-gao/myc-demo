#include<stdio.h>
#include<stdlib.h>

enum Color {
    red = 10, blue, green, pink, yellow = 20, black, white
};

int main_enum1() {
    int value;
    scanf("%d", &value);
    switch (value) {
        case red:
            printf("��ɫ\n");
            break;
        case blue:
            printf("��ɫ\n");
            break;
        case green:
            printf("��ɫ\n");
            break;
        case pink:
            printf("��ɫ\n");
            break;
        case yellow:
            printf("��ɫ\n");
            break;
        case black:
            printf("��ɫ\n");
            break;
        case white:
            printf("��ɫ\n");
            break;
        default:
            break;
    }
    return EXIT_SUCCESS;
}

enum TYPE {
    run, attack, skill, dance = 10, showUI, frozen = 20, dizz, dath, moti = 30
};

int main_enum2() {
    int value;
    while (1) {
        scanf("%d", &value);
        switch (value) {
            case run:
                printf("Ӣ�������ƶ���...\n");
                //value = 30;
                break;
            case attack:
                printf("Ӣ�����ڹ�����...\n");
                break;
            case skill:
                printf("Ӣ�������ͷż�����...\n");
                break;
            case dance:
                printf("Ӣ������������...\n");
                break;
            case showUI:
                printf("Ӣ��������ʾ����...\n");
                break;
            case frozen:
                printf("Ӣ�۱�������...\n");
                break;
            case dizz:
                printf("Ӣ�۱�ѣ����...\n");
                break;
            case dath:
                printf("Ӣ������...\n");
                return 0;
                break;
            case moti:
                printf("Ӣ�۵ȴ��ͷ�����...\n");
                break;
        }
    }
    return EXIT_SUCCESS;
}