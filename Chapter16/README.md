
# Chapter 16
**以下是第十六章的习题解答**

*EX为题号，灰色阴影部分为答案，其余为题目或其它说明*

## Ex16.1
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
## Ex16.2
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
