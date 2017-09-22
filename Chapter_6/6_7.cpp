#include <iostream>

int f()
{
    static int n = 0;

    return n++;
}

int main()
{
    for(int i=0; i<10; i++)
    {
	std::cout<<f()<<std::endl;
    }
}
