//decltype获取函数的类型，传入set.我们可以直接定义函数指针类型，传入set.
#include <iostream>
#include <string>
#include <set>
using namespace std;
class Sales_data
{
public:
	string isbn()const 
	{
		return isbndata;
	}
	string isbndata;
};

//定义比较函数
bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs)
{
	return lhs.isbn() < rhs.isbn();
}

//定义了函数指针类型 compareType
typedef bool(*compareType)(const Sales_data& lhs, const Sales_data& rhs);

int main()
{
        //compareType：函数指针类型， compareIsbn： compareType类型的变量
	std::multiset<Sales_data, compareType> bookstore(compareIsbn);
        return 0;
}
