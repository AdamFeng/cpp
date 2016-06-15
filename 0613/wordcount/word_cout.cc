 ///
 /// @file    word_cout.cc
 /// @author  viper(836505080@qq.com)
 /// @date    2016-06-13 19:37:09
 ///
 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Word
{
	string word;
	int num;
};

class WordStatic
{
public:
	void read_file();
	void write_file();
private:
	vector<struct Word> vec;
};

void WordStatic::read_file()
{
	ifstream ifs("The_Holy_Bible.txt");
	if(!ifs.good())
	{
		cout << "ifstream open error" << endl;
		return ;
	}
	vec.reserve(10000);
	string str;
	while(ifs >> str)
	{
		vector<struct Word>::iterator it;
		for(it=vec.begin();it!=vec.end();it++)
		{
			if(it->word==str)
			{
				it->num++;
				break;
			}
		}
		if(it==vec.end())
		{
			struct Word newword;
			newword.word=str;
			newword.num=1;
			vec.push_back(newword);
		}
	}
	ifs.close();
	return ;
}

void WordStatic::write_file()
{
	ofstream ofs("Bile_Word_Count.txt");
	if(!ofs.good())
	{
		cout << "ofstream open error" << endl;
		return ;
	}
	vector<struct Word>::iterator vit;
	for(vit=vec.begin();vit!=vec.end();vit++)
	{
		ofs << vit->word << " " << vit->num << endl;
	}
	ofs.close();
	return ;
}

int main()
{
	WordStatic wordcount;
	wordcount.read_file();
	wordcount.write_file();
	return 0;
}
