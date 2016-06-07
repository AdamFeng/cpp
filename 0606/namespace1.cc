 ///
 /// @file    namespace1.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-06 17:11:42
 ///
 
#include <iostream>

using namespace std;//编译指令

namespace wd
{
	int a=3;
	void func1()
	{
		cout << "func1"<< endl;
	}
}

namespace A
{
	void displayA()
	{
		cout<<"A::displayA()"<<endl;
	}
}

namespace B
{
	void displayB()
	{
		A::displayA();
		cout << "B::displayB()"<<endl;
	}
}

using namespace wd;

int main()
{
	cout<<wd::a<<endl;//使用作用域限定符
	wd::func1();

	B::displayB();
	return 0;
}
