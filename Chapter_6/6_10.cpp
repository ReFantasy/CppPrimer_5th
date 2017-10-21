#include <iostream>
void m_swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - 2* (*b);
    *a = (*a - *b) / 2;
    *b = (*b + *a) ;
}

int main()
{
    int a,b;
    std::cout<<"input two numbers"<<std::endl;
    std::cin >> a >> b;
    m_swap(&a, &b);
    std::cout <<"a= " << a <<"  b= " << b << std::endl;

    return 0;
}
