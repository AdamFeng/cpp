 ///
 /// @file    reference.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-07 21:42:54
 ///
 
#include <iostream>
using std::cout;
using std::endl;



int main()
{
	int a=10;
	int b=20;
	&a;
	cout<<"a="<<a<<endl;

	int & refa=a;//&引用，就是变量的一个别名
		//引用一经初始化，不会改变指向
	refa=5;
	cout<<"refa="<<refa<<endl;
	cout<<"a="<<a<<endl;

	//int & refb;//引用不能独立存在，必须要进行初始化

	refa=b;//把b的值赋给a
	cout<<"refa="<<refa<<endl;
	cout<<"a="<<a<<endl;

	//int &refc=1;//1字面值(literal)
	//&1//error
	const int &refc=1;
	cout<<"refc="<<refc<<endl;
	return 0;
}
