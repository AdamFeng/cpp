#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using std::cout;
using std::endl;

//只能生成栈对象,不能生成堆对象
class student
{
public:
	student(int id,const char * name)//构造函数
	: _id(id)
	{
		_name=new char[strlen(name)+1];
		strcpy(_name,name);
		cout << "student(int,const char*)"<<endl;
	}

	~student()//析构函数
	{
		delete [] _name;
		cout << "~student " << endl;
	}

	void print()
	{
		cout << "id   =" << _id << endl;
		cout << "name =" << _name << endl;
	}
//--------------------------------------------------------
private:
//operator new函数放入private区域,无法调用new,不能生成堆对象
	void* operator new(size_t count);
	void operator delete(void *p);

private:
	int _id;
	char * _name;
};

int main()
{
//	student * p=new student(100,"adam");//看不到空间的开辟
//	p->print();

	student s(123,"Jack");
	s.print();
}
