using namespace std;
#include <iostream>
#include <stdlib.h>
#include <cstring>
#define NUM 100
void trim1(char a[])
{
	int i=0,j,k=NUM-1;
	while(i<NUM)
	{
		if(a[i]==' ')
		{
			for(j=i;j<NUM-1;j++) a[j]=a[j+1];
			continue;
		}
		i++;
	}
	while(k>=0)
	{
		if(a[k]==' ') 
		{
			a[k]='\0';
			k--;
		}
		else break;
	}
}
void trim2(char a[])
{
	int n,i,j;
	while(a[0]==' ') 
	{
		for(j=0;j<NUM-1;j++) a[j]=a[j+1];
	}
}
int main()
{
    char x[NUM];
    cin.getline(x,99);
    trim1(x);
    cout<<x<<endl;
    cin.getline(x,99);
    trim2(x);
    cout<<x<<endl;
    return 0;
}
