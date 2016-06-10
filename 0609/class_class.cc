 ///
 /// @file    class_class.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-09 10:25:52
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class point
{
public:
	point()//无参构造函数
	{
		cout << "wucan point" << endl;
	}
	//构造函数
	point(int ix,int iy)
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
	}

	void print()
	{
		cout << "(" << _ix << "," << _iy << ")" << endl;
	}
private:
	int _ix;
	int _iy;
};

class line
{
public:	
	line(int x1,int y1,int x2,int y2)
	: _pt1(x1,y1)//调用point类中的构造函数
	, _pt2(x2,y2)
	//: _pt1()//调用point中的无参构造函数
	//, _pt2()
	{
		cout << "lint(int,int,int,int)" << endl;
	}

	void draw()
	{
		_pt1.print();
		cout << "to";
		_pt2.print();
	}
private:
	point _pt1;
	point _pt2;
};

int main()
{
	line li(1,2,3,4);
	li.draw();

	return 0;
}

