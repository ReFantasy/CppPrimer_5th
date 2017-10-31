#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main()
{
    vector<string> text;
    for(string line; getline(cin, line);)
	text.push_back(line);

    for(auto it = text.begin(); it!=text.end(); it++)
    {
	for(auto &c : *it)
	    c = toupper(c);
    }

    //output
    for(string str:text)
	cout<<str<<endl;
    return 0;
}
