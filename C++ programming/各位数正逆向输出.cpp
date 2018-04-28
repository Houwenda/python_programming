using namespace std;
#include <iostream>
void original(int n)  //ÕıĞòÊä³ö 
{
	int a,i=0,j=1,m=1;
	if(n!=0)
	{
		a=n;
		while(a/10!=0) 
		{
			a/=10;
			i+=1;	
		}
		cout<<a<<" ";
		for(j=1;j<=i;j++) m*=10;
		n-=a*m;
		original(n);
	}
	
}
void inverted(int n)  //ÄæĞòÊä³ö 
{
	if(n!=0) 
	{
		cout<<n%10<<" ";
		n/=10;
		inverted(n);
	}	
}
int main()
{
	int n;
	cin>>n;
	cout<<"Original order: ";
	original(n);
	cout<<'\n'<<"Inverted order: ";
	inverted(n);
	return 0;
}
