#include <stdio.h>
int main()
{
    int i = 0;
    double j = 0;
    double sum = 0;
    int flag = 1;
    for (i = 1; i <= 100; i++)
    {
        j=1.0 / i;//注意1.0是为了让整个1.0/i这个式子变成浮点数数据格式，不如小数计算不出来
        sum = sum +flag* j;
        flag = -flag;
    }
    printf("%lf\n", sum);
    return 0;
}

/*
分支语句与循环语句
分支语句：if   switch
循环语句: while   for    do while

分支语句

if分支语句语法
if(表达式1)
    语句1；
else if(表达式2)可以XN
    语句2；
else//注意这里是没有表达式的哦
    语句3；

#include <stdio.h>

int main()
{
    int age = 10;
    if (age < 18)
        printf("未成年\n");
    else if (age >= 18 && age < 28)//为什么不写(18<=age<28),因为运行顺序会是10小于18，结果为假，那么结果为0，此时0小于28，所以会打印青年。
        printf("青年\n");
    else
        printf("成年\n");
    return 0;

}

{}就是一个代码块

else悬空用法
#include <stdio.h>

int main()
{
    int a = 10;
    int b = 20;
    if (a==30)
        if(a==20)
            printf("haha\n");
        else
            printf("whoa\n");
    return 0;
    //此时不会打印任何东西，因为if语句嵌套于第一个if，而第一个if不成立
    else与最近的if匹配
}

=为赋值/==判断相等/!=判断不相等
if(5==num)//判断时，将常量写在变量前是好的代码风格，有助于识别错误。

练习1：判断一个数是否为奇数
练习2:输出1-100之间的奇数
结合做，需要利用while
#include <stdio.h>

int main()
{
    int i = 0;
    while (i<=1000)
    {
        if (i % 2 == 1)
            printf("%d ", i);
        i++;
    }
    return 0;
}

Switch分支语句：适用于多分支

#include <stdio.h>

int main()
{
    int day = 0;//需要整型表达式，所以将数据设置为整型
    scanf_s(" % d", &day);
    switch (day)//(整型表达式)
    {
    case 1://case后只能跟整型！表达式
        //if(表达式)
            //printf("内容")          switch语句与if、switch可以嵌套
        printf("星期一\n");
        break;
    case 2:
        printf("星期二\n");
        break;
    case 3:
        printf("星期三\n");
        break;
    case 4:
        printf("星期四\n");
        break;
    case 5:
        printf("星期五\n");
        break;//用于跳出Switch语句
    case 6:
        printf("星期六\n");
        break;
    case 7:
        printf("星期七\n");
        break;
    default://当输入值与要求值无关时，用这个来表达错误
        printf("输入错误，请输入1-7\n");
        break;
    }

    return 0;
}
练习：判断值
题目内容看视频，懒得打了。
答案：n=3 m=5（我觉得有误，不管了）


循环语句
while循环
#include <stdio.h>

int main()
{
    int i = 1;
    while(i<=10)
    {
        printf("%d\n", i);
        i++;
    }

    return 0;
}

  break用于跳出结束循环/continue用于回到循环开始

#include <stdio.h>

int main()
{
    int i = 1;
    while(i<=10)
    {
        printf("%d\n", i);
        i++;
        if (i == 5)
            break;//break用于结束循环,不再进行循环
    }

    return 0;
}


#include <stdio.h>

int main()
{
    int i = 1;
    while(i<=10)
    {
        if (i == 5)
            continue;//continue用于直接回到循环最开始的地方，也就是此行会直接回到while(i<=10)，本次循环中continue后面的语句不会执行
        printf("%d\n", i);
        i++;
    }

    return 0;
}

#include <stdio.h>

int main()//(有误，不知道为啥)
{
    int ch = 0;
    while ((ch = getchar()) != EOF)
    {
        if (ch < '0' || ch>'10')
            continue;
        putchar(ch);
    }
    return 0;
}


for循环(最常用！！！)
建议：1不要在for循环体内修改循环变量，防止for循环失去控制2循环控制变量取值采用"前闭后开区间"写法即for(i=0;i<10;i++)
语法:
for(表达式1;表达式2;表达式3)//1为初始循环2为条件循环3为调整循环
for可以等价于如下的while
int i= 0;//初始
while(i<10)//条件
{
    .....
    i++//调整

}


#include <stdio.h>

int main()
{
    int i = 0;
    for (i = 1; i <= 10; i++)
    {
        printf("%d\n", i);
    }
    return 0;
}

#include <stdio.h>

int main()
{
    int i = 0;
    for (i = 1; i <= 10; i++)
    {
        if (i == 5)
            break;//break与continue跟while中的作用一样
        printf("%d\n", i);
    }
    return 0;
}


#include <stdio.h>

int main()
{
    int i = 0;
    for (i = 1; i <= 10; i++)
    {
        if (i == 5)
            continue;//continue与while中的作用有差别，while中会直接从while当行回到条件行，可能不会执行调整行。但是for中的while会继续执行调整语句，然后再进行条件判断。
        printf("%d\n", i);
    }
    return 0;
}



#include <stdio.h>

int main()
{

    for (; ;)
    {
        printf("奶奶滴跟我玩阴滴是吧");
    }
    return 0;
}
//死循环，会一直高强度打印"奶奶滴跟我玩阴滴是吧"
//因为省略了判断条件，所以恒为真，就会一直执行

#include <stdio.h>

int main()
{
    int x, y;
    for (x=0,y=0;x<2&&y<5 ;++x,y++)
    {
        printf("奶奶滴跟我玩阴滴是吧");
    }
    return 0;
}

do while循环语句(特点是循环体一定会执行一次)
语法：
do
    循环语句
while（表达式）；

break continue起着一样的作用

#include <stdio.h>

int main()
{
    int i = 1;
    do
    {
        printf("%d\n", i);
        i++;
    }
    while(i<=10);
    return 0;
}

go to 语句
C语言中提供了可以随意滥用的goto语句和标记跳转的标号。
从理论上goto语句是没有必要的，实践中没有goto语句也可以很容易的写出代码。
但是某些场合下goto语句还是用得着的，最常见的用法就是终止程序在某些深度嵌套的结构的处理过程，例如一次跳出两层或多层循环。
这种情况使用break是达不到目的的。它只能从最内层循环退出到上一层的循环。
下面是使用goto语句的一个例子︰
for(...)
{
    for(...)
    {
        for(...)
        {
            if(disaster)
            goto error;
        }
    }
}
error:
    if(disaster)
    //处理错误情况 



练习


1.计算n的阶乘
错误解：
#include <stdio.h>

int main()
{
    int i = 1;
    ret n = 0;
    for (i = 1; i <= n; i++)
        i* i++;
    return 0;
}


答案：
#include <stdio.h>

int main()
{
    int i = 1;
    int n = 0;
    int ret = 1;
    scanf("%d", n);
    for (i = 1; i <= n; i++)
    {
        ret = ret * i;
    }
    printf("%d/n", ret);
    return 0;
}

2.计算1！+2！+3！+.....+10！
#include <stdio.h>
解1
int main()
{
    int i = 1;
    int n = 1;
    int ret = 1;
    int sum = 0;
    for (n = 1; n <= 10; n++)
    {
        ret = 1;
        for (i = 1; i <= n; i++)
        {
            ret = ret * i;
        }
        sum = sum + ret;
    }
    printf("%d\n", sum);
    return 0;
}
解2
#include <stdio.h>

int main()
{
    int i = 1;
    int n = 1;
    int ret = 1;
    int sum = 0;
    for (n = 1; n <= 10; n++)
    {

        ret = ret * n;
        sum = sum + ret;
    }
    printf("%d\n", sum);
    return 0;
}

3在一个有序数组中查找具体的某个数字n。编写int binsearch(int x, int v[], int n);功能∶在v[0]<=v[1]<=v[2]<= ....<=v[n-1]的数组中查找x。
二分法查找!!!重要编程思想
#include <stdio.h>

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int k = 6;
    int sz = sizeof(arr)/sizeof(arr[0]);//计算元素个数
    int left = 0;//左下标
    int right = sz-1;//右下标
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid]> k)
        {
            right = mid - 1;
        }
        else if (arr[mid] < k)
        {
            left = mid + 1;
        }
        else
        {
            printf("下标为：%d\n", mid);
            break;
        }
        if (left > right)
            printf("无法找到");

    }

    return 0;
}



4编写代码，演示多个字符从两端移动，虑中间汇聚。
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>
int main()
{
    char arr1[] = "颜憨憨出现在我的代码里咯!!";
    char arr2[] = "##########################";
    int left = 0;//左下标
    int right = strlen(arr1) - 1;
    //int right = sizeof(arr1) / sizeof(arr1[0])-2;//右下标/数组内部有\0，所以得-2

    while (left<=right)
    {
        arr2[left] = arr1[left];
        arr2[right] = arr1[right];
        printf("%s", arr2);
        Sleep(1000);//休息一秒1000毫秒。头文件为#include <Windows.h>
        system("cls");//清空屏幕，头文件为#include <stdlib.h>
        left++;
        right--;
    }
    printf("%s\n", arr2);
    return 0;
}




5编写代码实现，模拟用户登录情景，并且只能登录三次。(只允许输入三次密码，如果密码正确则提示登录成，如果三次均输入错误，则退出程序。)
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>
int main()
{
    int i = 0;
    char password[20] = {0};
    for (i = 0; i < 3; i++)
    {
        printf("请输入密码:\n");
        scanf_s("%s", password);
        if (strcmp(password , "123456")==0)//==不能用来比较两个字符串是否相等，应该用一个库函数--strcmp
        {
            printf("登录成功\n");
            break;
        }
        else
        {
            printf("密码错误\n");
        }
    }
    if (i == 3)
        printf("三次密码均错误，一小时后重试");

    return 0;
}



作业题1：从大到小输出。将三个数从大到小输出。
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>
int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    scanf_s("%d%d%d", &a, &b, &c);
    if (a < b)
    {
        int tmp = a;
        a = b;
        b=tmp;
    }
    if (a < c)
    {
        int tmp = a;
        a = c;
        c = tmp;
    }
    if (b < c)
    {
        int tmp = b;
        b = c;
        c = tmp;
    }
    printf("%d%d%d\n", a, b, c);//算法实现：a放最大值，b放中间值，c放最小值
    return 0;//利用if语句来赋值改变abc之间的大小，使得a放最大值，b放中间值，c放最小值
}
作业题2：打印3的倍数。打印1-100之间所有3的倍数
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>
int main()
{
    int i = 0;
    for (i = 0; i < 100; i++)
    {
        if (i % 3 == 0)
            printf("%d\n", i);
    }
    return 0;
}
作业题3：最大公约数。给定两个数，求两个数的最大公约数。
算法：辗转相除法
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>
int main()
{
    int m = 0;
    int n = 0;
    int r = 0;
    scanf_s("%d%d", &m, &n);
    while(m%n)
    {
        r = m % n;
        m = n;
        n = r;
    }
    printf("%d",n);
    return 0;
}
作业题4：求1000-2000年之间的闰年以及一共有多少个闰年。
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>
int main()
{
    int year = 0;
    int count = 0;
    for(year=1000;year<2000;year++)
    {
        if (year % 4 == 0 && year % 100 != 0)
        {
            printf("%d", year);
            count++;
        }
        else if (year % 400 == 0)
        {
            printf("%d", year);
            count++;
        }
    }

    printf("\n%d\n", count);

    return 0;
}

作业题5：打印100-200之间的素数

判断i是否为素数，素数判断的规则：1.试除法
1.试除法
#include <stdio.h>
int main()
{
    int i = 0;
    for (i = 100; i <= 200; i++)//产生100-200之间的数字，在此基础上进行判断
    {
        int j = 0;
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                break;
            }
        }
        if (i == j)
        {
            printf("%d  ", i);
        }
    }
    return 0;
}
升级版：
#include <stdio.h>
#iclude<math.h>
int main()
{
    int i = 0;
    for (i = 101; i <= 200; i+=2)//产生100-200之间的奇数，在此基础上进行判断
    {
        int j = 0;
        for (j = 2; j <= sqrt(i) ; j++)//sqrt()--开平方的数学库函数
        {
            if (i % j == 0)
            {
                break;
            }
        }
        if (j > sqrt(i))
        {
            printf("%d  ", i);
        }
    }
    return 0;
}


作业题6：数九的个数。1-100中出现多少个9
#include <stdio.h>
int main()
{
    int i = 0;
    int count = 0;
    for (i = 1; i < 100; i++)//产生1-100之间的数字，在此基础上进行判断
    {
        if (i % 10 == 9)//(i%10==9 ||i / 10 == 9)也可以
        {
            count++;
        }
        if (i / 10 == 9)
        {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}


作业题7：计算1/1-1/2+1/3...........+1/100的值，并打印出来
#include <stdio.h>
int main()
{
    int i = 0;
    double j = 0;
    double sum = 0;
    int flag = 1;
    for (i = 1; i <= 100; i++)
    {
        j=1.0 / i;//注意1.0是为了让整个1.0/i这个式子变成浮点数数据格式，不如小数计算不出来
        sum = sum +flag* j;
        flag = -flag;
    }
    printf("%lf\n", sum);
    return 0;
}


1小时36分钟-2小时46分的作业忽略不看（太长了，以后兴起再看吧）










*/