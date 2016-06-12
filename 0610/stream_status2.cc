 ///
 /// @file    stream_status2.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-11 21:08:57
 ///

#include <limits>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int ival;
	while(cin >> ival, !cin.eof())//到达文件尾,退出循环
	{
		if(cin.bad())//不可恢复的错误
		{
			cout << "IO stream corrupted" << endl;
			return -1;
		}
		if(cin.fail())//可恢复的错误
		{
			cin.clear();//重置状态
			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			cout << "data illegal,try again" << endl;
			continue;
		}
		cout << "ival=" << ival << endl;
	}
}
