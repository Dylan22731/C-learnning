#include <stdio.h>
#include <string.h>

int main()
{
	int a = 100;
	int* p = &a;//取地址
	printf("%p\n",&a);//%p用于打印地址
	printf("%p\n", p);
	*p = 20;//解引用操作符，意味着找到p对应的地址的空间，将空间内容更改为20
	printf("a = %d\n", a);
	return 0;

}
/*
操作符
控制符

sizeof（操作数的类型长度，以字节为单位）的用法
#include <stdio.h>
#include <string.h>
int main()
{
   int a = 10;
   int arr[] = { 1,2,3,4,5,6 };
   printf(" %d\n", sizeof(a));
   printf(" %d\n", sizeof(int));
   printf(" %d\n", sizeof a);
   //printf(" % d\n", sizeof int);error
   printf(" %d\n", sizeof(arr));//计算数组大小，单位是字节
   printf(" %d\n", sizeof(arr)/sizeof(arr[0]));//通过总数组大小除以单个数组元素大小来计算数组个数
}

~(对一个数的二进制按位取反)的用法
#include <stdio.h>
#include <string.h>
int main()
{
	int a = 0;//4个字节32个比特位0000000000000....三十二个0
	int b = ~a;//b为11111111111111.......三十二个1同时b为有符号的整型，符号位为第一位为1，说明其为负数。记住，此时b为补码！！
	printf(" %d\n", b);//打印的是源码
	//源码、反码、补码
	//负数在内存中储存的时候，是二进制的补码
	//源码、反码、补码运算规则：1源码符号位不变，其他位按位取反得到反码。2反码加1得到补码。
	//所以b打印的过程为
	//1111111111111111111111111111111补码
	//1111111111111111111111111111110反码
	//1000000000000000000000000000001源码
	//最终表示为-1
}

--和++的用法
#include <stdio.h>
#include <string.h>
int main()
{
	int a = 10;//
	//int b = a++;//后置++:先使用a的值，再使用++
	int b = ++a;//后置++:先使用++，再使用a
	printf(" %d\n% d\n" ,a,b);//11 11
	//--同理
}

(类型)强制类型转换，尽量不用哦



关系操作符
>大于
<
>=
<=小于等于
==
!=测试不相等
==测试相等


逻辑操作符
&&并且逻辑（一假为假）
||或逻辑（一真为真）


#include <stdio.h>
#include <string.h>
int main()
{
	//0表示假,非0表示真
	int a = 10;
	int b = 5;
	int c = a && b;//ab为真所以c为真，打印出非零数据即1
	printf(" %d\n" ,c);
}

#include <stdio.h>
#include <string.h>
int main()
{
	//0表示假,非0表示真
	int a = 0;
	int b = 5;
	int c = a && b;//a为假，b为真所以c为假，打印出0
	printf(" %d\n" ,c);
}


条件操作符
exp1?exp2:exp3

#include <stdio.h>
#include <string.h>
int main()
{
	//0表示假,非0表示真
	int a = 10;
	int b = 20;
	int max = 0;
	max = (a > b ? a : b);
	printf(" %d\n" ,max);
}
逗号操作符
exp1，exp2，exp3，exp4....

下标引用、函数调用和结构成员
[] () .


常见关键字
auto break case char const continue default do doub1e else enum
extern float forgoto if int long register return short signed
sizeof static struct switch typedef union unsigned void volatile while
int等价于signed int ：定义的变量时有符号的  unsigned int ：定义的变量时无符号的
register:建议定义为寄存器变量，会使得cpu接收更快，整个电脑会处理的更快
变量与关键字不能冲突

关键字typedef:类型定义，理解为类型重命名，通俗就是喊个小名

#include <stdio.h>
#include <string.h>
int main()
{
	unsigned int a = -10;
	typedef unsigned int uint;
	uint b = -35;
	printf(" %d\n" ,b);
	return 0;


}

关键字static：用于修饰变量和函数
1修饰局部变量-静态局部变量：延长局部变量生命周期，使局部变量不会被销毁
2修饰全局变量-静态全局变量：改变变量作用域，让全局变量只能在自己所在的源文件中作用
3修饰函数-静态函数：改变了函数的连接属性，由外部链接属性变为内部链接属性，效果也是只能在源文件中作用

知识补充：调用其他源文件的函数时，需要声明外部函数。如：extern int Add(int,int);


#include <stdio.h>
#include <string.h>

void test()
{
	static int a = 1;//修饰为静态局部变量a。意味着a在循环中没有被销毁，一直累积着。
	a++;
	printf("a = % d\n", a);
}
int main()
{
	int i = 0;
	while (i < 5)
	{
		test();
		i++;
	}

	return 0;



#difine定义常量和宏
#difine MAX 100
#difine MAX(X,Y) (X>Y?;X:Y)

指针

指针变量-用于存放地址:int*

#include <stdio.h>
#include <string.h>

int main()
{
	int a = 100;
	int* p = &a;//取地址
	printf("%p\n",&a);//%p用于打印地址
	printf("%p\n", p);
	*p = 20;//解引用操作符，意味着找到p对应的地址的空间，将空间内容更改为20
	printf("a = %d\n", a);
	return 0;

}
	int a = 100; 将100存放在一个地址对应的空间中
	int* p = &a;将地址存放在一个新的空间中
	*p = 20；通过*p找到刚才存放100的地址的空间，将空间内容改成20


指针变量的大小
在32位平台是4个字节
在64位平台是8个字节













*/