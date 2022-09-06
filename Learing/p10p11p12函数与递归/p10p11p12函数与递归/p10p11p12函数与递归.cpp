#include <stdio.h>
#include <string.h>



int Fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;

}


int main()
{
	int n = 0;
	int ret = 0;
	scanf_s("%d", &n);
	ret = Fib(n);
	printf("%d\n", ret);
}











/*
函数


函数定义
维基百科中对函数的定义︰子程序
·在计算机科学中，子程序（英语:Subroutine, procedure, function, routine, method,subprogram, callable unit )，是一个大型程序中的某部分代码，由一个或多个语句块组成。它负责完成某项特定任务，而且相较于其他代码，具备相对的独立性。
一般会有输入参数并有返回值，提供对过程的封装和细节的隐藏。这些代码通常被集成为软件库。


C语言中函数的分类∶
1.库函数
2.自定义函数


库函数︰
为什么会有库函数?
1.我们知道在我们学习C语言编程的时候，总是在一个代码编写完成之后迫不及待的想知道结果，想把这个结果打印到我们的屏幕上看看。这个时候我们会频繁的使用一个功能∶将信息按照一定的格式打印到屏幕上( printf )。
⒉在编程的过程中我们会频繁的做一些字符串的拷贝工作( strcpy )。
3.在编程是我们也计算，总是会计算n的k次方这样的运算( pow )。
像上面我们描述的基础功能，它们不是业务性的代码。我们在开发的过程中每个程序员都可能用的到，为了支持可移植性和提高程序的效率，所以C语言的基础库中提供了一系列类似的库函数，方便程序员进行软件开发。


简单的总结，C语言常用的库函数都有∶
IO函数
字符串操作函数
字符操作函数
 内存操作函数
时间/日期函数数学函数
其他库函数


具体使用一个库函数，需要引用相应的头文件。
学习一个库函数，可以在c++的官网上搜索该函数，得到该函数的使用方法和细节
例如memset
#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "almost every programmer should know memset!";
	memset(str, '-', 6);
	puts(str);
	return 0;
}


自定义函数
自定义函数和库函数一样，有函数名，返回值类型和函数参数。但是不一样的是这些都是我们自己来设计。这给程序员一个很大的发挥空间。
函数基本型：
ret_type fun_name(para1,*,*)      右边为例子     int Add(int x，int y)
{												 {
	statement;//语句项								  int z =0;
}													  z=x+y;
ret_type//返回类型									  return z;
fun_name//函数名								  }
para1//参数


例1
#include <stdio.h>
#include <string.h>

//定义函数（求两数中最大值函数）
int get_max(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}

int main()
{
	int a = 10;
	int b = 20;
	int max = get_max(a, b);//使用了未知的函数，需要定义一个函数
	printf("%d", max);
	return 0;
}


例2
错误版：
//定义交换值函数
#include <stdio.h>
#include <string.h>

//定义函数
void swap1(int x, int y)//void表示没有返回值类型
注意：这个函数是有问题的，无法运用起来。因为x与y开辟了两个新的空间、地址，xy即使交换了数值，也无法反应到外界。
{
	int tmp = 0;
	tmp = x;
	x = y;
	y = tmp;
}

int main()
{
	int a = 10;
	int b = 20;
	swap1(a,b);//使用了未知的函数，需要定义一个函数
	printf("%d\n%d", a,b);
	return 0;
}
最终打印出的值没有交换

改良版：(利用取地址和指针变量，将地址内的内容交换)
#include <stdio.h>
#include <string.h>

void swap2(int* pa, int* pb)//指针变量。int* pa, int* pb为形参
{
	int tmp = 0;
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

int main()
{
	int a = 10;
	int b = 20;
	swap2(&a,&b);//&a&b为实参
	printf("%d\n%d", a,b);
	return 0;
}

实际参数（实参):
真实传给函数的参数，叫实参。实参可以是∶常量、变量、表达式、函数等。无论实参是何种类型的量，在进行函数调用时，它们都必须有确定的值，以便把这些值传送给形参。
形式参数（形参) ∶
形式参数是指函数名后括号中的变量，因为形式参数只有在函数被调用的过程中才实例化(分配内存单光），所以叫形式参数。形式参数当函数调用完成之后就自动销毁了。因此形式参数只在函数中有效。
当实参传给形参的时候
形参其实是实参的一份临时拷贝
对形参的修改是不会改变实参的


函数的调用∶
传值调用（如swap1）
函数的形参和实参分别占有不同内存块，对形参的修改不会影响实参。
传址调用（如swap2）
1传址调用是把函数外部创建变量的内存地址传递给函数参数的一种调用函数的方式。
2这种传参方式可以让函数和函数外边的变量建立起正真的联系，也就是函数内部可以直接操作函数外部的变量。


练习
1.写一个函数可以判断一个数是不是素数。
#include <stdio.h>

int is_prime(int n)//利用2到n-1本身以及之间的数来取模判断一个数是不是素数
{
	int j = 0;
	for (j = 2; j < n; j++)
	{
		if (n % j == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int i = 0;
	for (i = 100; i <= 200; i++)
	{
		if (is_prime(i) == 1)
			printf("%d  ", i);
	}
	return 0;
}
2.写一个函数判断一年是不是闰年。
#include <stdio.h>

int is_leap_year(int y)
{
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
	{
		return 1;
	}
	else 0;
}

int main()
{
	int year = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if (is_leap_year(year) == 1)
		{
			printf("%d  ", year);
		}
	}
	return 0;
}

3.写一个函数，实现一个整形有序数组的二分查找。
二分查找
在一个有序数组中查找具体的某个数
如果找到了返回这个数的下标。找不到的返回-1
错误版：
#include <stdio.h>
#include <string.h>
int binary_search(int arr[],int k)//这里的arr实际上是指针
{
	int left = 0;
	int right = sizeof(arr)/sizeof(arr[0])-1;//这里相当于指针变量的大小除以数组元素int的大小。即4（8）字节除以4（8）字节

	while (left<=right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 7;
	int ret = binary_search(arr, k);//！注意数组传参数的过程中，只会传数组的第一个元素的地址！！！！
	if (ret == -1)
	{
		printf("没找着嘿嘿");
	}
	else
	{
		printf("找到惹是：%d\n", ret);
	}

	return 0;
}


正确版：
#include <stdio.h>
#include <string.h>
int binary_search(int arr[],int k,int sz)//这里的arr实际上是指针
{
	int left = 0;
	int right = sz - 1;
	while (left<=right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 7;
	int sz = sizeof(arr) / sizeof(arr[0]) ;
	int ret = binary_search(arr, k,sz);//！注意数组传参数的过程中，只会传数组的第一个元素的地址！！！！
	if (ret == -1)
	{
		printf("没找着嘿嘿");
	}
	else
	{
		printf("找到惹是：%d\n", ret);
	}

	return 0;
}



4.写一个函数，每调用一次这个函数，就会将num的值增加1。
#include <stdio.h>
#include <string.h>
void Add(int* p)//
{
	(*p)++;
}

int main()
{
	int num = 0;
	Add(&num);
	printf("%d\n", num);
	Add(&num);
	printf("%d\n", num);
	Add(&num);
	printf("%d\n", num);

	return 0;
}



函数的嵌套调用和链式访问
函数和函数之间可以有机的组合的。

嵌套调用：
#include <stdio.h>
#include <string.h>
void new_line()//
{
	printf("niubility");
}
void three_line()//
{
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		new_line();
	}
}
int main()
{
	three_line();
	return 0;
}


链式访问
把一个函数的返回值作为另外一个函数的参数。
例1
#include <stdio.h>
#include <string.h>

int main()
{
	printf("%d\n", strlen("abcd"));//类似数学中的复合函数
	return 0;
}
例2
int main()
{
	printf("%d", printf("%d",printf("%d",43)));//注意printf的返回值是打印的内容的个数，43返回值为2,2返回值为1，所以打印结果是4321
	return 0;
}



函数的声明和定义

函数声明︰
1.告诉编译器有一个函数叫什么，参数是什么，返回类型是什么。但是具体是不是存在，无关紧要。
2.函数的声明一般出现在函数的使用之前。要满足先声明后使用。
3.函数的声明一般要放在头文件中的。

函数定义∶
函数的定义是指函数的具体实现，交待函数的功能实现。

函数的声明和定义配套使用：
一般是创建三个文件
例如
第一步：add.h中放入函数的声明
xxx.h放声明
第二步：add.c中放入函数的定义
xxx.c放定义
第三步：test.c中使用函数时，先在头文件引用add.h。  头文件格式为：#include"add.h"。因为这里的函数是自创的，格式要求是""不是<>

#include <stdio.h>
#include <string.h>

//函数的声明
int Add(int, int);//注意声明的时候有分号

int main()
{
	int a = 10;
	int b = 20;
	int sum = 0;
	sum = Add(a, b);
	printf("%d",sum);
	return 0;
}



//函数的定义
int Add(int x, int y)//此时虽然定义了函数，但是编译器读取顺序从上到下，所以需要在main函数前声明该函数。//定义时不需要分号
{
	int z = x + y;
	return z;
}




函数递归

定义：程序调用自身的编程技巧称为递归( recursion )。递归做为一种算法在程序设计语言中广泛应用。
一个过程或函数在其定义或说明中有直接或间接调用自身的一种方法，它通常把一个大型复杂的问题层层
转化为一个与原问题相似的规模较小的问题来求解，递归策略只需少量的程序就可描述出解题过程所需要
的多次重复计算，大大地减少了程序的代码量。递归的主要思考方式在于:把大事化小。

递归的两个必要条件
·存在限制条件，当满足这个限制条件的时候，递归便不再继续。
·每次递归调用之后越来越接近这个限制条件。
递归要善加利用（一定要有限制条件），不然容易栈溢出--Stack Overflow

练习1：接受一个整型值（无符号），按照顺序打印它的每一位。例如︰输入∶1234，输出1  2  3  4.
#include <stdio.h>
#include <string.h>

void print(int n)
{
	if (n > 9)//·设置了限制条件，防止函数无限递归导致栈溢出
	{
		print(n / 10);//·函数在定义的过程中，再次调用了函数。同时这个函数调用过程会使函数越来越接近限制条件
	}
	printf("%d  ", n % 10);
}
这就是递归，目前，我个人类似就有点像循环和嵌套函数



int main()
{
	unsigned int num = 0;
	scanf_s("%d", &num);
	print(num);
	return 0;
}

练习2∶编写函数不允许创建临时变量，求字符串的长度。
错误版：
#include <stdio.h>
#include <string.h>

int my_strlen(char* str)//这里str接受的信息是数组的第一个元素的地址。然后一个数组包括素组的所有元素以及隐藏的\0。利用\0来设置限制条件
{
	int count = 0;
	while (*str != '\0')//*str解引用，找到数组的第一个元素
	{
		count++;
		str++;//地址++表达的意思是往后寻找一个地址
	}
	return count;
}


int main()
{
	char arr[] = "asiugaiosnd";
	int len = my_strlen(arr);
	printf("%d", len);
	return 0;
}
正确版：
#include <stdio.h>
#include <string.h>

//大事化小思维
//my_strlen("yxy")
//1+my_strlen("xy")
//1+1my_strlen("y")
//1+1+1my_strlen("")

int my_strlen(char* str)//这里str接受的信息是数组的第一个元素的地址。然后一个数组包括素组的所有元素以及隐藏的\0。利用\0来设置限制条件
{
	if (*str != '\0')//*str解引用，找到数组的第一个元素
	{
		return 1 + my_strlen(str + 1);//str + 1是指地址往后+1
	}
	else
	{
		return 0;//这个式子是为了整个函数递归到最后时，返回0这个值与1相加，不计算'\0'这个字符长度
	}
}

int main()
{
	char arr[] = "yxy";
	int len = my_strlen(arr);
	printf("%d", len);
	return 0;
}

递归与迭代
练习3:求n的阶乘（不考虑溢出）
#include <stdio.h>
#include <string.h>



int Fac(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * Fac(n - 1);
}


int main()
{
	int n = 0;
	int ret = 0;
	scanf_s("%d", &n);
	ret = Fac(n);
	printf("%d\n", ret);
}
练习4：求第n个斐波那契数。
不适合用递归，计算量特别大
所以用循环迭代
#include <stdio.h>
#include <string.h>



int Fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;

}


int main()
{
	int n = 0;
	int ret = 0;
	scanf_s("%d", &n);
	ret = Fib(n);
	printf("%d\n", ret);
}



















































*/