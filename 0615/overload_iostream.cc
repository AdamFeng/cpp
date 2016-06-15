 ///
 /// @file    overload_iostream.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-15 17:22:01
 ///

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

//输入输出运算符函数，必须以友元函数进行重载
//不能是成员函数，其返回值类型必须是流对象的引用
class Complex
{
	friend std::ostream & operator<<(std::ostream & os,const Complex & rhs);
	friend std::istream & operator>>(std::istream & is,Complex & rhs);
	friend Complex operator+(const Complex & lhs,const Complex & rhs);
public:
	Complex(double dreal=0,double dimag=0)
	: _dreal(dreal)
	, _dimag(dimag)
	{
		cout << "Complex(double,double)" << endl;
	}
	
private:
	double _dreal;
	double _dimag;
};

Complex operator+(const Complex & lhs,const Complex & rhs)
{//自由函数重载+
	return Complex(lhs._dreal+rhs._dreal,lhs._dimag+rhs._dimag);
}

std::ostream & operator<<(std::ostream & os,const Complex & rhs)
{//友元函数重载<<输出
	if(rhs._dreal!=0)
	{
		cout<<rhs._dreal;
		if(rhs._dimag>0)
		{
			os<<"+"<<rhs._dimag<<"i";
		}
		else if(rhs._dimag<0)
		{
			os<<"-"<<rhs._dimag*(-1)<<"i";
		}
	}

	if(rhs._dreal==0)
	{
		if(rhs._dimag>0)
		{
			os<<rhs._dimag<<"i"<<endl;
		}
		else if(rhs._dimag<0)
		{
			os<<"-"<<rhs._dimag*(-1)<<"i"<<endl;
		}
	}
	return os;
}

std::istream & operator>>(std::istream & is,Complex & rhs)
{//友元函数重载>>输入
	is >> rhs._dreal;
	while(is.get()!='*');
	is >> rhs._dimag;
	return is;
}

int main()
{
	Complex c1(0,-2);
	Complex c2(-1,4);

	cout << "c1=" << c1 << endl;
	cout << "c2=" << c2 << endl;

	Complex c3=c1+c2;
	cout << "c3=" << c3 << endl;

	Complex c4;
	std::cin >> c4;
	cout << "c4=" << c4 << endl;
	
}
