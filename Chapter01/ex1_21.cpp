#include <iostream>
#include "./include/Sales_item.h"

int main()
{
    Sales_item book1,book2;
    std::cin>>book1>>book2;

    std::cout<<"the sum of book1 and book2:"<<std::endl<<book1+book2<<std::endl;
    return 0;
}
