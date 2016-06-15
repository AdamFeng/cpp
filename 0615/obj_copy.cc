 ///
 /// @file    obj_copy.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-15 21:24:39
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//如果一个对象能够进行复制，表达的是值语义
//如果一个对象不能进行复制，表达的是对象语义

class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;//链式编程,两次<<
	}
private:
	//禁止复制：从语法层面去表达语义
	A(const A &);//复制构造函数
	A& operator=(const A &);//赋值运算符函数
};

int main()
{
	A a;//栈对象的创建需要析构函数

	//A b=a;//error,A类创建的对象不能进行复制,不能调用复制构造函数
	A c;
	//c=a;//error,不能调用复制运算符函数
}
