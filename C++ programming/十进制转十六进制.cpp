using namespace std;
#include<iostream>
void DecToHex(int n)
{
	int m=0,k,i=0;  //i表示左移位数
	while(i<=28)
	{
		m=n<<i;
		m=m>>28;
		switch(m)
		{
			case -8:cout<<"8";
			break; 
			case -7:cout<<"9";
			break;
			case -6:cout<<"a";
			break;
			case -5:cout<<"b";
			break;
			case -4:cout<<"c";
			break;
			case -3:cout<<"d";
			break;
			case -2:cout<<"e";
			break;
			case -1:cout<<"f";
			break;
			default:cout<<m;
			break;
		}
		i=i+4;
	}
}
int main()
{
	int n;
	cin>>dec>>n;
	DecToHex(n);
	return 0;
}
