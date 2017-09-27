#include <iostream>
using namespace std;

int Max(const int a, const int *pb)
{
    return (a>*pb) ? a : *pb;
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<Max(a, &b)<<endl;

    return 0;
}
