 ///
 /// @file    memfunc_friend.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-15 16:07:50
 ///

#include <math.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

//友元函数之成员函数

class Point;//前向声明，使Line可以使用Point类声明函数

class Line
{//Line的成员函数作为Point的友元函数时，必须先定义Line
public:
	float distance(const Point & p1,const Point & p2);
};

class Point
{
	friend float Line::distance(const Point & p1,const Point & p2);
public:
	Point(int ix=0,int iy=0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}
	~Point()
	{
		cout<<"~Point()"<<endl;
	}
	void print()
	{
		cout<<"("<<_ix<<","<<_iy<<")"<<endl;
	}
private:
	int _ix;
	int _iy;
};


float Line::distance(const Point & p1,const Point & p2)
{
//使用匿名临时对象时，默认存在语句Point & p1=Point(1,2);
//编译不会通过，因为临时对象无法绑定到引用上，
//加上const关键字之后就可以绑定到临时对象上了
	return sqrt((p1._ix-p2._ix)*(p1._ix-p2._ix)+
				(p1._iy-p2._iy)*(p1._iy-p2._iy));
}

int main()
{
	Line line;//要使用Line的一个对象来调用distance方法
	cout<<line.distance(Point(1,2),Point(3,4))<<endl;
//Point(1,2)和Point(3,4)是匿名临时对象，在定义中加const才能编译通过
}
