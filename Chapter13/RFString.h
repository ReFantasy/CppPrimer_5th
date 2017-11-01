#ifndef __RFSTRING_H__
#define __RFSTRING_H__
#include <iostream>
#include <memory>
#include <string>
class RFString
{
	friend std::ostream& operator<<(std::ostream& os, const RFString &str);
public:
	RFString() :begin(nullptr), end(nullptr){}
	RFString(const char *pchar);
	RFString(const RFString &rf_str);
	RFString& operator=(const RFString& rhs);
	size_t size()const;  //返回字符的个数，不包括结束符
	~RFString();
private:
	char *begin = nullptr;
	char *end = nullptr; //end指向'\0'之后的位置
private:
	static std::allocator<char> alloc;
	

};



#endif // !__RFSTRING_H__
