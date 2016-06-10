 ///
 /// @file    static_value.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-09 10:00:03
 ///
#include <string.h> 
#include <iostream>
using std::cout;
using std::endl;

class computer
{
public:
	computer(float price)
	: _price(price)
	{
		cout << "computer(float)" << endl;
		_totalprice+=_price;
	}

	~computer()
	{
		cout << "~computer" << endl;
		_totalprice-=_price;
	}

	void print()
	{
		cout << "totalprice:" << _totalprice <<endl;
	}
private:
	float _price;
	static float _totalprice;//存储于全局静态区，在编译时就确定下来了
};

float computer::_totalprice=0.0;//static变量在main函数之外定义

int main()
{
	computer pc1(3000);//不包含静态数据成员
	pc1.print();
	computer pc2(5000);
	pc2.print();
	computer pc3(4000);
	pc3.print();

	pc2.~computer();
	pc2.print();

	//创建的是栈对象，只包含_price成员，没有static数据成员
	//大小为4
	cout << "sizeof(pc1)=" << sizeof(pc1) << endl;
	cout << "sizeof(computer)=" << sizeof(computer) << endl;


	return 0;
}
