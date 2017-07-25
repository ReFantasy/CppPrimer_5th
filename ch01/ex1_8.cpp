#include <iostream>

int main()
{
	std::cout << "/*" << std::endl;  //right
	std::cout << "*/" << std::endl;  //right

	// std::cout << /* "*/" */ <<std::endl; error
	
	std::cout << /* "*/" /* "/*" */ << std::endl; //right

	return 0;
}
