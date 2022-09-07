#include <stdio.h>

typedef struct stu 
{
    char name[20];
    short age;
    char sex[5];
}stu;

void printf1(stu tmp)
{
    printf("%s\n", tmp.name);
    printf("%d\n", tmp.age);
    printf("%s\n", tmp.sex);
}

void printf2(stu* ps1)
{
    printf("%s\n", ps1->name);
    printf("%d\n", ps1->age);
    printf("%s\n", ps1->sex);
}

int main()
{
    stu s1 = { "颜欣怡",21,"女" };
    printf1(s1);
    printf2(&s1);
    return 0;
}

/*
1. 结构体的声明
1.1 结构的基础知识
结构是一些值的集合，这些值称为成员变量。结构的每个成员可以是不同类型的变量。
1.2 结构的声明
struct tag
{
 member-list;
}variable-list;
例如描述一个学生：
#include <stdio.h>

struct stu //struct结构体关键字  stu结构体标签  struct stu结构体类型
{
    int age;
    char id[10];//成员变量
}s1,s2;//全局结构体变量
int main()
{
    struct stu s;//局部结构体变量
    return 0;
}

typedef struct stu //typedef将struct stu类型命名为stu（改名作用）
{
    int age;
    char id[10] ;
}stu;//
int main()
{
    struct stu s;
    stu s1;
    return 0;
}

1.3 结构成员的类型
结构的成员可以是标量、数组、指针，甚至是其他结构体。

1.4 结构体变量的定义和初始化
有了结构体类型，那如何定义变量，其实很简单。
typedef struct stu //struct结构体关键字  stu结构体标签  struct stu结构体类型
{
    char name[20];
    int age;
    char id[12] ;//成员变量
}stu;//全局结构体变量
int main()
{
    struct stu s={"张三",81,"2019113050"};//局部结构体变量初始化
    stu s1;
    return 0;
}

1.31.4复合例子
#include <stdio.h>
struct S
{
    int a;
    char b[20];
    double c;
};

struct T
{
    char ch[20];
    struct S s;
    char* pc;
}stu;
int main()
{
    char arr[] = "niubility";
    struct T t = { "niubility",{10,"hehe",3.1415926},arr};
    printf("%s", t.s.b);//hehe
    printf("%s", t.pc);//niubility
    return 0;
}


2. 结构体成员的访问

结构体变量访问成员
结构变量的成员是通过点操作符（.）访问的。点操作符接受两个操作数。

结构体指针访问指向变量的成员
有时候我们得到的不是一个结构体变量，而是指向一个结构体的指针。


3. 结构体传参
直接上代码：
#include <stdio.h>

typedef struct stu
{
    char name[20];
    short age;
    char sex[5];
}stu;

void printf1(stu tmp)
{
    printf("%s\n", tmp.name);
    printf("%d\n", tmp.age);
    printf("%s\n", tmp.sex);
}

void printf2(stu* ps1)
{
    printf("%s\n", ps1->name);
    printf("%d\n", ps1->age);
    printf("%s\n", ps1->sex);
}

int main()
{
    stu s1 = { "颜欣怡",21,"女" };
    printf1(s1);
    printf2(&s1);
    return 0;
}
 
答案是：首选print2函数。
原因：形参是实参的临时拷贝，需要开辟跟实参一样大小的内存空间。如果用指针，就会减小内存空间的占用。
函数传参的时候，参数是需要压栈的。如果传递一个结构体对象的时候，结构体过大，参数压栈的的系统开销比较大，所以会导致性能的下降。









*/