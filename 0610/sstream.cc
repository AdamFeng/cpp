 ///
 /// @file    sstream.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-12 15:35:56
 ///

//字符串的输入输出流主要进行字串的格式转换

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::istringstream;
using std::ostringstream;
using std::stringstream;

string int2str(int idx)
{
	ostringstream oss;//输出流
	oss << idx;//int --> string
	return oss.str();//返回string类型
}

void func()
{
	string line="hello,shenzhen tianqi buhao";
	istringstream iss(line);//输入流
	string word;//获取以空格分隔的每个字串
	while(iss >> word)//将输入流中的字串输入到word中
	{
		cout << word << endl;
	}
}

int test()
{//字符串输入输出流可以进行数据类型转换
// int --> string       string --> int
	int i1=512;
	int i2=1024;
	stringstream ss;//创建字符串的输入输出流
	//ss << "i1= " << i1 << ",i2= " << i2 << endl;//写入ss流中
	ss << i1 << " " << i2 << endl;//写入ss流中

	string str=ss.str();//调用ss.str()创建字符串，
					//将ss流中的数据写入str字符串中
	cout << str << endl;

	int i3=0;
	int i4=0;
	ss >> i3;//将ss流中的数据写回到int型变量中
	cout << "i3=" << i3 << endl;
	ss >> i4;
	cout << "i4=" << i4 << endl;
#if 0
	while(ss >> str)//输入输出流写回到字符串中
	{//以空格分隔
		cout << str << endl;
	}
	cout << endl;
#endif
	return 0;
}

int main()
{
	//test();

	int i1=512;
	int i2=1024;
	char arr[100];
	memset(arr,0,sizeof(arr));
	sprintf(arr,"i1=%d,i2=%d\n",i1,i2);
		//C语言中格式化输入到字符串中
	cout << arr << endl;

	string s1=int2str(i1);
	cout << s1 << endl;
	func();
	return 0;
}

