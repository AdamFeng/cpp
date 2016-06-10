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
#if 0
	//缺省赋值运算符函数
	computer & operator=(const computer & rhs)
	{
		_brand=rhs._brand;
		_price=rhs._price;
		cout << "operator=(const computer & rhs)" <<endl;
	}
#endif
#if 1
	//自定义赋值运算符函数
	computer & operator=(const computer & rhs)//&为引用
	{
		if(this==&rhs)//自复制,&为取地址
			return *this;

		delete [] _brand;//释放对象原来开辟的空间

		_brand=new char[strlen(rhs._brand)+1];//深拷贝
		strcpy(_brand,rhs._brand);
		_price=rhs._price;
		cout << "operator=(const computer & rhs)" <<endl;
		
		return *this;//this代表对象本身
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

	void print(/*computer * this*/)
	{
		cout << "brand:" << this->_brand <<endl;
		cout << "price:" << this->_price <<endl;
	}
private:
	char * _brand;
	float _price;
};


int main()
{
	computer com("Dell",400);//在栈上,局部对象
	//定义时调用构造函数，离开作用域时调用析构函数
	com.print();//调用此函数时，传递this指针，this指向com对象本身

	computer com1("IBM",574);
	com1.print();

	com1=com;//调用自定义赋值运算符函数com.operator=(pc)
	com1.print();

	return 0;
}
