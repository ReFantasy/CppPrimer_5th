# Chapter_11

**以下是第十一章的习题解答**

EX为题号，灰色阴影部分为答案，其余为题目或其它说明

## Ex11.1
```
map按照关键字查找
vector按照位置朝找
两者底层的实现使用不同的数据结构。
```

## Ex11.4
```C++
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

```
