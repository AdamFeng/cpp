 ///
 /// @file    operator_overload_memfunc.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-15 17:22:01
 ///

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

//以成员函数进行操作符重载

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

	//返回值为对象
	Complex operator+(const Complex & rhs)
	{
		return Complex(this->_dreal+rhs._dreal,
					   this->_dimag+rhs._dimag);
	}

	//复合赋值运算符的返回值使用引用更合理
	Complex & operator+=(const Complex & rhs)
	{
		this->_dreal += rhs._dreal;
		this->_dimag += rhs._dimag;
		return *this;//原操作数发生变化
	}

private:
	double _dreal;
	double _dimag;
};



int main()
{
	Complex c1(2,-2);
	Complex c2(-1,4);
	c1.display();
	c2.display();

	c1+=c2;
	c1.display();
	c2.display();
	
}
