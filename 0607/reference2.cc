 ///
 /// @file    reference2.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-07 21:59:55
 ///
 
#include <iostream>
using std::cout;
using std::endl;
/*发生值传递，即copy
void swap(int x,int y)
{
	int tmp=x;
	x=y;
	y=tmp;
}
*///指针传递，本质为值传递
void swap(int* px,int* py)
{
	int tmp=*px;
	*px=*py;
	*py=tmp;
}

void swap(int &refx,int& refy)
{
//函数传参时，不需要进行复制，直接操作实参本身
//会减少复制的开销，从而提高执行效率
//使用时更直观，更容易理解
	int tmp=refx;
	refx=refy;
	refy=tmp;
}

int arr[5]={0,1,2,3,4};

int & func()//引用作为函数返回值
{
	return arr[0];
}/*
//不能返回一个局部变量的指针
int * func1()
{
	int x=4;
	return &x;
}
//不能返回局部变量的引用
int &func2()
{
	int x=4;
	return x;
}*/
//不要轻易返回堆空间对象的引用
int &func3()
{
	int* px= new int(10);
	return *px;
}
int main()
{
	int a=3;
	func()=10;
	cout<<a+func()<<endl;

	cout<<arr[0]<<endl;
//	cout<<func2()<<endl;

	//这种方法可用堆空间的返回
	int &b=func3();
	cout<<"b="<<b<<endl;
	delete(&b);

	//该表达式执行完毕后，就会发生内存泄露
	cout<<"a+func3()="<<a+func3()<<endl;
	return 0;
}

int test()
{
	int a=3;
	int b=4;
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	//swap(&a,&b);
	swap(a,b);

	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	return 0;
}
