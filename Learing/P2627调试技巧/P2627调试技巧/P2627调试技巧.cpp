//版本二：10分
//知识补充：const int* p = &num;  const放指针变量的*左边，修饰的是*p，这意味着不能修改*p的值
//int* const p =&num;  const放指针变量的*右边，修饰的是p，这意味着不能修改p的值
#include <stdio.h>
#include <assert.h>

char* my_strcmp(char* dest, const char* src)//const修饰的是*src，说明*src不能改变。	所以while (*src++ = *dest++)就会报错
{
	char* ret = dest;
	assert(dest != NULL);//assert语句要引用头文件#include <assert.h>，然后当条件为假即assert(0)就会报错，方便查找问题所在
	assert(src != NULL);
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char arr1[] = "yxyytdxhgsq";
	char arr2[] = "hanhan";
	printf("%s", my_strcmp(arr1, arr2));

}


//动手完成一个strcmp函数
//版本一：8分
//#include <stdio.h>
//#include <assert.h>
//
//void my_strcmp(char* dest, char* src)
//{
//	assert(dest != NULL);//assert语句要引用头文件#include <assert.h>，然后当条件为假即assert(0)就会报错，方便查找问题所在
//	assert(src != NULL);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}
//int main()
//{
//	char arr1[] = "yxyytdxhgsq";
//	char arr2[] = "hanhan";
//	my_strcmp(arr1, arr2);
//	printf("%s", arr1);
//
//}



//#include <stdio.h>
//int main()
//{
//    int i = 0;
//    int arr[10] = { 0 };
//    for (i = 0; i <= 12; i++)
//    {
//        arr[i] = 0;
//        printf("hehe\n");
//    }
//    return 0;
//}
//死循环的原因：
//1.盏区的默认使用规则：先使用高地址处的空间，再使用低地址处的空间
//2.数组随着下标的增加，地址是由低到高
//所以这里的情况是数组越界访问，然后访问到了i的地址，使i=0，从而进行的死循环。



// #include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	int sum = 0;//保存最终结果
//	int n = 0;
//	int ret = 1;//保存n的阶乘
//	scanf_s("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		int j = 0;
//		for (j = 1; j <= i; j++)//错误原因为ret保存了上次计算的结果，导致阶乘的过程乘了上一次阶乘的结果，令ret=1就好了
//		{
//			ret *= j;
//		}
//		sum += ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}