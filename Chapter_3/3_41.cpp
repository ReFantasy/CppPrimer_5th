#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int array[] = {1,2,3,4,5,6};

    vector<int> vi(begin(array), end(array));

    for(auto i:vi)
	cout<<i<<endl;

    return 0;
}
