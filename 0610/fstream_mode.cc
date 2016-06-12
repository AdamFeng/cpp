 ///
 /// @file    fstream_mode.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-12 14:48:05
 ///
 
#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;

int test0()
{
	//ofstream ofs("test",std::iso::ate);
	//ate对输出流不起作用，会清空test里的数据
	
	ofstream ofs("test",std::ios::app);//在test末尾添加
	if(!ofs.good())
	{
		cout << "ofstream open error" << endl;
		return -1;
	}
	cout << ofs.tellp() << endl;//打印文件指针的末尾位置
	string str="new";
	cout << ofs.tellp() << endl;
	ofs.close();
	return 0;
}

int test1()
{
	ifstream ifs("test",std::ios::ate);
	//ate对输入流起作用，打开后定位到文件末尾
	
	if(!ifs.good())
	{
		cout << "ifstream open error" << endl;
		return -1;
	}
	cout << ifs.tellg() << endl;//打印文件指针的末尾位置
	return 0;
}

int main()
{
	fstream fs("test");//要求文件存在
	//文件的输入输出流使用同一个指针,打开后指针在文件头
	if(!fs.good())
	{
		cout << "fstream open error" << endl;
		return -1;
	}
	int num;
	for(int i=0;i!=10;i++)
	{
		cin >> num;
		fs << num << " ";
	}

	cout << fs.tellp() << endl;//文件指针在文件末尾
	fs.seekp(0,std::ios::beg);//移动文件指针到文件头

	for(int i=0;i<10;i++)
	{
		fs >> num;
		cout << num << " ";
	}
	cout << endl;

	cout << fs.tellp() << endl;

	fs.close();
	return 0;
}
