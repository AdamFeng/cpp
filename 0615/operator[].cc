 ///
 /// @file    operator[].cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-15 20:12:03
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class CharArr
{
public:
	CharArr(int size)
	: _size(size)
	{
		_pbuf=new char[_size];
	}

	~CharArr()
	{
		delete _pbuf;
	}

	int length()
	{
		return _size;
	}

	char & operator[](int i)//重载下标运算符，访问数组中元素
	{
		static char nullchar='\0';
		if(i<_size && i>=0)
		{
			return _pbuf[i];
		}else
		{
			cout << "overflow" << endl;
			return nullchar;
		}
	}
private:
	int _size;
	char * _pbuf;
};

int main()
{
	const char * p="hello,world!";//数据位于文字常量区
	CharArr ca(strlen(p)+1);

	for(int i=0;i<ca.length();++i)
	{
		ca[i]=p[i];
	}

	for(int i=0;i<ca.length();++i)
	{
		cout << ca[i];
	}
	cout << endl;
}
