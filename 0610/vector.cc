#include<iostream>
#include<vector>

using namespace std;

void printNum(vector<int> & vec)//使用引用进行参数传递
{
	cout << "vec'size=" << vec.size() << endl;
	cout <<	"vec'capacity=" << vec.capacity() << endl;
}
//vector具有动态增长的功能,动态增长方式由编译器决定
int main(void)
{
	vector<int> vec;
	vec.reserve(100);//预先开辟一定的空间
	
	printNum(vec);
	vec.push_back(1);
	printNum(vec);
	vec.push_back(2);	
	printNum(vec);
	vec.push_back(3);	
	printNum(vec);
	vec.push_back(4);	
	printNum(vec);
	vec.push_back(5);	
	printNum(vec);
	vec.push_back(6);	
	printNum(vec);
	vec.push_back(7);	
	printNum(vec);
	vec.push_back(8);	
	printNum(vec);
	vec.push_back(9);	
	printNum(vec);

	for(int i=0;i!=vec.size();i++)
	{//下标访问
		cout << vec[i] << " ";
	}
	cout << endl;

	vector<int>::iterator vit;//迭代器
	for(vit=vec.begin();vit!=vec.end();vit++)
	{//访问vector中的内容
		cout << *vit << " ";	
	}
	cout << endl;
		
	return 0;
}
