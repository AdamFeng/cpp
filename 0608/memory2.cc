 ///
 /// @file    memory2.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-08 10:21:08
 ///
 
#include<stdio.h>
#include <iostream>
using std::cout;
using std::endl;

int a=0;
const int b=10;//文字常量区
//生命周期的不同导致const常量的存储位置不同

int main()
{
	char* p1="123456";
	const int c=20;//栈

	printf("& a=%p\n",&a);//全局/静态区
	printf("& b=%p\n",&b);//文字常量区
	printf("& c=%p\n",&c);//栈
	printf("&p1=%p\n",&p1);//栈
	printf("p1 =%p\n",p1);//文字常量区
	return 0;
}
