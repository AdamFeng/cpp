 ///
 /// @file    string.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-13 10:24:08
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class String
{
public:
	String();
	String(const char* pstr);
	String(const String & rhs);
	String & operator=(const String & rhs);
	~String();
	void print();
private:
	char * _pstr;
};

String::String()//默认无参构造函数
{
	cout << "String()" << endl;
	_pstr=new char;
}
String::String(const char * pstr)//带参数的构造函数
{
	cout << "String(const char * pstr)" << endl;
	_pstr=new char[strlen(pstr)+1];
	strcpy(_pstr,pstr);
}
String::String(const String & rhs)//复制构造函数
{
	cout << "String(const String & rhs)" << endl;
	_pstr=new char[strlen(rhs._pstr)+1];
	strcpy(_pstr,rhs._pstr);
}
String &/*注意此处的写法*/ String::operator=(const String & rhs)//赋值运算符函数
{
	cout << "String & operator=(const String & rhs)" << endl;
	if(&rhs==this)
		return *this;
	delete [] _pstr;
	_pstr=new char[strlen(rhs._pstr)+1];
	strcpy(_pstr,rhs._pstr);
	return *this;
}
String::~String()//析构函数
{
	cout << "~String()" << endl;
	delete [] _pstr;
}
void String::print()
{
	cout << "String=" << _pstr << endl;
}

int main()
{
	String str1;
	str1.print();

	String str2="hello,world";
	String str3="wangdao";

	str2.print();
	str3.print();
	str2=str3;
	str2.print();

	String str4=str3;
	str4.print();
	return 0;
}
