using namespace std;
#include <iostream>
#include <cmath>
void FacPrimely(int); 
bool SuShu(int);
int main()
{
	int x;
	cin>>x;
	cout<<x<<'=';
	FacPrimely(x);
	return 0;
}
bool SuShu(int n)
{
	int i=2;
	while(i<n)
	{
		if(n%i==0) break;
		i++;
	}
	if(i==n) return true;
	else return false;
}
void FacPrimely(int n)
{
	if(SuShu(n)) 
	{
		cout<<n;
		return ;
	}
	else
	{
	int k=2;
	while(k<=sqrt(n))
	{
		if(SuShu(k))   //k1ÊÇËØÊý 
		{
			if(n%k==0) 
			{
				cout<<k<<'*';
				break;	 
			} 
		}
		k++;
	}
	FacPrimely(n/k);
	}
}
