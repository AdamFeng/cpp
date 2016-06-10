 ///
 /// @file    const_func.cc
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
		cout << "point(int,int)" << endl;
	}
	
	//复制构造函数
	point(const point & rhs)
	: _ix(rhs._ix)//初始化列表
	, _iy(rhs._iy)
	{
		cout << "point(const point&)" << endl;
	//	rhs.setX(10);
	}

	//后加const,本质将参数改为const point * const this
	void print(/*point * const this缺省参数*/) const
	{
		//this=0x000;//无法修改地址，const
		//this->_ix=10;//error,不能修改
		cout << "print() const" << endl;
		cout << "(" << _ix << "," << _iy << ")" << endl;
	}
//两个print()构成重载
	void print()
	{
		cout << "print()" << endl;
		cout << "(" << _ix << "," << _iy << ")" << endl;
	}

	void setX(int x)//非const成员函数
	{
		_ix=x;
	}
private:
	int _ix;
	int _iy;
};


int main()
{
	point pt1(1,2);
	pt1.print();

	const point pt2(3,4);
	pt2.print();
//	pt2.setX(10);//const对象不能调用非const成员函数
}
