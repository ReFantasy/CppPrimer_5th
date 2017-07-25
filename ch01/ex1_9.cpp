#include <iostream>
#include <stdio.h>
int main(int argc, char *argv[])
{
	int val = 50;
	int sum = 0;

	while(val <= 100 )
	{
		sum += val;
		++val;
	}

	printf("The sum from 50 to 100 is %d\n", sum);

	return 0;
}
