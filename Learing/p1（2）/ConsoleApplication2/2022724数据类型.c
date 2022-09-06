#include<stdio.h>

int main()
{
	{
		int num1 = 0;
		printf("num = %d\n", num1);//ok
		return 0;
	}
	printf("num = %d\n", num1);//error
	return 0;
}

/*
数据类型
    char ch = 'A';
	printf("%c\n",ch);//%c--打印字符格式的数据
	int age = 20;
		printf("%d\n", age);//%d--打印整型十进制数据

数据所占内存空间
    printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(short));
	printf("%d\n", sizeof(float));
	printf("%d\n", sizeof(long long));

		short age = 20;//申请两个字节来存放20这个数据，两个字节及16个比特位。
	float weght = 125.4;
全局变量与局部变量
#include<stdio.h>
int A = 100;//全局变量，当没有局部变量时，执行全局变量。
int main()
{
	int A = 20;//局部变量
	printf("%d\n", A);//全局变量不要和局部变量重名。容易bug。同时局部变量优先。同时局部变量优先。但是局部的意思是指在大括号内哦
    return 0;
}
变量的使用
#include<stdio.h>

int main()
{
	//计算两个数的和
	int num1 = 0;
	int num2 = 0;
	int sum = 0;
	//c语言定义，变量要定义在当前代码块的最前面
	//输入数据-使用输入函数scanf
	scanf ("%d%d",&num1, &num2);//取地址符号&
	sum = num1 + num2;
	printf("sum=%d\n", sum);
	return 0;
}

变量的作用域和生命周期
作用域
#include<stdio.h>

int main()
{
	int num1 = 0;
	printf("num = %d\n", num1);//此行是变量num1的作用域，全局变量的作用域很广，可用于整个工程
	return 0;全局变量的作用域甚至可以跨文件，只需要使用extern进行声明就好
}
生命周期
局部变量的生命周期
#include<stdio.h>

int main()
{
	{//局部变量的生命周期的开始
		int num1 = 0;
		printf("num = %d\n", num1);//ok
		return 0;
	}//局部变量的生命周期的结束，所以下面的打印函数中num是未定义表示符
	printf("num = %d\n", num1);//error
	return 0;
}
全局变量的生命周期是整个程序的生命周期









char 字符数据类型
short短整型
int整型
long长整型
long long更长的整型
float单精度浮整数
double双精度浮整数
%c--打印字符格式的数据
%d--打印整型格式的数据
%f--打印浮点数格式的数据
%p--以地址的形式打印
%x--打印16进制数字




*/