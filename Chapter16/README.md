
# Chapter 16
**以下是第十六章的习题解答**

*EX为题号，灰色阴影部分为答案，其余为题目或其它说明*

## Ex16.1
编译器使用实际的模板实参代替对应的模板参数来创建一个特定类型的类或者函数版本叫做模板的实例化。

## Ex16.2
```C++
template <typename T, typename F = std::less<T>>
int compare(const T &a, const T &b,F f = F())
{
	if (f(a, b))
		return -1;
	if (f(b, a))
		return 1;

	return 0;
}
```

## Ex16.3
找不到数据类型的`<`操作

## Ex16.4
```C++
template <typename InputIt, typename T>
InputIt Find(InputIt begin, InputIt end, const T& value)
{
    for (; begin != end; ++begin) {
        if (*begin == value) {
            return begin;
        }
    }
    return end;
}
```

## Ex16.5
打印数组
```C++
template<typename T, int N>
void PrintArray(T (&ary)[N])
{
	for (int i = 0; i < N; i++)
	{
		cout << ary[i] << " ";
	}
	cout << endl;
}
```

## Ex16.6
```C++

template<typename T, int N>
T* Begin(T(&ary)[N])
{
	return ary;
}

template<typename T, int N>
T* End(T(&ary)[N])
{
	return ary+N;
}
```

## Ex16.7
```C++
template<typename T, int N>
constexpr int GetArraySize(T(&ary)[N])
{
	return N;
}
```

## Ex16.8
大部分标准库类型定义了`==`和`!=`操作（可能没有定义`<`操作）

## Ex16.9
函数模板用来生成特定参数版本的函数，类模板用来生成特定参数版本的类

## Ex16.10
编译器使用实际的模板参数替换掉形式上的模板参数，从而生成特定版本的类

## Ex16.11
```C++
void insert(ListItem<elemType> *ptr, elemType value);
ListItem<elemType> *front, *end;
```

## Ex16.17
当需要特别强调声明的是一个类型而不是一个值的时候必须使用`typename`

## Ex16.18
(a) 错误 U前面缺少typename
(b) 错误 改正：template<typename T> T f2(T &)
(c) 错误 inline 需要写在函数返回值前面而不是'template'
(d) 错误 缺少函数返回值
(e) ？？ 模板中的Ctype类型覆盖了typedef 的Ctype
	
## Ex16.19
```C++
template<typename C>
void f(const C& c)
{
	using size_type = typename C::size_type;  // 表明C::size_type是一个类型而不是一个值
	for (size_type i = 0; i<c.size(); i++)
	{
		cout << c[i] << " ";
	}
}
```

## Ex16.20
```C++
template<typename Iterator>
void f(Iterator b, Iterator e)
{
	while (b != e)
	{
		cout << *b++ << " ";
	}
}
```
