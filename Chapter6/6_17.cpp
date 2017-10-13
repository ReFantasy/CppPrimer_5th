#include <iostream>
#include <string>

using namespace std;

bool hasA(const string &s)
{
    for(auto it = s.cbegin(); it != s.cend(); ++it)
    {
	if(isupper(*it))
	    return true;
    }

    return false;
}

void to_lower(string &s)
{
    for(char &c : s)
	c = tolower(c);
}

int main()
{
    string s;
    cout<<"please enter a string: ";
    getline(cin, s);
    if(hasA(s))
    {
	cout<<"has upper alpha"<<endl;
    }

    to_lower(s);

    cout<<s<<endl;

    return 0;
}
