 ///
 /// @file    operator_pointer.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-15 22:01:43
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Data
{
public:
	int size()
	{
		return 5;
	}
};

class DataPtr
{
public:
	DataPtr()
	: _pData(new Data)//初始化_pData,指向一个Data对象
	{
		cout << "DataPtr()" << endl;
	}
	~DataPtr()
	{
		delete _pData;
		cout << "~DataPtr" << endl;
	}
	Data * operator->()
	{//重载操作符->
		return _pData;
	}
private:
	Data * _pData;
};

int main()
{
	DataPtr p;
	cout << p->size() << endl;//类似于下条语句
	//cout << (p.operator->())->size() << endl;
}
