using namespace std;
#include <iostream>
#include <cmath>
bool IsPrime(int n)
{
	int i=2;
	while(i<sqrt(n))
	{
		if(n%i==0) return false;
		i++;
	}
	return true;
}
int main()
{
	int input,i=3;
	cin>>input;
	while(i<=input/2)
	{
		if(IsPrime(i)==true)
		{
			if(IsPrime(input-i)==true) cout<<input<<'='<<i<<'+'<<input-i<<' ';
		}
		i+=2;
	}
	return 0;
}
