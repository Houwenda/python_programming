using namespace std;
#include <iostream>
void printIP(char *s)
{
	int n=0,j,num;	
	n=0;
	while(n<4)
	{
		num=0;
		j=0+8*n;
		while(j<8*n+8)
		{
			num*=2;	
			num+=*(s+j)-48;					
			j++;
		}
		if(n<3)
			cout<<num<<'.';
		else 
			cout<<num;		
		n++;
	}	
}
int main(void)
{
	char s[35];
	cin>>s;
	printIP(s);	
}
