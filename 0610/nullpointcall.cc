 ///
 /// @file    nullpointcall.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-10 10:53:26
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Nullpointer
{
public:
	static void test1();
	void test2();
	void test3(int i);
	void test4();

private:
	static int _istatic;
	int _itest;
};

int Nullpointer::_istatic=0;

void Nullpointer::test1()
{
//静态成员函数访问静态数据成员,只要有Nullpointer类即可
//p为空指针，类型为Nullpointer,所以可以访问静态数据成员
	cout << "static" << _istatic << endl;
}

void Nullpointer::test2()
{
	cout << "test2" << endl;
}

void Nullpointer::test3(int i)
{
	cout << "test3: i=" << i << endl;
}

void Nullpointer::test4()
//需要使用this指针调用_itest成员
//this指针为传入的p指针，p指针为空，所以访问出错
{
	cout << "test4: _itest=" << _itest <<endl;
}

int main()
{
	Nullpointer * p=NULL;
	p->test1();
	p->test2();
	p->test3(1);
//	p->test4();//error
}
