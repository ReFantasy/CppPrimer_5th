## Chapter 13
#### **第十三章的习题解答**

## Ex13.1
如果一个构造函数的 **第一个参数是自身类型的引用**，且任何额外的参数都有默认值，则此构造函数是拷贝构造函数。

使用情况：
- 将一个对象作为实参传递给一个非引用类型的形参
- 从一个返回类型为非引用类型的函数返回一个对象
- 用花括号列表初始化一个数组中的元素或一个聚合类中的成员

## Ex13.2
拷贝构造函数的形参类型必须为引用类型。
如果其参数不是引用类型，则调用永远不会成功：为了调用拷贝构造函数，我们必须拷贝它的实参,而为了拷贝实参，我们又需要调用拷贝构造函数，无限循环。

**举例：**
void f(type x)
f(a) 相当于构造一个临时变量x, x = a,然后把x传进去。
当编译器执行 x = a 时,又需要调用x(a)构造x.
x(a) 相当于构造一个临时变量x1, x1 = a,然后把x1传进去。
如此往复循环。

## Ex13.4
```C++
拷贝构造：
arg -> local
global -> heap
local、*heap -> pa
拷贝赋值:
local -> *heap
```

## [Ex13.5](13_5.cpp)

## Ex13.6
拷贝赋值运算符 `operator=`

当对两个实例`a，b`赋值，`a = b`时，调用拷贝赋值运算符

合成的拷贝赋值运算符只是简单的把两个对象的非静态成员对应赋值。

当类没有定义拷贝赋值运算，默认生成合成的拷贝赋值运算操作。

## [Ex13.8](13_8.cpp)

## Ex13.9
析构函数：类的一个成员函数，没有返回值，也不接受参数。
作用：析构函数释放对象再生存期分配的所有资源。
当一个类没有定义自己的析构函数时，编译器会为他定义一个合成析构函数。

## Ex13.10

## [Ex13.11](13_11.cpp)

## Ex13.12
三次。*accum  item1  item2.*

## Ex13.13
```C++
#include <iostream>
#include <vector>
using namespace std;

struct X
{
	X()
	{
		cout << "X()" << endl;
	}
	X(const X &x)
	{
		cout << "X(const X &x)" << endl;
	}

	X& operator=(X &x)
	{
		cout << "X& operator=()" << endl;
		return x;
	}
	~X()
	{
		cout << "~X()" << endl;
	}
};

int main()
{
	cout << "【X a;】" << endl;
	X a;
	cout << "【X b;】" << endl;
	X b;
	cout << "【X c(a);】" << endl;
	X c(a);
	cout << "【a = b;】" << endl;
	a = b;
	cout << "【X *p = new X;】" << endl;
	X *p = new X;
	cout << "【vector<X> vec1(4);】" << endl;
	vector<X> vec1(4);
	cout << "【vector<X> vec2(4, X());】" << endl;
	vector<X> vec2(4, X());
	cout << "【return 0】" << endl;
	return 0;
}
```

## Ex13.14
三个输出内容一样
```C++
#include <iostream>
using namespace std;

class Numbered
{
public:
	Numbered() = default;
public:
	int mysn = 0;
};

void f(Numbered s)
{
	cout << s.mysn << endl;
}
int main()
{
	Numbered a, b = a, c = b;//调用合成拷贝构造函数，三个变量的数据成员完全一样
	f(a);
	f(b);
	f(c);
	return 0;
}
```

## Ex13.15
会。输出的结果主要看拷贝构造函数怎么实现的。

a.mysn=0,b.mysn=1,c.mysn=2

输出：1，2，3
```C++
#include <iostream>
using namespace std;

class Numbered
{
public:
	Numbered() = default;

	//添加拷贝构造函数
	Numbered(const Numbered &cp)
	{
		mysn = cp.mysn + 1;
	}
public:
	int mysn = 0;
};

void f(Numbered s)
{
	cout << s.mysn << endl;
}
int main()
{
	Numbered a, b = a, c = b; //调用自定义拷贝构造函数a.mysn=0,b.mysn=1,c.mysn=2
    
	f(a); //将a传入f()时，因为f()是值传递，会构造一个临时变量，f(a)输出的结果1
	f(b);
	f(c);
	return 0;
}

```

