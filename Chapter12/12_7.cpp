#include <iostream>
#include <vector>
#include <memory>
using namespace std;

//创建int的vector指针
shared_ptr<vector<int>> makePtr()
{
	return make_shared<vector<int>>();
}

//接受指针
shared_ptr<vector<int>> receivePtr(istream &is, shared_ptr<vector<int>> ptr)
{
	cout << "in func receivePtr " << ptr.use_count() << endl;

	int tmp;
	while (is >> tmp)
	{
		ptr->push_back(tmp);
	}
	
	return ptr;
}

//读取保存才vector内的值
void printValue(shared_ptr<vector<int>> ptr)
{
	cout << "in func printValue " << ptr.use_count() << endl;

	for (const auto &vi : (*ptr))
	{
		std::cout << vi << endl;
	}
}
int main()
{
	auto ptr = makePtr();
	cout << "in func main " << ptr.use_count() << endl;
	receivePtr(cin, ptr);
	printValue(ptr);

	return 0;
}

