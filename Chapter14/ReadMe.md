## Chapter 14
#### **第十四章的习题解答**

## Ex14.2
```C++
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Sales_data 
{
	friend ostream& operator<<(ostream &os, const Sales_data &sale);//输入
	friend istream& operator>>(istream &is, Sales_data &sale);//输出
	friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs); //加法
public:
	Sales_data() :bookNo(string()), units_sold(0), revenue(0) {}
	Sales_data(const string &s, const unsigned us, const double d) :bookNo(s), units_sold(us), revenue(d) {}
	Sales_data(const Sales_data&sale)
	{
		bookNo = sale.bookNo;
		units_sold = sale.units_sold;
		revenue = sale.revenue;
	}
	std::string isbn()const { return bookNo; }
	double avg_price()const
	{
		if (units_sold)
			return revenue / units_sold;
		else
			return 0;
	}
	Sales_data& operator=(const Sales_data &rhs)
	{
		bookNo = rhs.bookNo;
		units_sold = rhs.units_sold;
		revenue = rhs.revenue;
		return *this;
	}
	Sales_data& operator=(Sales_data &&rhs)
	{
		bookNo = std::move(rhs.bookNo);
		units_sold = rhs.units_sold;
		revenue = rhs.revenue;
		return *this;
	}
	Sales_data& operator+=(const Sales_data &rhs)
	{
		if (bookNo == rhs.bookNo)
		{
			units_sold += rhs.units_sold;
			revenue += rhs.revenue;
			return *this;
		}
		else
		{
			return *this;
		}
	}
private:
	//数据成员
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
ostream& operator<<(ostream &os, const Sales_data &sale)
{
	os << "bookNo:" << sale.isbn() << "  " << "units_sold:" << sale.units_sold << "  " << "revenue:" << sale.revenue;
	return os;
}

istream& operator>>(istream &is, Sales_data &sale)
{
	is >> sale.bookNo >> sale.units_sold >> sale.revenue;
	return is;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data tmp(lhs);
	tmp += rhs;
	return tmp;
}
```

## Ex14.18
```C++
class StrBlob
{
	friend bool operator==(const StrBlob &lrs, const StrBlob &rhs);
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

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
	return ((*lhs.data) == (*rhs.data));
}
```
