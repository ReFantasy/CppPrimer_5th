# Chapter_11

**以下是第十一章的习题解答**

EX为题号，灰色阴影部分为答案，其余为题目或其它说明

## Ex11.1
```
map按照关键字查找
vector按照位置朝找
两者底层的实现使用不同的数据结构。
```

## [Ex11.4](./11_4.cpp)

## [Ex11.7](./11_7.cpp)

## Ex11.9
```C++
map<string, list<int>> m;
```

## [Ex11.10](./11_10.cpp)

## [Ex11.11](./11_11.cpp)

## [Ex11.12](./11_12.cpp)

## Ex11.14
```C++
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

class CFamily
{
public:
	CFamily() {}
	CFamily(string family_name)
	{
		family_children = { { family_name, vector<pair<string, string>>()} };
	}
public:
	void addNewFamily(string new_family_name)
	{
		const auto& mv = family_children[new_family_name];
		if(mv.empty())
			family_children[new_family_name] = vector<pair<string, string>>();
	}
	void addChild(string family_name, string child_name, string birthday = "1949-10-01")
	{
		const auto& mv = family_children[family_name];
		if (mv.empty())
		{
			addNewFamily(family_name);
			auto& vec = family_children[family_name];
			vec.push_back(make_pair(child_name, birthday));
		}
		else
		{
			auto& vec = family_children[family_name];
			vec.push_back(make_pair(child_name, birthday));
		}

	}

	void printFamily()
	{
		for (const auto &f : family_children)
		{
			cout << "family name: " << f.first << endl;
			cout << "family children: " << endl;
			for (const auto& name : f.second)
			{
				cout <<  "名字：" << f.first << left << setw(8) << name.first  << "  生日：" << name.second << " ";
				cout << endl;
			}
			cout << endl;
			cout << endl;
		}
	}
private:
	map<string, vector<pair<string, string>>> family_children;
};

int main(int argc, char *argv[])
{
	CFamily family;

	//先添加家庭姓氏，再逐一添加孩子名
	family.addNewFamily("李");
	family.addChild("李", "大孩", "1992-12-21");
	family.addChild("李", "二孩", "1997-03-21");
	family.addChild("李", "三孩", "1993-08-15");

	//直接添加孩子名(自动创建家庭)
	family.addChild("王", "明", "1994-10-01");
	family.addChild("王", "翠花", "1994-11-12");
	family.addChild("王", "狗蛋", "1998-06-13");

	family.addChild("周", "杰伦", "1979-01-18");

	//输出所有的家庭
	family.printFamily();
	cout << endl;
	return 0;
}

```

## Ex11.15
```C++
map<int, vector<int>>;
mapped_type: vector<int>
key_type: int
value_type: pair<int, vector<int>>
```

## Ex11.20
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
		if (isalpha(c))
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
		//++word_count[strToLower(word)];
		auto ret = word_count.insert(make_pair(strToLower(word), 1));
		if (!ret.second)
		{
			ret.first->second++;
		}
	}

	for (const auto &w : word_count)
	{
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times " : " time ") << endl;
	}

	return 0;
}

```

## Ex11.21
```C++
如果插入的元素不存在，则插入，sizt_t=0，然后将其值加一，单词的个数为 1，正确。
如果插入的元素已经存在，同样也将map的键值加一，该单词的个数递增1，正确。
```
