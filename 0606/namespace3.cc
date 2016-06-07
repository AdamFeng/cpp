 ///
 /// @file    namespace3.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-07 17:46:01
 ///


//.c文件代表一个模块，多个模块之间的交互实现信息隐藏

#include <iostream>//头文件,没有.h，使用模板编写

//using namespace std;//编译指令
using std::cout;
using std::endl;

namespace wd
{
	int a=3;
	void func1()
	{
		//cout 标准输出流对象
		cout<<"func1()"<<endl;//<<运算符重载
	}
}

namespace A
{
	int num=100;
	void displayA()
	{
		cout<<"A::displayA()"<<endl;
	}
}

using A::displayA;//using声明机制

namespace B
{
	int num=1000;
	void displayB()
	{
		displayA();
		cout<<"B::displayB()"<<endl;
	}
}

int main()
{
	//使用作用域限定符
	cout<<wd::a<<endl;//直接打印wd中的a
	wd::func1();//直接调用wd中的func1
	B::displayB();//直接调用B中的displayB()
	
	cout<<A::num<<endl;
	cout<<B::num<<endl;
}
