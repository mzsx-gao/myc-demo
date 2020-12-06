#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
 * 结构体与指针
 */
//结构体成员为指针类型
struct student {
    char *name;
    int age;
    int *scores;
    char *addr;
};

int main_stu09() {

    struct student stu;
    //stu.name = "张三";
    stu.name = (char *) malloc(sizeof(char) * 21);
    stu.scores = (int *) malloc(sizeof(int) * 3);
    stu.addr = (char *) malloc(sizeof(char) * 51);
    strcpy(stu.name, "张三");
    stu.age = 18;
    stu.scores[0] = 88;
    stu.scores[1] = 99;
    stu.scores[2] = 100;
    strcpy(stu.addr, "北京市");

    printf("%s\n", stu.name);
    printf("%d\n", stu.age);
    printf("%d\n", stu.scores[0]);
    printf("%d\n", stu.scores[1]);
    printf("%d\n", stu.scores[2]);
    printf("%s\n", stu.addr);

    free(stu.name);
    free(stu.scores);
    free(stu.addr);

    return EXIT_SUCCESS;
}

struct stu {
    char name[21];
    int age;
    int scores[3];
    char addr[51];
};

//结构体指针
int main_stu10(void) {
    struct stu ss = {"林冲", 30, 100, 100, 100, "汴京"};
    struct stu *p = &ss;
    printf("%s\n", (*p).name);
    printf("%d\n", (*p).age);

    //结构体指针->成员
    //结构体变量.成员
    printf("%s\n", p->name);
    printf("%d\n", p->age);
    printf("%d\n", p->scores[0]);
    printf("%d\n", p->scores[1]);
    printf("%d\n", p->scores[2]);
    printf("%s\n", p->addr);

    return 0;
}


//通过结构体指针操作堆空间
typedef struct student ss;
int main_stu11() {
    ss *p = (ss *) malloc(sizeof(ss) * 3);

    for (int i = 0; i < 3; i++) {
        //(p + i)->name;
        p[i].name = (char *) malloc(sizeof(char) * 21);
        p[i].scores = (int *) malloc(sizeof(int) * 3);
        p[i].addr = (char *) malloc(sizeof(char) * 51);
    }

    for (int i = 0; i < 3; i++) {
        scanf("%s%d%d%d%d%s", p[i].name, &p[i].age, &p[i].scores[0],
              &p[i].scores[1], &p[i].scores[2], p[i].addr);
    }

    for (int i = 0; i < 3; i++) {
        printf("%s ", p[i].name);
        printf("%d ", p[i].age);
        printf("%d ", p[i].scores[0]);
        printf("%d ", (p + i)->scores[1]);
        printf("%d ", (p + i)->scores[2]);
        printf("%s\n", (p + i)->addr);
    }
    //释放堆空间
    for (int i = 0; i < 3; i++) {
        free(p[i].name);
        free(p[i].scores);
        free(p[i].addr);
    }
    free(p);
    return EXIT_SUCCESS;
}