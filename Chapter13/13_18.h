#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
	Employee() :id(-1) {}
	Employee(const string &new_name)
		:name(new_name)
	{
		id = ++ID;
	}
public:
	string name;
	int id;
private:
	static int ID;
};

int Employee::ID = 0;