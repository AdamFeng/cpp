 ///
 /// @file    class_friend.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-15 16:07:50
 ///

#include <math.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

//友元类

class Point;//前向声明，使Line可以使用Point类声明函数

class Line
{
	//Line的每一个成员函数都成为Point类的友元函数
public:
	float distance(const Point & p1,const Point & p2);
	void set(Point * p,int x,int y);
};

class Point
{
	friend Line;//友元类。友元不能继承,无属性
	//friend class Line;//也可声明友元类
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
	return sqrt((p1._ix-p2._ix)*(p1._ix-p2._ix)+
				(p1._iy-p2._iy)*(p1._iy-p2._iy));
}

void Line::set(Point * p,int x,int y)
{
	p->_ix=x;
	p->_iy=y;
}

int main()
{
	Line line;//要使用Line的一个对象来调用distance方法
	Point pt1(1,2);
	Point pt2(3,4);
	cout << "distance=";
	cout<<line.distance(pt1,pt2)<<endl;

	cout << endl;
	line.set(&pt1,10,11);
	cout << "distance=";
	cout<<line.distance(pt1,pt2)<<endl;
}
