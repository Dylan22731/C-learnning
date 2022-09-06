#include <stdio.h>
#include <string.h>

int MAX(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

int main()
{
    int num1 = 10;
    int num2 = 20;
    int max = 0; 
    max = MAX(num1, num2);
    printf("较大值是:%d\n",max);
    return 0;
 
}


/*
常量
分四种
1字面常量3，100，3.14
2const修饰的常变量const int num = 4,此时num就是常变量，具有常属性的变量
3#difine定义的标识符常量
#include <stdio.h>

#define MAX 10//定义的标识符常量

int main()
{
    int arr[MAX] = {0};
    printf("%d\n", MAX);
    return 0;
}
4枚举常量
一一列举
性别：男，女
三原色：红，黄，蓝
枚举关键enum

#include <stdio.h>
enum Sex
{
    MALE,
    FEMALE,
    SECRET
};
//MALE,FEMALE,SECRET为枚举常量
int main()
{
    //enum Sex s = FEMALE
    printf("%d\n",MALE);//默认值是0
    printf("%d\n", FEMALE);//默认值是1
    printf("%d\n", SECRET);//默认值是2
    return 0;
}

字符串：
由一对双引号括起来的一个字符序列。\0是转义字符，不算做字符串内容。
"abc"--'a' 'b' 'c' '\0'  \0意为字符串的结束标志
转义字符：
\\用于表示一个\，防止被解释成一个转义字符
\'用于表示字符常量'
printf("%c\n",'\'')这样就会打印出一个单独的'
\"用于表示字符串内部的双引号
\n换行
\ddd表示1到3个八进制数字 例如\32是2个八进制的数字，将其转换为十进制的26后，即ASCII码值为26代表的字符
\xdd表示2个十六进制数字\x20
#include <stdio.h>
#include <string.h>
int main()
{
    printf("%d\n", strlen("c:\test\32\test.c"));
    return 0;
}
选择语句
#include <stdio.h>
#include <string.h>
int main()
{
    int input = 0;
    printf("加入比特\n");
    printf("你要好好学习吗？(1/0)>:");
    scanf_s("%d", &input);
    if (input == 0)
        printf("牛逼");
    else
        printf("很弱诶拜托");
    return 0;
}
循环语句
（略后面慢慢学）

函数
#include <stdio.h>
int Add(int x, int y)
{
    int z = x + y;
    return z;
}

int main()
{
    int num1 = 10;
    int num2 = 20;
    int sum = 0;
    sum = Add(num1, num2);
    printf("%d\n", sum);
    return 0;

数组
定义：一组相同元素类型的组合
数组下标默认从零开始
#include <stdio.h>
#include <string.h>
int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};//定义一个存放10个整数数字的数组
    int i = 0;
        while (i<10)
        {
            printf("%d\n", arr[i]);
            i++;
        }
    //printf("%d\n", arr[4]);//数组下标从零开始，所以访问的是第五个值arr[下标]

    return 0;
}

操作符
讲略，后面重点学


作业：求两个数的较大值（函数）
#include <stdio.h>(简单解答)
#include <string.h>
int main()
{
    int num1 = 10;
    int num2 = 20;
    if (num1 > num2)
        printf("较大值是:%d\n",num1);
    else
        printf("较大值是:%d\n",num2);
    return 0;
}
函数解法：
#include <stdio.h>
#include <string.h>

int MAX(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

int main()
{
    int num1 = 10;
    int num2 = 20;
    int max = 0;
    max = MAX(num1, num2);
    printf("较大值是:%d\n",max);
    return 0;

}








*/