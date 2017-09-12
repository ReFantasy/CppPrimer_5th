#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> vs;
    string tmp;
    while(cin>>tmp)
    {
	vs.push_back(tmp);
    }
    
    for(auto &s:vs)
    {
	for(auto &c:s)
	{
	    c = toupper(c);
	}
    }

    for(auto s:vs)
	cout<<s<<endl;
    return 0;
}
