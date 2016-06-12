 ///
 /// @file    singleton.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-10 11:12:08
 //
 ///单例设计模式--类似全局变量
 //
 //类在内存中只能有1个实例

#include<stdio.h> 
#include <iostream>
using std::cout;
using std::endl;

//要求：内存中一个类只能产生一个数据对象
//
//1、该对象不能是栈对象,全局对象,只能为堆对象
//2、将构造函数放入private区域
//3、在public提供一个静态成员函数
//4、提供一个static数据成员

//int a=3;//尽量不适应全局变量，使用单例模式替代

class singleton
{
public:
	static singleton * getInstance()
		//类内提供方法,调用singleton构造函数,创建一个对象
		//static,通过类名进行调用static方法
	{
		if(_pInstance==NULL)
			_pInstance=new singleton;
		return _pInstance;
	}

	static void destroy()
	{
		delete _pInstance;
	}
private:
	singleton()//构造函数放入private区域
	{	
		cout << "singleton()" << endl;
	}
	~singleton()
	{
		cout << "~singleton" <<endl;
	}
private:
	static singleton * _pInstance;//静态成员数据
};

singleton * singleton::_pInstance=NULL;
//静态成员数据的初始化必须放在类之外进行

void func()
{
	cout << "func()" << endl;
	singleton * p1=singleton::getInstance();
}

//singleton s3;//全局静态区开空间
//singleton s4;//不能为全局对象

int main()
{
	//singleton s1;//栈上开空间
	//singleton s2;//不能为栈对象

	singleton * p1=singleton::getInstance();//获取一个对象
	singleton * p2=singleton::getInstance();
	singleton * p3=singleton::getInstance();
	printf("p1=%p\n",p1);
	printf("p2=%p\n",p2);
	printf("p3=%p\n",p3);
	func();	
	singleton::destroy();
	//singleton * p1=new singleton;//堆上开空间
	//singleton * p2=new singleton;//不能调用private构造函数


}
