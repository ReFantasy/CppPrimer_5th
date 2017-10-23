#include <iostream>
#include <vector>
using namespace std;

//创建int的vector指针
std::vector<int>* makePtr()
{
	return new std::vector<int>;
}

//接受指针
std::vector<int>* receivePtr(istream &is, std::vector<int>* ptr)
{
	int tmp;
	while (is >> tmp)
	{
		ptr->push_back(tmp);
	}
	return ptr;
}

//读取保存才vector内的值
void printValue(std::vector<int>* ptr)
{
	for (const auto &vi : (*ptr))
	{
		std::cout << vi << endl;
	}
	delete ptr;
	ptr = nullptr;
}
int main()
{
	auto ptr = makePtr();
	receivePtr(cin, ptr);
	printValue(ptr);

	return 0;
}

