 ///
 /// @file    memory.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-08 10:10:07
 ///

#include<string.h>
#include<stdio.h>
#include <iostream>
using std::cout;
using std::endl;

int a=0;//全局初始化区
char* p1;//全局未初始化区

int main()
{
	int b;//stack
	char s[]="112";//stack
	char *p2;//stack
	char *p3="112";//p3--stack  字符串位于文字常量区
	static int c=0;//全局/静态区
	p1=new char[10];//p1指向的对象位于堆
	p2=new char[5];//p2指向的对象位于堆
	strcpy(p1,"112");

	//文字常量区
	printf("p3 =%p\n",p3);
	//全局/静态区
	printf("& a=%p\n",&a);
	printf("& c=%p\n",&c);
	printf("&p1=%p\n",&p1);
	//堆区
	printf("p1 =%p\n",p1);
	printf("p2 =%p\n",p2);
	//栈区
	printf("& s=%p\n",s);
	printf("& b=%p\n",&b);
	printf("&p2=%p\n",&p2);
	printf("&p3=%p\n",&p3);
}
