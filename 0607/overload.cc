 ///
 /// @file    overload.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-07 23:05:57
 ///
 
#include<stdio.h>
#include <iostream>
using std::cout;
using std::endl;

/*
 C语言不支持重载
 C++支持函数重载：
 实现原理：名字改编(name mangling)
	当函数名称相同时，会根据形参个数、类型、顺序进行名字改编
 */
//对源文件只进行编译，得到.o后可用nm查看改编后的名字

int add(int a,int b)
{
	return a+b;
}
double add(double a,double b)
{
	return a+b;
}
int add(int a,double b, int c)
{
	return a+b+c;
}

int main()
{
	int a=3;
	int b=4;
	printf("a+b=%d\n",add(a,b));
	double c=3.4;
	double d=6.2;
	printf("c+d=%f\n",add(c,d));
	return 0;
}
