#include <iostream>
using namespace std;
int abs(int n)
{
    if(n >= 0)
	return n;
    else
	return -n;
}

int main()
{
    cout << "Please enter an number:";
    int n;
    cin>>n;
    cout<<"|"<<n<<"|is:"<<abs(n)<<endl;

    return 0;
}
