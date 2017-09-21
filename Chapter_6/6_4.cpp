#include <iostream>
int fact(int n)
{
    if(n <= 1)
	return 1;
    else
	return n*fact(n-1);
}

int main()
{
    //n!
    int n = 0;
    std::cout << "plase enter an number:";
    std::cin >> n;
    std::cout << n<<"! is: " <<fact(n) << std::endl;

    return 0;
}
