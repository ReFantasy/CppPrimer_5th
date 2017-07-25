#include <iostream>

int main(int argc, char* argv[])
{
	int first, second;
	int tmp_first, tmp_second;  //临时变量
	std::cout << "Enter two numbers: ";
	std::cin >> first >> second;
	
	tmp_first = first;
	tmp_second = second;
	while( tmp_second - tmp_first >= 0)
	{
		std::cout << tmp_first << " ";
		++tmp_first;
	}

	tmp_first = first;
	tmp_second = second;
	while(tmp_first - tmp_second >= 0)
	{
		std::cout << tmp_second << " ";
		++tmp_second;
	}

    std::cout << std::endl;
	return 0;
}
