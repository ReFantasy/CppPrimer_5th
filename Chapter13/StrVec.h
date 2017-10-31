#ifndef __STRVEC_H__
#define __STRVEC_H__
#include <iostream>
#include <string>
using std::cout;
using std::endl;
class StrVec
{
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {} //默认初始化
	StrVec(const std::initializer_list<std::string> &li);  //列表初始化

	StrVec(const StrVec &);               //拷贝构造函数
	StrVec& operator=(const StrVec &);    //拷贝赋值运算符
	~StrVec();                            //析构函数
	void push_back(const std::string &);  //push_back
	size_t size() const;  //返回已经使用的元素数目
	size_t capacity()const;      //可以保存的元素数量
	std::string* begin() const;
	std::string* end() const;
	void reserve(size_t n);
	void resize(size_t n);
	void print()const
	{
		for (auto p = elements; p != first_free; p++)
			cout << *p << endl;
	}
private:
	static std::allocator<std::string> alloc;    //分配元素
	std::string *elements;    //指向数组首元素指针
	std::string *first_free;  //指向数组第一个空闲元素的指针
	std::string *cap;         //指向数组尾后位置的指针
private:
	//工具函数

	//被添加元素的函数使用
	void chk_n_alloc();       //保证StrVec至少有容纳一个新元素的空间，如果没有则分配新空间
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);  //分配内存，并拷贝一个给定范围中的元素
	void free();     //销毁元素并释放内存
	void reallocate(); //获得更多的内存并拷贝已有的元素
};

#endif // !__STRVEC_H__

