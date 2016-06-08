 ///
 /// @file    const.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-07 19:45:38
 ///
 
#include <iostream>
using std::cout;
using std::endl;

#define MAX 100
/*
 发生时机：预编译时
 简单的字符串替换，不具备类型检查功能
 有可能把错误带到运行时
 */
/*
 const int a=1;
	const发生时机：编译时，具备类型检查功能
 */
int main()
{
	const int a=1;//const修饰的变量时不能被修改的（常量）
	//const int b;//error，常量必须进行初始化
	int const b=2;//也是定义const常量
//--------------------------------------------------

	int c=3;//变量c

	const int* pa=&c;//pointer to const，常量指针
	//*pa=4;//error
	int const* pb=&c;//等同于const int*
	//const在*前，即为常量指针
	pa=&a;//常量指针可以改变指针的指向
	cout<<"*pa="<<*pa<<endl;

	int* const pc=&c;//const pointer，指针常量
		//const在*后，指针常量
	//指针常量是常量，在声明时需要赋值
	*pc=4;//指针常量所指向的变量的值是可以更改的
	cout<<"*pc="<<*pc<<endl;
	cout<<"c="<<c<<endl;
	//pc=&a;//const作用：指针常量的指向对象不能更改


	const int* const pd=&c;
	//*pd=5;//error,解引用修改值报错
	//pd=&a;//error,指针指向的变量不能更改

	return 0;
}
