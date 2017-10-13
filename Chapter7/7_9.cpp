#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
	std::string name;
	std::string address;
};

istream& read(istream &is, Person &person)
{
	is >> person.name >> person.address;
	return is;
}

ostream& print(ostream &os, Person &person)
{
	os << person.name << " " << person.address << endl;
	return os;
}

int main(int argc, char *argv[])
{	
	Person person;
	read(cin, person);
	print(cout, person);
	return 0;
}
