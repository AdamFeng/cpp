 ///
 /// @file    const_init.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-09 10:25:52
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class point
{
public:
	//构造函数
	point(int ix=0,int iy=0)
	:_ix(ix)//const数据成员只能在初始化列表进行初始化
	,_iy(iy)
	{
		cout << "point(int ,int )" << endl;
		//_ix=ix;//赋值语句,并不是初始化
		//_iy=iy;
	}
	
	void print()
	{
		cout << "(" << _ix << "," << _iy << ")" << endl;
	}
#if 0
	void setX(int ix)
	{
		_ix=ix;//const数据成员不能被修改
	}
#endif
private:
	const int _ix;
	const int _iy;
};

int main()
{
	point pt1(1,2);
	pt1.print();


	return 0;
}

