 ///
 /// @file    operator_overload_friendfunc.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-15 17:22:01
 ///

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

//以友元函数进行操作符重载

class Complex
{
	friend Complex operator+(const Complex & lhs,const Complex & rhs);
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

Complex operator+(const Complex & lhs,const Complex & rhs)
{
	return Complex(lhs._dreal+rhs._dreal,lhs._dimag+rhs._dimag);
}

int main()
{
	Complex c1(0,-2);
	Complex c2(-1,4);
	c1.display();
	c2.display();

	Complex c3=c1+c2;
	c3.display();
}
