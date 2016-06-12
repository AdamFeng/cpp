 ///
 /// @file    stream_status.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-11 20:43:26
 ///
 
#include <iostream>
#include <string>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void printCin()
{
	cout << "badbit=" << cin.bad() << endl;//系统级故障,不可恢复
	cout << "failbit=" << cin.fail() << endl;//可恢复的错误
	cout << "eofbit=" << cin.eof() << endl;//碰到文件尾
	cout << "goodbit=" << cin.good() << endl;//有效状态
}

int main()
{
	int inum;
	printCin();
	while(cin >> inum)
		cout << "inum=" << inum <<endl;

	printCin();
	cin.clear();//重置所有状态
	cout << endl;
	printCin();

	//清空缓冲区(跳过缓冲区中max个数据,\n将max个数据全部丢掉)
	cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

	string s;
	cin >> s;
	cout << s << endl;

	return 0;
}
