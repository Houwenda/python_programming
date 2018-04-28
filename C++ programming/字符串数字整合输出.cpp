using namespace std;
#include <iostream>
#include <cstring>
int stringToInt(char a[])
{
	int i,len,sum=0,n;
	char num[20];
	len=strlen(a);
	for(i=0;i<len;i++)
	{
		if(a[i]>=48&&a[i]<=57)
		{	
			n=int(a[i])-48;		
			sum=sum*10+n;
		} 
	}
	return sum;
}
int main()
{
	char a[20];
	cin.getline(a,20);
	cout<<stringToInt(a);
	return 0;
}
