#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using std::cout;
using std::endl;

//只能开辟堆空间
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
	void print()
	{
		cout << "id   =" << _id << endl;
		cout << "name =" << _name << endl;
	}
	void destroy()
	{
		//this->~student();//调用析构函数
		//不会delete堆空间，所以有可能出错
		delete this;
	}
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
private://类之外不再适用
	~student()//析构函数
	{
		delete [] _name;
		cout << "~student " << endl;
	}

private:
	int _id;
	char * _name;
};

int main()
{
	//student s(101,"Adam");//栈对象调用不成功
	//因为析构函数在private区域，所以无法调用

	student * p=new student(100,"adam");//看不到空间的开辟
	p->print();

	p->destroy();
//	delete p;
}
