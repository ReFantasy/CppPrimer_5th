#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
using namespace std;


int main(int argc, char *argv[])
{	
        //声明通过
	map<vector<int>::iterator, int> vecmap;
	map<list<int>::iterator, int> listmap;

        //vecmap插入元素通过
	std::vector<int> vi;
	vecmap.insert(std::pair<std::vector<int>::iterator, int>(vi.begin(), 0));

        //listmap插入元素报错
        //原因：map的关键字类型必须定义了比较操作。vector<int>::iterator可以进行大小的比较，list<int>::iterator不能进行大小的比较。
	std::list<int> li;
	listmap.insert(std::pair<std::list<int>::iterator, int>(li.begin(), 0));

	return 0;
}
