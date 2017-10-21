#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
using namespace std;
void word_transform(ifstream &map_file, ifstream &input, ofstream &out);
map<string, string> buildMap(ifstream &map_file);
const string& transform(const string &s, const map<string, string> &m);

int main()
{
	ifstream map_file, input;
	ofstream out;

	map_file.open("map_file.txt");
	input.open("input.txt");
	out.open("out.txt");

	word_transform(map_file, input, out);

	map_file.close();
	input.close();
	out.close();
	return 0;
}


void word_transform(ifstream &map_file, ifstream &input, ofstream &out)
{
	//创建映射map
	auto memmap = buildMap(map_file);
	string line;
	while (getline(input, line))
	{
		stringstream strstream(line);
		string word;
		while (strstream >> word)
		{
			string tmp_str = transform(word, memmap);
			if (strstream.good())
			{
				cout << tmp_str << " ";
				out << tmp_str << " ";
			}
			else
			{
				cout << tmp_str << endl;
			}
			
		}

		if (input.good())
			out << endl;
	}
	
}


std::map<std::string, std::string> buildMap(ifstream &map_file)
{
	std::map<std::string, std::string> mymap;
	string key;
	string value;
	while (map_file>>key && getline(map_file, value))
	{
		mymap.insert(make_pair(key, value.substr(1)));
	}

	return mymap;
}


const std::string& transform(const string &s, const map<string, string> &m)
{
	auto iter = m.find(s);

	if (iter != m.end())
	{
		return iter->second;
	}

	return s;
}

