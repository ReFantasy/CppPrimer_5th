#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line, word;

    while(getline(cin, line))  //read in a line
	cout << line << endl;

    while(cin >> word)  //read in a wold
	cout << word << endl;

    return 0;
}
