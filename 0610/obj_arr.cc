 ///
 /// @file    obj_arr.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-09 10:25:52
 ///对象数组
 
#include <iostream>
using std::cout;
using std::endl;

class point
{
public:
	point()
	: _ix(0)
	, _iy(0)
	{
		cout << "point()" << endl;
	}

	//构造函数--explicit作用为此构造函数只能显式调用
	//不可以隐式转换
	explicit point(int ix,int iy)
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

	~point()
	{
		cout << "~point" << endl;
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
	//point arr[5];
	//point(5,6);//匿名对象,创建后马上被销毁(又名临时对象),无法获取地址

	point arr2[5]={point(1,2),point(3,4)};
		//可通过arr访问，匿名对象不再匿名
		//前两个调用自定义构造函数
		//后三个调用无参构造函数
	arr2[0].print();
	arr2[1].print();
	arr2[2].print();
	arr2[3].print();
	arr2[4].print();
	
	return 0;
}

