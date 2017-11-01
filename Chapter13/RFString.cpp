#include "RFString.h"
#include <memory>
#include <utility>

//定义静态变量
std::allocator<char> RFString::alloc;

RFString::RFString(const char *pchar)
	:begin(nullptr), end(nullptr)
{
	int n = 0;
	const char* tmp = pchar;
	while ((*tmp++) != '\0') n++;
	n++; //包含结束符'\0'
	begin = alloc.allocate(n);
	end = begin + n;
	std::uninitialized_copy(pchar, pchar+n, begin);

}


RFString::RFString(const RFString &rf_str):RFString(rf_str.begin){}

RFString& RFString::operator=(const RFString& rhs)
{
	auto new_begin = alloc.allocate(rhs.size() + 1);
	std::uninitialized_copy(rhs.begin, rhs.end, new_begin);
	//free this
	for (auto b = begin; b != end; b++)
		alloc.destroy(b);
	alloc.deallocate(begin, size() + 1);

	begin = new_begin;
	end = begin + rhs.size()+1;

	return *this;
}

size_t RFString::size()const
{
	return (end-begin-1);
}

RFString::~RFString()
{
	for (auto b = begin; b != end; b++)
		alloc.destroy(b);
	alloc.deallocate(begin, size() + 1);
}

std::ostream& operator<<(std::ostream& os,const RFString &str)
{
	auto n = str.end - str.begin;
	for (auto p = str.begin; p != str.end; p++)
		os << *p;
	return os;
}

