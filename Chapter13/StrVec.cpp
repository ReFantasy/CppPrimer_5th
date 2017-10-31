#include "StrVec.h"
#include <memory>
std::allocator<std::string> StrVec::alloc;
StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	cap = first_free = newdata.second;
}

StrVec::StrVec(const std::initializer_list<std::string> &li)
	:elements(nullptr), first_free(nullptr), cap(nullptr)
{
	for (auto itm : li)
		push_back(itm);
}

StrVec& StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

StrVec::~StrVec()
{
	free();
}

void StrVec::push_back(const std::string &s)
{
	chk_n_alloc();    //确保有空间保存s
	alloc.construct(first_free++, s);

}

size_t StrVec::size() const
{
	return first_free - elements;
}

size_t StrVec::capacity() const
{
	return cap - elements;
}

std::string* StrVec::begin() const
{
	return elements;
}

std::string* StrVec::end() const
{
	return first_free;
}

void StrVec::reserve(size_t n)
{
	if (n > capacity())
	{
		//分配当前内存两倍大小的空间
		auto newcapacity = n;
		//分配新内存
		auto newdata = StrVec::alloc.allocate(newcapacity);
		//将数据从旧内存移动到新内存
		auto dest = newdata;
		auto elem = elements;
		for (size_t i = 0; i != size(); i++)
			StrVec::alloc.construct(dest++, std::move(*elem++));

		free();//构造完成。释放旧内存
		elements = newdata;
		first_free = dest;
		cap = elements + newcapacity;
	}
}

void StrVec::resize(size_t n)
{
	if (n > capacity())
	{
		reserve(n);
	}
	else if (n < capacity())
	{
		//分配内存空间
		auto newcapacity = n;
		//分配新内存
		auto newdata = StrVec::alloc.allocate(newcapacity);
		//将数据从旧内存移动到新内存
		auto dest = newdata;
		auto elem = elements;
		for (size_t i = 0; (i<size())&&(i != n); i++)
			StrVec::alloc.construct(dest++, std::move(*elem++));

		free();//构造完成。释放旧内存
		elements = newdata;
		first_free = dest;
		cap = elements + newcapacity;
	}
}

void StrVec::chk_n_alloc()
{
	if (size() == capacity())
		return reallocate();
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
	auto data = alloc.allocate(e - b);
	return { data, uninitialized_copy(b, e, data) };
}

void StrVec::free()
{
	if (elements)
	{
		for (auto p = first_free;p != elements;)
			StrVec::alloc.destroy(--p);
		StrVec::alloc.deallocate(elements, cap - elements);
	}
}

void StrVec::reallocate()
{
	//分配当前内存两倍大小的空间
	auto newcapacity = size() ? 2 * size() : 1;
	//分配新内存
	auto newdata = StrVec::alloc.allocate(newcapacity);
	//将数据从旧内存移动到新内存
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); i++)
		StrVec::alloc.construct(dest++, std::move(*elem++));

	free();//构造完成。释放旧内存
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}
