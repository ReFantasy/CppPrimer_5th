#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vi;
    int tmp;
    while(cin>>tmp)
    {
	vi.push_back(tmp);
    }
    cout<<"sum"<<endl;
    for(int i=0, j=vi.size()-1; i<=j; i++,j--)
    {
	cout<<vi[i]+vi[j]<<endl;
    }
    return 0;
}
