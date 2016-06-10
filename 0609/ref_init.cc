 ///
 /// @file    ref_init.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-09 10:25:52
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class point
{
public:
	//构造函数
	point(int ix,int iy,double & dz)
	: _ix(ix)//const/引用数据成员只能在初始化列表进行初始化
	, _iy(iy)
	, _ref1(_ix)//引用，实体是_ix
	, _ref2(dz)
	{
		cout << "point(int,int,double)" << endl;
	}

	point(const point & rhs)//复制构造函数
	: _ix(rhs._ix)//复制，有独立空间
	, _iy(rhs._iy)
	, _ref1(rhs._ref1)//引用，实体是构造函数中的_ix
	, _ref2(rhs._ref2)//引用，实体是构造函数中的dz
	{
		cout << "point(const point & rhs)" << endl;
	}

	void print()
	{
		cout << "(" << _ix << "," << _iy << ")" << endl;
		cout << "(" << _ref1 << "," << _ref2 << ")" << endl;
	}

	void setX(int x)
	{
		_ix=x;
	}

private:
	 int _ix;
	 int _iy;
	 int & _ref1;
	 double & _ref2;
};
/*
引用只是别名，没有自己的空间，相当于指针，
引用的实体改变，所有指向该实体的引用值都改变
 */
int main()
{
	double dx=4.9;
	point pt1(1,2,dx);//调用构造函数
	pt1.print();

	point pt2(pt1);//调用复制构造函数
	pt2.print();
	cout << endl;

	pt1.setX(7);//将pt1中_ix设为7
	pt1.print();//pt1中_ix和ref1都改变
	pt2.print();//pt2中_ix不改变，ref1改变
	cout << endl;

	dx=7.6;
	pt1.print();
	pt2.print();
	
	return 0;
}

