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

## Ex12.11
```
process创建一个新的智能指针，和函数外的智能指针共享同一块内存，当process执行结束，内存被释放。
外部智能指针销毁时，则会delete一块已经被释放的内存空间，抛出一个异常值。
```

## Ex12.12
```C++
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
	auto p = new int();
	auto sp = make_shared<int>();
	//process(sp);                 //正确。sp的引用计数加一
	//process(new int());          //编译错误，不能隐式转换
	//process(p);                  //编译错误，不能隐式转换
	//process(shared_ptr<int>(p)); //创建智能指针，函数调用结束后，释放p所指向的内存，p成为空悬指针
	
	return 0;
}
```

## Ex12.17
```C++
int ix = 1024, *pi = &ix, *pi2 = new int(2048);
typedef unique_ptr<int> IntP;
IntP p0(ix);  //参数类型错误
IntP p1(pi);  //编译通过，然而运行时错误，delete一块不是通过new申请的内存
IntP p2(pi2); //编译通过，当p2销毁时，p2所指的内存被释放，pi2成为野指针
IntP p3(&ix); //同p1
IntP p4(new int(2048)); //right
IntP p5(p2.get()); //同一块内存被p2、p5释放两遍
```

## Ex12.23
```C++
#include <iostream>
#include <string>
using namespace std;

char* stringLink(const char *ch1, const char *ch2)
{
        
	int n = strlen(ch1) + strlen(ch2) - 1;  //存储两个字符串需要的内存	
	char *p = new char[n];
	char *tmp = p;

	for (const char*ch = ch1; (*ch) != '\0'; ch++, tmp++)
		(*tmp) = (*ch);

	for (const char*ch = ch2; (*ch) != '\0'; ch++, tmp++)
		(*tmp) = (*ch);

	(*tmp) = '\0';  //字符串以空字符结束

	return p;
}

char* stringLink(const string &s1, const string &s2)
{
        //string.data()返回string中首个字符对象的地址，并且以空字符'\0'结束
	return stringLink(s1.data(), s2.data());
}

int main()
{
	cout << stringLink("hello,", "world!") << endl;
	cout << stringLink(string("string_1,"), string("string_2!")) << endl;
	
	return 0;
}

```

















