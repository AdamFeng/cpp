 ///
 /// @file    new.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-07 21:06:59
 ///
 
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main()
{
/*-------------------C语言申请内存空间--------------------*/
	int *pa=(int*)malloc(sizeof(int));
	cout<<"*pa="<<*pa<<endl;
	*pa=10;
	cout<<"*pa="<<*pa<<endl;
	free(pa);

/*-------------------C++申请内存空间----------------------*/
	int *pb=new int(3);
		//new是一个表达式，它负责开辟空间，并可以初始化
	cout << "*pb="<<*pb<<endl;
	delete pb;//空间释放

	//申请数组时，初始化值需要在[]后加()
	//如果不加，初始值不确定
	int *pd=new int[10]();//申请拥有10个int型数据的数组空间
	for(int idx=0;idx!=10;idx++)
	{
		cout<<pd[idx]<<" ";
	}
	cout<<endl;
	delete [] pd;//释放数组空间，加[]


}

