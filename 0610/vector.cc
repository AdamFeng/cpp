#include<iostream>
#include<vector>

using namespace std;

void printNum(vector<int> & vec)//ʹ�����ý��в�������
{
	cout << "vec'size=" << vec.size() << endl;
	cout <<	"vec'capacity=" << vec.capacity() << endl;
}
//vector���ж�̬�����Ĺ���,��̬������ʽ�ɱ���������
int main(void)
{
	vector<int> vec;
	vec.reserve(100);//Ԥ�ȿ���һ���Ŀռ�
	
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
	{//�±����
		cout << vec[i] << " ";
	}
	cout << endl;

	vector<int>::iterator vit;//������
	for(vit=vec.begin();vit!=vec.end();vit++)
	{//����vector�е�����
		cout << *vit << " ";	
	}
	cout << endl;
		
	return 0;
}