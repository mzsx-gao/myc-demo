#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

/*
 * 结构体与函数
 */
typedef struct student ss;
struct student {
    char name[21];
//    char *name;
    int age;
    int score[3];
    char addr[51];
};

void stu_fun01(ss stu1) {
//    stu1.name = (char*)malloc(sizeof(char)*21);
    strcpy(stu1.name, "卢俊义");
    printf("形参:%s\n", stu1.name);
}

int main_stu12() {
    ss stu = {NULL, 50, 101, "水泊梁山"};
    // 注意当student的name是指针变量时，放开下面一行，此时形参和实参一样;
    // 如果想不一样，放开stu_fun01函数的第一行
//    stu.name = (char*)malloc(sizeof(char) * 21);
    strcpy(stu.name, "宋江");
    stu_fun01(stu);
    printf("实参:%s\n", stu.name);
    return EXIT_SUCCESS;
}


/*
 * 结构体指针作为函数参数,地址传递
 */
void stu_fun02(ss *p) {
    strcpy(p->name, "公孙胜");
    printf("%s\n", p->name);
}

int main_stu13(void) {
    ss stu = {"吴用", 50, 101, "水泊梁山"};
    stu_fun02(&stu);
    printf("%s\n", stu.name);
    return 0;
}

//数组作为函数参数退化为指针 丢失元素精度 需要传递个数
void stu_BubbleSort(ss *stu, int len) {
    printf("%d\n", sizeof(stu));//指针变量，32位操作系统4个字节，64位操作系统8个字节
    for (int i = 0; i < len - 1; i++)
        for (int j = 0; j < len - i - 1; j++) {
            //if (stu[j].age>stu[j + 1].age)
            if ((stu + j)->age > (stu + j + 1)->age) {
                ss temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
}

int main_stu14(void) {
    ss stu[3] = {
            {"鲁智深", 30, 33, 33, 33, "五台山"},
            {"呼延灼", 45, 44, 44, 44, "汴京"},
            {"顾大嫂", 28, 33, 33, 33, "汴京"},
    };
    stu_BubbleSort(stu, 3);
    for (int i = 0; i < 3; i++) {
        printf("姓名：%s\n", stu[i].name);
        printf("年龄：%d\n", stu[i].age);
        printf("成绩1：%d\n", stu[i].score[0]);
        printf("成绩2：%d\n", stu[i].score[1]);
        printf("成绩3：%d\n", stu[i].score[2]);
        printf("地址：%s\n", stu[i].addr);
    }
}


/*
 * const 修饰结构体指针
 */
//const修饰结构体指针类型
int main_stu15() {
    ss stu1 = {"孙悟空", 700, 101, 101, 101, "花果山"};
    ss stu2 = {"猪八戒", 1200, 1000, 1000, 1000, "高老庄"};

    const ss *p = &stu1;
    p = &stu2;//OK 可以修改结构体指针变量的值，不能修改结构体指针对应内存空间的值
    //p->age = 888;//err
    //(*p).age = 888;//err

    return EXIT_SUCCESS;
}

//const 修饰结构体指针变量,不能修改指针的指向
int main_stu16(void) {
    ss stu1 = {"孙悟空", 700, 101, 101, 101, "花果山"};
    ss stu2 = {"猪八戒", 1200, 1000, 1000, 1000, "高老庄"};

    ss *const p = &stu1;
    //p = &stu2;//err，不能修改指针的指向
    p->age = 888;
    strcpy(p->name, "沙悟净");
    printf("%s\n",stu1.name);
}


int main_stu17(void) {
    ss stu1 = {"孙悟空", 700, 101, 101, 101, "花果山"};
    ss stu2 = {"猪八戒", 1200, 1000, 1000, 1000, "高老庄"};

    //const 修饰结构体指针类型
    //const 修饰结构体指针变量
    const ss *const p = &stu1;
    //p = &stu2;//err;
    //p->age = 888;//err
    ss **pp = &p;

    //*pp = &stu2;
    (*pp)->age = 888;
    (**pp).age = 888;
}