 ///
 /// @file    struct.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-08 17:52:51
 ///
 
#include <iostream>
using std::cout;
using std::endl;

struct A
{//默认属性为public
	int ia;
	int ib;
};

class B
{
public:
	void setIa(int a)
	{
		ia=a;
	}
	void setIb(int b)
	{
		ib=b;
	}
private://默认属性为private
	int ia;
	int ib;
};

int main()
{
	int ix;
	A a;
	a.ia=10;
	a.ib=20;

	B b;
//	b.ia=1;
//	b.ib=2;
//	b.setIa(1);
//	b.setIb(2);

	return 0;
}
