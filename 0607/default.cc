 ///
 /// @file    default.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-08 15:00:37
 ///

#include<stdio.h>
#include <iostream>
using std::cout;
using std::endl;

int add(int a,int b=0)
{//可以接收一个或两个参数
	return a+b;
}
//设置默认形参要从右到左进行
int add(int a,int b,int c)
{
	return a+b+c;
}

int main()
{
	int a=3;
	int b=4;
	cout<<add(a)<<endl;
	printf("a+b=%d\n",add(a,b));
	return 0;
}
