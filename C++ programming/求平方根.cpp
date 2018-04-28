using namespace std;
#include<iostream>
#include<cmath>
int main()
{
	double a,x1,x2;
	cin>>a;
	x1=a/2;
	while(fabs(x1-x2)>=1e-5)
	{
		x2=x1;
		x1=(x1+a/x1)/2;
	}
	cout<<x1<<'\n';
	cout<<sqrt(a);
	return 0;
}
