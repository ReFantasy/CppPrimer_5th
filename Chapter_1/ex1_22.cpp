#include <iostream>
#include "./include/Sales_item.h"

int main()
{
    Sales_item sum,book;
    while(std::cin>>book)
    {
	sum += book;
    }

    std::cout<<"the sum are: "<<std::endl<<sum<<std::endl;
    return 0;
}
