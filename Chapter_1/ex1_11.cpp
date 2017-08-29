#include <iostream>

int main(int argc, char* argv[])
{
	int first, second;
	std::cout << "Enter two numbers: ";
	std::cin >> first >> second;
	
        while(second == first)
	{
	    std::cout<<first<<std::endl;
	    return 0;
	}

	while( second - first >= 0)
	{
		std::cout << first << " ";
		++first;
	}
	
	std::cout<<std::endl;

	while((second + 1) == first)
	    return 0;

	while(second - first <= 0)
	{
		std::cout << second << " ";
		++second;
	}
	
	std::cout << std::endl;  //空格
	return 0;
}
