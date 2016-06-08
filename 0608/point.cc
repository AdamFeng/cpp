 ///
 /// @file    point.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-08 11:23:09
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class point
{
public:
#if 0
	point()//构造函数可以进行重载
	{
		cout << "point()" << endl;
	}
	point(int ix,int iy)
	{
		cout << "point(int,int)" << endl;
		_ix=ix;
		_iy=iy;
	}
	point(int ix=0,int iy=0)//构造函数中可以设置缺省值
	{
		cout << "point(int,int)" << endl;
		_ix=ix;
		_iy=iy;
	}
#endif
	//初始化顺序只跟数据成员声明时的顺序有关
	//与在初始化列表中的顺序无关
	point(int ix,int iy)
	: _ix(ix)//初始化列表,对ix和iy初始化
	, _iy(iy)
	{
		cout << "point(int,int)" << endl;
		//_ix=ix;//赋值
		//_iy=iy;
	}
	void print()
	{
		cout << "(" <<_ix << "," << _iy << ")" << endl;
	}

private:
	int _ix;
	int _iy;

};

int main()
{
//	point p1;//调用默认构造函数
//	p1.print();

	point p2(3,4);
	p2.print();

//	point p3(5);
//	p3.print();

	return 0;
}
