#include <iostream>
#include <string>
#include <map>
using namespace std;

//忽略标点，并全部转为小写
string strToLower(const string &str)
{
	string tmp;
	for (const auto &c : str)
	{
		if(isalpha(c))
			tmp += tolower(c);
	}
	return tmp;
}

int main(int argc, char *argv[])
{	
	map<string, size_t> word_count;
	string word;
	while (cin >> word)
	{
		//预处理输入的单词之后再加入到map
		++word_count[strToLower(word)];
	}

	for (const auto &w : word_count)
	{
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times " : " time " )<< endl;
	}
	
	return 0;
}
