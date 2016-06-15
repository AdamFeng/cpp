 ///
 /// @file    func_call.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-15 20:03:05
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Demo
{
public:
	//函数调用运算符能传递多个参数，能够重载
	double operator()(double x,double y)
	{
		return x>y?x:y;
	}

	double operator()(double x,double y,double z)
	{
		return (x+y)*z;
	}
};

int main()
{
	Demo demo;
	cout<<"max="<<demo(1,4)<<endl;
	cout<<"(7+5)*3="<<demo(7,5,3)<<endl;
}
