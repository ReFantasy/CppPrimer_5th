#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> vi;
    string tmp;
    while(cin>>tmp)
    {
	vi.push_back(tmp);
    }
    
    for(auto s:vi)
	cout<<s<<endl;
    return 0;
}
