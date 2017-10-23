# Chapter_12

**以下是第十二章的习题解答**

EX为题号，灰色阴影部分为答案，其余为题目或其它说明

## Ex12.1
```
都是四个
```

##Ex12.2
```C++
#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

class StrBlob
{
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob() :data(make_shared<vector<string>>()) {}
	StrBlob(std::initializer_list<std::string> il)
		:data(make_shared<vector<string>>(il)) {}
	size_type size()const
	{
		return data->size();
	}
	bool emtpy()const
	{
		return data->empty();
	}
	//添加和删除元素
	void push_back(const std::string &t)
	{
		data->push_back(t);
	}
	void pop_back()
	{
		check(0, "pop_back on empty StrBlog");
		data->pop_back();
	}
	//元素访问
	std::string& front()
	{
		check(0, "front on empty StrBlog");
		return data->front();
	}

	const std::string& front()const
	{
		check(0, "front on empty StrBlog");
		return data->front();
	}
	std::string& back()
	{
		check(0, "back on empty StrBlog");
		return data->back();
	}
	const std::string& back()const
	{
		check(0, "back on empty StrBlog");
		return data->back();
	}
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string &msg)const
	{
		if (i >= size())
		{
			throw out_of_range(msg);
		}
	}
};
```

## Ex12.3

**const版本还要加push_back和pop_back?**

**无法理解。。。**

## [Ex12.6](./12_6.cpp)

## [Ex12.7](./12_7.cpp)

## Ex12.8
语法上没错。指针类型隐式转换为布尔类型，导致内存泄漏。

## Ex12.10
```C++
//正确
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

void process(std::shared_ptr<int> ptr)
{
	std::cout << "inside the process function:" << ptr.use_count() << "\n";
}

int main()
{
	shared_ptr<int> p(new int(42));
	cout << "in main,p.use_count: " <<p.use_count() << endl;

	process(shared_ptr<int>(p));

	cout << "after process,p.use_count: " << p.use_count() << endl;
	return 0;
}
```
