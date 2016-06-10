 ///
 /// @file    point2.cc
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
private:
	int _ix;
	int _iy;
};


int main()
{
	point pt1(1,2);
	pt1.print();

	point pt2(5);//显式调用构造函数
//	point pt2=5;//隐式转换-->通过构造函数完成
	pt2.print();

	return 0;
}

