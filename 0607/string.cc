 ///
 /// @file    string.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-08 15:54:39
 ///

#include <stdio.h>
#include <string.h>

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int test0()
{//C++字符串操作
	int a=3;
	string s1="hello";
	string s2=",world";
	string s3=s1+s2+"shenzhen";//字符串拼接，类型const char *
	cout << s3 <<endl;
	cout << endl;
	cout << "sizeof(string)=" << sizeof(string) <<endl;//string类型大小为4
	cout << "s3.size()=" <<s3.size() <<endl;//字符串长度

	string s4="hello,world,world";
	string s5=s4.substr(0,5);//取字串
	cout << "s5=" <<s5 <<endl;

	int p=s4.find("world");
	cout << "p="<< p <<endl << endl;
	string s6=s4.substr(s4.find("world"),5);
		//find返回world开始时的下标位置
	cout<< "s6=" <<s6 <<endl;

	for(int i=0;i!=s4.size();i++)
	{
		cout << s4[i] << endl;
		s4[i]+=1;
	}
	cout << "s4="<<s4 << endl;

	string::iterator begin=s4.begin();
	string::iterator end=s4.end();
	printf("&begin=%p\n",&begin);
	printf("&end  =%p\n",&end);

	//通过迭代器方式进行访问,迭代器可理解为指针
	string::iterator it=s4.begin();
	for(;it!=s4.end();it++)
	{
		cout << *it <<endl;
	}
	cout << endl;

	return 0;
}

int test1()
{
	char pstr[]="hello,world";

	char pstr1[]="hello";
	char pstr2[]=",world";

	char* pstr3=new char[20];
	strcpy(pstr3,pstr1);
	strcat(pstr3,pstr2);//C字符串拼接
	cout << "pstr3=" << pstr3 <<endl;
	delete [] pstr3;

	char pstr4[]="hello,world";
	char* p=strstr(pstr4,"world");//查找字串

	cout << "p=" <<p<<endl;
	return 0;
}

int main()
{
	cout<<"test1"<<endl;
	test1();
	cout << "test0" << endl;
	test0();
}
