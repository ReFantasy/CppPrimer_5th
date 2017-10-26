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
```
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
```
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