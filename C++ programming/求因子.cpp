using namespace std;
#include <iostream>
int main()
{
	int x,n=1;
	cin>>x;
	while(n<x)
	{
		if(x%n==0)
		{
			 cout<<n<<' ';
		}
		n++;
	}
	return 0;
}
