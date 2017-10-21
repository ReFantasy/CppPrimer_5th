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


## Ex11.7
```C++
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class CFamily
{
public:
	CFamily() {}
	CFamily(string family_name)
	{
		family_children = { { family_name, vector<string>() } };
	}
public:
	void addNewFamily(string new_family_name)
	{
		family_children[new_family_name] = vector<string>();
	}
	void addChild(string family_name, string child_name)
	{
		const auto& mv = family_children[family_name];
		if (mv.empty())
		{
			addNewFamily(family_name);
			auto& vec = family_children[family_name];
			vec.push_back(child_name);
		}
		else
		{
			auto& vec = family_children[family_name];
			vec.push_back(child_name);
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
				cout << name << " ";
			}
			cout << endl;
			cout << endl;
		}
	}
private:
	map<string, vector<string>> family_children;
};

int main(int argc, char *argv[])
{	
	CFamily family;

	//先添加家庭姓氏，再逐一添加孩子名
	family.addNewFamily("李");
	family.addChild("李", "大孩");
	family.addChild("李", "二孩");
	family.addChild("李", "三孩");

	//直接添加孩子名(自动创建家庭)
	family.addChild("王", "王一");
	family.addChild("王", "王二");
	family.addChild("王", "王三");

	//输出所有的家庭
	family.printFamily();
	cout << endl;
	return 0;
}
```

## Ex11.9
```C++
map<string, list<int>> m;
```

## Ex11.10
```C++
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
using namespace std;


int main(int argc, char *argv[])
{	
        //声明通过
	map<vector<int>::iterator, int> vecmap;
	map<list<int>::iterator, int> listmap;

        //vecmap插入元素通过
	std::vector<int> vi;
	vecmap.insert(std::pair<std::vector<int>::iterator, int>(vi.begin(), 0));

        //listmap插入元素报错
        //原因：map的关键字类型必须定义了比较操作。vector<int>::iterator可以进行大小的比较，list<int>::iterator不能进行大小的比较。
	std::list<int> li;
	listmap.insert(std::pair<std::list<int>::iterator, int>(li.begin(), 0));

	return 0;
}
```
