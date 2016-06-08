 ///
 /// @file    io.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-08 16:27:40
 ///

#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
	string s;

	//while(cin>>s) //以空格来对字符串进行分割
	//	cout << s << endl;
	
	while(getline(cin,s))//回车键分割
		cout << s << endl;
}
