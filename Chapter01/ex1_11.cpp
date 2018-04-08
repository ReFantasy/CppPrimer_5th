#include <iostream>
using namespace std;

void PrintRange(int v1, int v2)
{
	if (v1 <= v2)
	{
		while (v1 <= v2)
		{
			cout << v1++ << " ";
		}
	}
	else
	{
		while (v2 <= v1)
		{
			cout << v1-- << " ";
		}
	}
}

int main(int argc, char* argv[])
{
	int first, second;
	std::cout << "Enter two numbers: ";
	std::cin >> first >> second;

	PrintRange(first, second);
	cout << endl;

	return 0;
}
