#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;


int main()
{
	string str;
	int seq;
	vector<pair<string, int>> vec;
	while (cin >> str >> seq)
	{
		vec.push_back(make_pair(str, seq));
	}

	//输出
	for (const auto &p : vec)
	{
		cout << left << setw(10) << p.first << left << setw(4) << p.second << endl;
	}
	return 0;
}
