using namespace std;
#include <iostream>
#include <cstring>
int whichnum(int a[],int m)
{
	int i=1;
	for(;i<=m;i++) 
	if(a[i]!=0) 
	return i;	
} 
bool numleft(int a[],int m)
{
	int i=1,j=0;
	while(i<=m)
	{
		if(a[i]==1)
			j+=1;
		i++;
	}
	if(j==1) return true; 
	else return false;	
}
int game(int m,int n)
{
	int a[m+1],i=1,j=1,num;
	for(i=0;i<m+1;i++) a[i]=1;
	a[0]=0;
	i=1;
	while(!numleft(a,m))
	{
		while(i<=m)
		{
			if(a[i]!=0)
			{				
				if(j%n==0)
				{
					a[i]=0;	
					j++;
					i++;
					if(numleft(a,m)) break;	
				}
				else
				{
					i++;
					j++;
				}												
			}															
			else i++;
		}
		i=1;		
	}
	num=whichnum(a,m);
	return num;
}
int main()
{
	int m,n;
	cin>>m>>n;
	cout<<game(m,n);
	return 0;
} 
