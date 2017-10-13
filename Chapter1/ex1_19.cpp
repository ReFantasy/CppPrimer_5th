#include <iostream>

int main()
{
    int first, second;
    std::cin >> first >> second;

    if(first > second)
    {
	int tmp = first;
	first = second;
	second = tmp;
    }

    while(first <= second)
    {
	std::cout << first << " ";
	first++;
    }

    std::cout<<std::endl;

    return 0;
}
