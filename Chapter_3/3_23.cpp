#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    vector<int> vi;
    for(int i=0; i<10; i++)
	vi.push_back(rand()%100);

    for(int i:vi)
	cout<<i<<" ";
    cout<<endl;

    // *2
    for(auto it = vi.begin(); it != vi.end(); it++)
	(*it) *=2;

    for(int i:vi)
      cout<<i<<" ";
    cout<<endl;

   return 0; 
}
