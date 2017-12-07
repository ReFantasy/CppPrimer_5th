
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
