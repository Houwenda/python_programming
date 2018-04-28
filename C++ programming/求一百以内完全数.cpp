using namespace std;
#include <iostream>
int main()
{
	int x=1,n=1,sum=0;
	while(x<=100)
	{
		n=1;
		sum=0; 
		while(n<x)
		{
			if(x%n==0)
			{
				sum+=n;
			}
			n++;
		}
		if(sum==x) cout<<x<<' ';
		x++;
	}
	return 0;
} 
