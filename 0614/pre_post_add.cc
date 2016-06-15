 ///
 /// @file    pre_post_add.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-15 17:22:01
 ///

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

//以成员函数进行++重载,前置后置

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

	//前置++效率高于后置++
	Complex & operator++()
	{
		++(this->_dreal);
		++(this->_dimag);
	}

	//为了区分前置++和后置++
	//在后置++的成员函数的参数列表之中添加一个int作为标记
	//该int并不是形参
	Complex operator++(int)
	{
		Complex tmp(*this);
		++(this->_dreal);
		++(this->_dimag);
		return tmp;
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

	(c1++).display();
	(++c2).display();
	c1.display();
	c2.display();
	
}
