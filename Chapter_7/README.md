# Chapter_7

**以下是第七章的习题解答**

EX为题号，灰色阴影部分为答案，其余为题目或其它说明

## [Ex7.1](./7_1.cpp)
## [Ex7.3](./7_3.cpp)
## [Ex7.4](./7_4.h)
## [Ex7.5](./7_5.h)
## [Ex7.9](./7_9.cpp)
## Ex7.10
```
判断是否正确读取data1和data2。
```

## Ex7.16
```
访问说明符的个数和位置没有什么限制。
一般提供给类的使用者的函数放在public
实现类内的功能的函数放在private
```

## Ex7.17
```
struct和class唯一的区别就是默认的权限不同
struct默认public
class默认private
```

## Ex7.19
* public include: constructors, getName(), getAddress().

* private include: name, address.

## Ex7.23 && Ex7.24
```C++
#include <iostream>
#include <string>
using namespace std;

class Screen
{
//定义Screen类内类型
public:
	typedef unsigned int Screen_type;

//构造函数
public:
	Screen() = default;
	Screen(const Screen_type width, const Screen_type height, const int n_blank);
	Screen(const Screen_type width, const Screen_type height, const char c);

//封装接口
public:
	Screen_type getWidth() const
	{
		return m_width;
	}
	Screen_type getHeight() const
	{
		return m_height;
	}
	std::string getContent() const
	{
		return m_contents;
	}

//成员变量
private:
	Screen_type m_width = 0;
	Screen_type m_height = 0;
	std::string m_contents;
};

inline Screen::Screen(const Screen_type width, const Screen_type height, const int n_blank)
	:m_width(width), m_height(height), m_contents(n_blank>0 ? n_blank : 0, ' '){}

inline Screen::Screen(const Screen_type width, const Screen_type height, const char c)
	:m_width(width), m_height(height), m_contents(width*height, c) {}

//打印 Screen
void print(const Screen &screen)
{
	cout << "screen width: " << screen.getWidth() << endl;
	cout << "screen height: " << screen.getHeight() << endl;
	cout << "screen contents: " << screen.getContent() << endl;
}

int main(int argc, char *argv[])
{	
	Screen::Screen_type width = 10;
	Screen::Screen_type height = 5;
	Screen my_screen(10, 5, -7);
	print(my_screen);
	return 0;
}
```

Ex 7.27
```C++
#include <iostream>
#include <string>
using namespace std;

class Screen
{
//定义Screen类内类型
public:
	typedef unsigned int pos;

//构造函数
public:
	Screen() = default;
	Screen(const pos width, const pos height, const int n_blank);
	Screen(const pos width, const pos height, const char c);

//封装接口
public:
	pos getWidth() const
	{
		return m_width;
	}
	pos getHeight() const
	{
		return m_height;
	}
	std::string getContent() const
	{
		return m_contents;
	}
	Screen& set(const char c);
	Screen& set(const pos x, const pos y, const char c);
	Screen& move(const pos r, const pos c);
	char get(const pos r, const pos c)const;
	Screen& display(std::ostream &os);
	const Screen& display(std::ostream &os)const;

//成员变量
private:
	pos m_width = 0;
	pos m_height = 0;
	std::string m_contents;
	pos m_cursor = 0;

//私有函数
private:
	void do_display(ostream &os)const
	{
		os << m_contents << endl;
	}
};

inline Screen::Screen(const pos width, const pos height, const int n_blank)
	:m_width(width), m_height(height), m_contents(n_blank>0 ? n_blank : 0, ' '){}

inline Screen::Screen(const pos width, const pos height, const char c)
	:m_width(width), m_height(height), m_contents(width*height, c) {}

inline Screen& Screen::set(const char c)
{
	m_contents[m_cursor] = c;

	return *this;
}

inline Screen& Screen::set(const pos x, const pos y, const char c)
{
	m_cursor = x*m_width + y;
	m_contents[m_cursor] = c;

	return *this;
}

inline Screen& Screen::move(pos r, pos c)
{
	m_cursor = r*m_width + c;
	return *this;
}

inline char Screen::get(const pos r, const pos c)const
{
	return m_contents[r*m_width + c];
}

Screen& Screen::display(std::ostream &os)
{
	do_display(os);
	return *this;
}

const Screen& Screen::display(std::ostream &os)const
{
	do_display(os);
	return *this;
}
//打印 Screen
void print(const Screen &screen)
{
	cout << "screen width: " << screen.getWidth() << endl;
	cout << "screen height: " << screen.getHeight() << endl;
	cout << "screen contents: " << screen.getContent() << endl;
}

int main(int argc, char *argv[])
{	
	Screen my_screen(5, 5, 'X');
	my_screen.move(4, 0).set('#').display(cout);
	cout << "\n";
	my_screen.display(cout);
	cout << "\n";

	return 0;
}
```
