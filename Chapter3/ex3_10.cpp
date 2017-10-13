#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string s;
    cin>>s;

    for(auto it = s.begin(); it != s.end(); )
    {
	if(ispunct(*it))
	    s.erase(it);
	else
	    it++;
    }

    cout<<s<<endl;

    return 0;
}
