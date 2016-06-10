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
	//构造函数
	computer(const/*不修改brand内容*/ char* brand,float price)
//	: _brand(brand)//不能直接给指针类型的变量直接赋值
	: _price(price)
	{
		cout << "computer(const char *,float)" << endl;
		_brand=new char[strlen(brand)+1];
		strcpy(_brand,brand);
	}

	//对于栈对象而言，创建时自动调用构造函数
	//销毁时自动调用析构函数
	~computer()
	{
		delete [] _brand;
		cout << "~computer" << endl;
	}
	//在类里面定义的成员函数都是inline函数
	//inline函数在调用他的地方会直接将函数执行体部分展开
	//没有函数调用的开销

	void print()
	{
		cout << "brand:" << _brand <<endl;
		cout << "price:" << _price <<endl;
	}
private:
	char * _brand;
	float _price;
};

computer pc("Mac",199);//全局对象
//程序开始时调用构造函数，
//程序结束时调用析构函数

int main()
{
	computer com("Dell",400);//在栈上,局部对象
	//定义时调用构造函数，离开作用域时调用析构函数
	com.print();

	//com.~computer();//显示调用析构函数，会重复销毁空间
	//析构函数就是用来清理空间的，不需要显示调用

	static computer pc1("Acer",1378);//局部静态对象
	//定义时调用构造函数,程序结束时调用析构函数

	computer * p=new computer("IBM",399);//new创建的对象
	//创建时调用构造函数,delete时调用析构函数
	delete p;

	return 0;
}
