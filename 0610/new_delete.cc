#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using std::cout;
using std::endl;

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

	void* operator new(size_t count)//重载new
	{
		cout << "operator new" <<endl;
		void * p=malloc(count);//开辟空间
		return p;
	}

	void operator delete(void *p)//重载delete,传递指针
	{
		cout << "operator delete" << endl;
		free (p);
	}
private:
	int _id;
	char * _name;
};

int main()
{
	student * p=new student(100,"adam");//看不到空间的开辟
	p->print();

	delete p;
}
