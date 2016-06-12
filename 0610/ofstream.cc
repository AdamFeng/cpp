 ///
 /// @file    ofstream.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-12 14:32:05
 ///
 
#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

int main()
{
	ifstream ifs("vector.cc");
	if(!ifs.good())
	{
		cout << "ifstream open error" << endl;
		return -1;
	}

	ofstream ofs("test");//不要求文件一定存在，有此文件会重建
	if(!ofs.good())
	{
		cout << "ofstream open error" << endl;
		return -1;
	}

	string str;
	//从ifs流中读数据输入到ofs流中
	while(getline(ifs,str))
	{
		ofs << str << endl;
	}

	ifs.close();
	ofs.close();
	return 0;
}
