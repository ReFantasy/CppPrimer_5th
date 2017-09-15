#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vi;
    for(auto it = vi.begin(); it != vi.end(); it++)
	cout << *it << " ";

    return 0;
}
