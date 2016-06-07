 ///
 /// @file    namespace2.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-07 17:46:01
 ///


//.c文件代表一个模块，多个模块之间的交互实现信息隐藏

#include <iostream>

//using namespace std;//编译指令
using std::cout;
using std::endl;

namespace wd
{
	int a=3;
	void func1()
	{
		//cout 标准输出流对象
		cout<<"func1()"<<endl;// <<运算符重载
	}
}

namespace A
{
	void displayA()
	{
		cout<<"A::displayA()"<<endl;
	}
}

using A::displayA;//using声明机制

namespace B
{
	void displayB()
	{
		displayA();
		cout<<"B::displayB()"<<endl;
	}
}

int main()
{
	cout<<wd::a<<endl;//直接打印wd中的a
	wd::func1();//直接调用wd中的func1
	B::displayB();//直接调用B中的displayB()
}