## Ex13.16
不会

因为 void f(const Numbered &s) 引用参数，

调用f时，不会构造临时变量，所以不存在调用拷贝构造函数。

输出：0，1，2
```C++
#include <iostream>
using namespace std;

class Numbered
{
public:
	Numbered() = default;

	//添加拷贝构造函数
	Numbered(const Numbered &cp)
	{
		mysn = cp.mysn + 1;
	}
public:
	int mysn = 0;
};

void f(const Numbered &s)
{
	cout << s.mysn << endl;
}
int main()
{
	Numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);
	return 0;
}
```

## Ex13.17
如上。

## [Ex13.18](./13_18.h)

## Ex13.19
不需要
```C++
class Employee
{
public:
	Employee() :id(-1) {}
	Employee(const string &new_name)
		:name(new_name)
	{
		id = ++ID;
	}
	Employee(const Employee &) = delete;
	Employee& operator=(const Employee &) = delete;
public:
	std::string name;
	int id;
private:
	static int ID;
};

int Employee::ID = 0;
```

## Ex13.22
```C++
class HasPtr
{
public:
	HasPtr(const std::string &s = std::string())
		:ps(new std::string(s)), i(0) {}

	HasPtr(const HasPtr & hp)
		:ps(new std::string(*hp.ps)), i(hp.i) {}
		
    //拷贝赋值运算符
	HasPtr& operator=(const HasPtr &hp)
	{
		if (ps != nullptr)
			delete ps;
		ps = new string(*hp.ps);
		i = hp.i;
		return *this;
	}
	
    //添加析构函数
    ~HasPtr()
    {
        delete ps;
    }
private:
	std::string *ps;
	int i;
```

## Ex13.24
如果没有定义析构，`ps`所指向的`string`将不会被释放，导致内存泄漏。
如果没有定义拷贝构造，则只会拷贝指针，不会拷贝指针所指向的内存数据。

## Ex13.27
```C++
class HasPtr
{
public:
	//构造函数分配新的string和新的计数器，将计数器置为1
	HasPtr(const std::string &s = std::string())
		:ps(new std::string(s)), i(0), use(new std::size_t(1)) {}

	//拷贝构造函数拷贝所有数据成员，并递增计数器
	HasPtr(const HasPtr &hp)
		:ps(hp.ps),i(hp.i),use(hp.use)
	{
		++*use;
	}

	HasPtr& operator=(const HasPtr &rhs)
	{
		++(*rhs.use);
		
		if (--*use == 0)
		{
			delete ps;
			delete use;
		}
		
		ps = rhs.ps;
		i = rhs.i;
		use = rhs.use;
		return *this;
	}
	~HasPtr()
	{
		if (--*use == 0)
		{
			delete ps;
			delete use;
		}
	}
private:
	std::string *ps;
	int i;
	std::size_t *use;
};
```

## Ex11.29
```
swap(HasPtr& lhs,HasPtr& rhs)
{  
    //该swap内部调用的并不是自己,而是std::swap  
    //同时这些swap的参数类型也各不相同,证明不是递归调用自己  
    cout<<"call swap(HasPtr&,HasPtr&)"<<endl;  
    std::swap(lhs.ps,rhs.ps);  
    std::swap(lhs.i,rhs.i);  
    }  
```

## Ex13.33
因为我们需要修改Folder中保存的Message

## [Ex13.34](./13_34.h)

## Ex13.35
单方面的改变了message所指向的文件夹，而文件夹所包含的message没有改变，导致folder和message关系不对应。

## [EX13.36](./13_34.h)

## [EX13.37](./13_34.h)

## Ex13.38
避免申请内存需要的额外开销

## Ex13.39
[StrVec.h](./StrVec.h)

[StrVec.cpp](./StrVec.cpp)

## Ex13.40
```C++
#include "StrVec.h"
StrVec::StrVec(const std::initializer_list<std::string> &li)
	:elements(nullptr), first_free(nullptr), cap(nullptr)
{
	for (auto itm : li)
		push_back(itm);
}
```
