 ///
 /// @file    computer.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-08 11:06:32
 ///
#include<stdio.h> 
#include<string.h>
#include <iostream>
using std::cout;
using std::endl;

class computer
{
	public://与类中变量有关的函数
		computer()//默认构造函数
		{
			cout<<"默认构造函数"<<endl;
		}
		void setbrand(const char * brand);
		void setprice(float price);
		void print();
	private://类中的变量
		char _brand[10];
		float _price ;
};
//-----------------一般写在头文件-------------------------

//类中函数的实现，必须加上类名
void computer::setbrand(const char * brand)
{
	strcpy(_brand,brand);
}
void computer::setprice(float price)
{
	_price=price;
}
void computer::print()
{
	cout<<"brand:"<<_brand<<endl;
	cout<<"price:"<<_price<<endl;
}

int main()
{
	computer com;//创建对象时调用构造函数
	com.setbrand("Mac");
	com.setprice(100);
	com.print();
}

