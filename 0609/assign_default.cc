 ///
 /// @file    point3.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-09 10:25:52
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class point
{
public:
	//构造函数--explicit作用为此构造函数只能显式调用
	//不可以隐式转换
	explicit point(int ix=0,int iy=0)
	:_ix(ix)//初始化列表
	,_iy(iy)
	{
		cout << "point(int ,int )" << endl;
	}
	
	//复制构造函数
	point(const point & rhs)
	: _ix(rhs._ix)//初始化列表
	, _iy(rhs._iy)
	{
		cout << "point(const point&)" << endl;
	}

	void print()
	{
		cout << "(" << _ix << "," << _iy << ")" << endl;
	}
//------------------------------------------------------

	//默认赋值运算符函数
	point & operator=(const point & rhs)
	{
		_ix=rhs._ix;
		_iy=rhs._iy;
		cout << "operator=(const point & rhs)" << endl;
	}
private:
	int _ix;
	int _iy;
};


int main()
{
	int a=3,b=4;
	a=b;//赋值操作

	point pt1(1,2);
	point pt2(3,5);
	pt1=pt2;//赋值运算符函数,pt1在之前已经创建
	point pt3=pt1;//复制构造函数,pt3在之前没有创建
	pt1.print();
	pt2.print();
	pt3.print();

	return 0;
}

