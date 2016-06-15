 ///
 /// @file    operator_overload.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-15 17:22:01
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//使用复数的运算学习操作符重载

class Complex
{
public:
	Complex(double dreal,double dimag)
	: _dreal(dreal)
	, _dimag(dimag)
	{
		cout << "Complex(double,double)" << endl;
	}
	
	void display()
	{
		if(_dreal!=0)
		{
			cout<<_dreal;
			if(_dimag>0)
			{
				cout<<"+"<<_dimag<<"i"<<endl;
			}
			else if(_dimag<0)
			{
				cout<<"-"<<_dimag*(-1)<<"i"<<endl;
			}
			else
				cout << endl;
		}
		if(_dreal==0)
		{
			if(_dimag>0)
			{
				cout<<_dimag<<"i"<<endl;
			}
			else if(_dimag<0)
			{
				cout<<"-"<<_dimag*(-1)<<"i"<<endl;
			}
			else
				cout << endl;
		}
	}
private:
	double _dreal;
	double _dimag;
};

#if 0
//内置类型的运算符功能不能进行重载
//运算符重载对形参的要求是类类型或枚举类型
int operator+(int a,int b)
{
	return a-b;
}
#endif


int main()
{
	Complex c1(0,-2);
	Complex c2(-1,4);
	c1.display();
	c2.display();
}
