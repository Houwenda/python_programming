using namespace std;
#include <iostream>
int gcd(int a, int b)  //最大公约数 
{
	int r;
	r=a%b;
	if(r==0) return b;
	else gcd(b,r);
}
	int lcm(int a, int b)  //最小公倍数 
	{
		return a*b/gcd(a,b);
	}
int main()
{
	int a,b; 
	cin>>a>>b;
	cout<<"最大公约数为"<<gcd(a,b)<<'\n'<<"最小公倍数为"<<lcm(a,b);
	return 0;
}
