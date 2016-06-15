 ///
 /// @file    ifstream.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-15 20:58:48
 ///
 
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::ifstream;

int main()
{
	ifstream ifs("A.cc");
	if(!ifs.good())
	{
		cout << "ifstream open error" << endl;
		return -1;
	}

	//流类型都不能进行复制
	//ifstream ifs2(ifs);//调用复制构造函数？

	ifs.close();
}
