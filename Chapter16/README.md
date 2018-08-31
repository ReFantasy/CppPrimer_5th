
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
找不到比较数据类型的`<`操作


## Ex16.4
```C++
template <typename ITERATOR, typename VALUE>
ITERATOR myFind(const ITERATOR begin, const ITERATOR end, const VALUE v)
{
	auto b = begin, e = end;
	for (; b != e; b++)
	{
		if (*b == v)
			return b;
	}

	return end;
}

int main()
{
	vector<int> a({ 1,5,7,9,18, 20 });
	auto iter = myFind<decltype(a.begin()), int>(a.begin(), a.end(), 5);
	cout << *iter << endl;
}
```

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
