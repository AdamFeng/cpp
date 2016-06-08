 ///
 /// @file    static_cast.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-07 22:50:16
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//强制转换
int main()
{
	//C 强转
	double b=3.13;
	int a=(int)b;//将b强转为int
	int c=int(b);//将b强转为int
	cout<<"a="<<a<<endl;
	cout<<"c="<<c<<endl;

	//C++ 强转
	int d=static_cast<int>(b);
		//static_cast<目标类型>(原参数)
	cout<<"d="<<d<<endl;

	//查找进行了强转的地方 grep查找static_cast
	//const_cast,dynamic_cast,reinterpret_cast

	return 0;
}
