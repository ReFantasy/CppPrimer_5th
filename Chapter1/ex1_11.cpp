#include <iostream>

int main(int argc, char* argv[])
{
	int first, second;
	std::cout << "Enter two numbers: ";
	std::cin >> first >> second;
	
	//如果输入的两个参数相等 直接输出并结束程序
        while(second == first)
	{
	    std::cout<<first<<std::endl;
	    return 0;
	}

	//第二个参数大于第一个参数
	while( second - first >= 0)
	{
		std::cout << first << " ";
		++first;
	}
	
		
	while((second + 1) == first)
	{
	    std::cout<<std::endl;
	    return 0;
	}
	//第二个参数小于第一个参数
	while(second - first <= 0)
	{
		std::cout << second << " ";
		++second;
	}
	
	std::cout<<std::endl;
	return 0;
}
