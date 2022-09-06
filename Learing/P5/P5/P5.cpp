#include<stdio.h>

struct Book
{
    char name[20];
    short price;
};

int main()
{
    struct Book b1 = { "c语言程序设计",55 };
    struct Book* pb = &b1;


    printf("书名：%s\n", pb->name);
    printf("价格：%d\n", pb->price);
    return 0;
}

/*
结构体:用于描述复杂对象

#include<stdio.h>

struct Book
{
    char name[20];//用于书名
    short price;//用于价格
};

int main()
{
    struct Book b1 = { "c语言程序设计",55 };
    printf("书名：%s\n", b1.name);
    printf("价格：%d\n", b1.price);
    b1.price = 15;
    printf("折扣价：%d\n", b1.price);
    return 0;
}

利用指针变量来打印
#include<stdio.h>

struct Book
{
    char name[20];
    short price;
};

int main()
{
    struct Book b1 = { "c语言程序设计",55 };
    struct Book* pb = &b1;


    printf("书名：%s\n", pb->name);
    printf("价格：%d\n", pb->price);
    return 0;
}

总结
.用于结构体变量  成员
->用于结构体指针  成员
















*/