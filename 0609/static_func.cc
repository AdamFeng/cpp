 ///
 /// @file    computer.cc
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
	computer(const char* brand,float price)
	: _price(price)
	{
		cout << "computer(const char *,float)" << endl;
		_brand=new char[strlen(brand)+1];
		strcpy(_brand,brand);
		_totalprice+=_price;
	}

	~computer()
	{
		delete [] _brand;
		cout << "~computer" << endl;
		_totalprice-=_price;
	}
public:
	//对静态成员函数而言，函数参数列表之中不包含this指针
	//可以直接通过类名来调用
	//在静态成员函数里,只能调用静态数据成员,不能调用非静态数据成员
	static void print(computer & com)
	{
		cout << "brand:" << com._brand <<endl;
		cout << "price:" << com._price <<endl;
		printtotalprice();//调用静态成员函数
	}
private://只能在此类内进行调用
	static void printtotalprice()
	{//访问静态数据成员
		cout << "totalprice:" << _totalprice << endl;
	}
private:
	char * _brand;
	float _price;
	static float _totalprice;
};

float computer::_totalprice=0;

int main()
{
	computer pc1("IBM",4000);
	//pc1.print(pc1);//没有this指针,需要传参
	computer::print(pc1);//直接使用类名调用print方法

	//private属性的静态成员函数不能在main函数进行调用
	//computer::printtotalprice();

	{
		computer pc2("Mac",10000);
		computer:: print(pc2);
	}
	computer::print(pc1);

	return 0;
}
