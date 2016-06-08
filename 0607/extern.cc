 ///
 /// @file    extern.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-08 15:06:13
 ///

#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

//进行C和C++混合编程
//#ifdef __cpluscplus
extern "C"//extern{}内的是用C编译的
{
//#endif

int add(int a,int b)
{
	return a+b;
}

//#ifdef __cpluscplus
}
//#endif

int add(int a,double b,int c)
{
	return a+b+c;
}

int main()
{
	int a=3;
	int b=4;
	printf("a+b=%d\n",add(a,b));
}
