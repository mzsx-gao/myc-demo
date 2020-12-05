#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
 * 结构体嵌套结构体
 */
struct scores {
    int cl;//c语言
    int cpp;//C++
    int cs;//C#
};

typedef struct student stu;
struct student {
    char name[21];
    int age;
    struct scores ss;
    char addr[51];
};


int main_stu06(void) {
    //struct student stu;
    stu s;
    printf("学生结构体大小：%d\n", sizeof(stu));
    printf("成绩结构体大小：%d\n", sizeof(s.ss));
    printf("名称数组大小：%d\n", sizeof(s.name));
}

int main_stu07() {
    //struct student stu = { "貂蝉",18,99,99,99,"徐州" };

    struct student stu;
    strcpy(stu.name, "小乔");
    stu.age = 20;
    stu.ss.cl = 88;
    stu.ss.cpp = 88;
    stu.ss.cs = 88;
    strcpy(stu.addr, "江东");

    printf("%s\n%d\n%d\n%d\n%d\n%s\n",
           stu.name, stu.age, stu.ss.cl, stu.ss.cpp, stu.ss.cs, stu.addr);

    return EXIT_SUCCESS;
}

/*
 * 结构体赋值
 */
struct student2 {
    char name[21];
    //char *name;
    int age;
    int score;
    char addr[51];
};

int main_stu08() {
    struct student2 stu = {"孙尚香", 26, 60, "巴蜀"};
    struct student2 s1 = stu;

    //深拷贝和浅拷贝
    strcpy(s1.name, "甘夫人");
    s1.age = 28;
    s1.score = 80;

    //对s1的赋值不会影响到stu的值，两者是两个独立的内存空间
    printf("%s\n", stu.name);
    printf("%d\n", stu.age);
    printf("%d\n", stu.score);

    return EXIT_SUCCESS;
}