#include <iostream>
#include <stdlib.h>
#include <initializer_list>
//#include <sstream>
using namespace std;

int f(initializer_list<int> a)
{
    int sum = 0;
    for(auto em : a)
	sum += em;

    return sum;
}

int main(int argc , char** argv)
{
    cout<<f({1,2,3,4,5,6,7,8,9})<<endl;
}
