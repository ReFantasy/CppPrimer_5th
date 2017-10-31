#ifndef __STRBLOG_H__
#define __STRBLOG_H__

#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

class StrBlob
{
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
	std::string& back()
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

#endif
