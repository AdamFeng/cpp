 ///
 /// @file    computer2.cc
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
//-----------------------------------------------------------
#if 0
	//缺省的复制构造函数
	computer(const computer & rhs)
	: _brand(rhs._brand)//浅拷贝：传递的地址值,指向堆空间同一块区域,
		//调用析构函数会出现double free问题
		//此时此析构函数不再适用，需自己显式定义复制构造函数
	, _price(rhs._price)
	{
		cout << "浅computer(const computer & rhs)" << endl;
	}
#endif
#if 1
	//若参数为对象，发生复制构造时，会导致无限递归，直到栈溢出
	//所以参数只能为引用
	computer(const computer & rhs)//自定义复制构造函数
	: _price(rhs._price)
	{//深拷贝
		_brand=new char[strlen(rhs._brand)+1];
		strcpy(_brand,rhs._brand);
		cout << "深computer(const computer & rhs)" <<endl;
	}
#endif
//-----------------------------------------------------------

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

	computer com1=com;
	com1.print();

	return 0;
}
