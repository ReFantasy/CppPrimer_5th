
# Chapter 16
**以下是第十六章的习题解答**

*EX为题号，灰色阴影部分为答案，其余为题目或其它说明*

## Ex16.2
```C++
template <typename T>
int compare(T a, T b)
{
	if (less<T>()(a, b))
		return -1;
	if (less<T>()(b, a))
		return 1;

	return 0;
}
```
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

## Ex16.5
打印数组
```C++
template<size_t N, typename T>
void print(const T (&t)[N])
{
	for (size_t i = 0; i < N; i++)
	{
		cout << t[i] << endl;
	}
}
```

## Ex16.6
```C++

template<size_t N, typename T>
const T* mybegin(const T (&t)[N])
{
	return &t[0];
}

template<size_t N, typename T>
const T* myend(const T (&t)[N])
{
	return &t[N];
}

int main()
{
	string str[] = { "1", "cust", "hello", "ball" };
	int vi[] = { 1,5,7,9,2 };
	for (auto iter = mybegin(str); iter != myend(str); iter++)
	{
		cout << *iter << endl;
	}
}
```
