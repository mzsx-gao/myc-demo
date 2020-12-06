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
            printf("红色\n");
            break;
        case blue:
            printf("蓝色\n");
            break;
        case green:
            printf("绿色\n");
            break;
        case pink:
            printf("粉色\n");
            break;
        case yellow:
            printf("黄色\n");
            break;
        case black:
            printf("黑色\n");
            break;
        case white:
            printf("白色\n");
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
                printf("英雄正在移动中...\n");
                //value = 30;
                break;
            case attack:
                printf("英雄正在攻击中...\n");
                break;
            case skill:
                printf("英雄正在释放技能中...\n");
                break;
            case dance:
                printf("英雄正在跳舞中...\n");
                break;
            case showUI:
                printf("英雄正在显示徽章...\n");
                break;
            case frozen:
                printf("英雄被冰冻中...\n");
                break;
            case dizz:
                printf("英雄被眩晕中...\n");
                break;
            case dath:
                printf("英雄死亡...\n");
                return 0;
                break;
            case moti:
                printf("英雄等待释放命令...\n");
                break;
        }
    }
    return EXIT_SUCCESS;
}