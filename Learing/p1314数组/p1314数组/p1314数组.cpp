#include <stdio.h>
void buble_sort(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)//用于循环每一趟
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)//用于循环每一趟里的数字交换
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j ];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 ,0};
	int sz = sizeof(arr) / sizeof(arr[0]);//计算冒泡排序的趟数
	buble_sort(arr,sz);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("% d " , arr[i]);
	}
	return 0;
}

/*
本章重点
1.一维数组的创建和初始化
2.—维数组的使用
3.一维数组在内存中的存储
4.二维数组的创建和初始化
5.二维数组的使用
6.二维数组在内存中的存储
7.数组作为函数参数
8.数组的应用实例1:三子棋
9.数组的应用实例2∶扫雷游戏



一维数组的创建和初始化

数组的创建
数组是一组相同类型元素的集合。
数组的创建方式∶
type_t   arr_name  [const_n];
type_t是指数组的元素类型
 const_n是一个常量表达式，用来指定数组的大小
 例如；
 char arr3[10];f1oat arr4[1];doub1e arr5[20];


数组的初始化
数组的初始化是指，在创建数组的同时给数组的内容一些合理初始值（初始化)。
int arr1[10]= {1,2,3};//不完全初始化。剩下的元素默认初始化为0。
int arr[]='ab';//'ab'后面自带隐藏的\0。所占空间为3，字符长度为2。
int arr2[] = {1,2,3,4};
int arr3[5] = {1，2，3，4，5};
char arr4[3] = { 'a' ,98，'c '};
char arr5[] ={  'a ' , 'b', 'c'};
数组的区别
int arr1[10]= {'a','b','c'};该形式不含\0，strlen函数会一直查找直到有\0，所以如果用strlen查找这个数组，那么结果会是随机值。
int arr2[10]= "abc";该形式自带\0


一维数组的使用
对于数组的使用我们之前介绍了一个操作符︰[]，下标引用操作符。它其实就数组访问的操作符。

#include <stdio.h>
#include <string.h>
int main()
{
	char arr[] = "abcdfghi";
	int i = 0;
	int len = strlen(arr);
	for (i = 0; i < len; i++)
	{
		printf("%c\n", arr[i]);//a对应的下标是0
	}
}

总结:
1.数组是使用下标来访问的，下标是从0开始。
⒉数组的大小可以通过计算得到。
int arr[10];
int sz = sizeof(arr)/sizeof(arr[0]);


一维数组在内存中的存储
十进制：0123456789
十六进制：0123456789ABCDFG
int arr[] = {1,2,3,4};
一维数组在内存中是连续存放的，空间连续开辟



二维数组的创建和初始化

二维数组的创建
int arr[3][4];//3行4列共12个元素
char arr[3][5];
double arr[2][4];

二维数组的初始化（矩形数组）
int arr[3][4] = {1,2,3,4};//不完全初始化，按顺序放置元素，先放满一行再放下一行
int arr[3][4] = {{1,2},{4,5};//此代码意思为，12放在第一行，45放在第二行，第一行和第二行空余的元素为0
int arr[][4] = {{2,3},{4,5}};二位数组中，行可以省略，列不能省略而且必须大于一行元素的总数

二维数组的使用
注意，第一行和第一列的下标都是0。从0开始算。
#include <stdio.h>
#include <string.h>
int main()
{
	int arr[3][4] = {{1,2,3},{4,5}};
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 4; j++)
		{
			printf("%d  ", arr[i][j]);//第i行第j列的元素
		}
		printf("\n");
	}

}


二维数组在内存中是连续存放的，空间连续开辟。其实也可以把二维数组看做几个一维数组横排放。
可以这样去理解：
arr[0][j];arr[1][j];arr[2][j];arr[3][j];




数组作为函数参数

往往我们在写代码的时候，会将数组作为参数传个函数，比如∶我要实现一个冒泡排序（这里要讲算法思想）函数将一个整形数组排序。
那我们将会这样使用该函数︰
冒泡排序思想：将数之间进行顺序交换，换成想要的排序。
#include <stdio.h>
void buble_sort(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)//用于循环每一趟
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)//用于循环每一趟里的数字交换
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j ];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 ,0};
	int sz = sizeof(arr) / sizeof(arr[0]);//计算冒泡排序的趟数
	buble_sort(arr,sz);//数组在传参时，传递的是首元素的地址 即&arr[0]
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("% d " , arr[i]);
	}
	return 0;
}

数组名是什么?
#include <stdio.h>
int main()
{
	int arr[10] = {1,2，3,4,5};
	printf("%p\n"，arr);
	printf("%p\n"，&arr[0]);
	return 0;//结果是一样的，证明数组名arr就是数组首元素的地址。
}
结论∶
数组名是数组首元素的地址。（有两个例外)
例外1：sizeof(数组名)--此时数组名表示整个数组
例外2：&数组名--数组名表示整个数组


三子棋程序
扫雷程序














*/