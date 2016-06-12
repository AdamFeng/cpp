 ///
 /// @file    ifstream.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-12 14:04:28
 ///
 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

int main()
{
	ifstream ifs("vector.cc");//定义文件流对象,要求所读文件是存在的
	if(!ifs.good())//ifs流是否准备好
	{
		cout << "ifstream open error" << endl;
		return -1;
	}
	
	vector<string> vecstr;//定义容器
	vecstr.reserve(100);//预分配空间
	string str;
	
	//while(ifs >> str)//空格分隔
	while(getline(ifs,str))// \n分隔
	{
		//cout << str << endl;
		vecstr.push_back(str);//str中数据放入vecstr容器中
	}
	
	//auto int a;//C++11之前：auto--int a;默认带auto

	for(auto & elem : vecstr)//C++11之后,可以自动推断变量类型
	{//引用形式,遍历vecstr中的元素
		cout << elem << endl;
	}

	ifs.close();
	return 0;
}
