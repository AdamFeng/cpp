 ///
 /// @file    point.cc
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
	point(int ix=0,int iy=0)
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
private:
	int _ix;
	int _iy;
};

//当形参和实参都是对象，形参和实参进行结合时
//会调用复制构造函数
void func(point pt)//传递point对象pt
{
	pt.print();
}

//返回值优化功能，看不到复制构造函数的调用
//在编译时 -fno-elide-constructors  可以看到
point func2()
{
	point pt(5,6);
	pt.print();
	return pt;
}

int main()
{
	point pt1(1,2);
	point pt2(pt1);//调用复制构造函数

	pt1.print();
	pt2.print();

	cout << endl;
	func(pt2);

	cout << endl;
	func2();

	return 0;
}

