using namespace std;
#include <iostream>
void move(int *p,int n,int m)
{
	int count=0,temp,i;
	while(count<m)
	{
		temp=*(p+n-1);
		for(i=n-2;i>=0;i--)
			*(p+i+1)=*(p+i);
		*p=temp;
		count++;
	}	
}
void print (int *p,int n)
{
	int i=0;
	while(i<n)
	{
		cout<<*(p+i)<<' ';
		i++; 
	}
}
int main()
{
	int n,m,a[10],i;
	cin>>n;
	cin>>m;
	for(i=0;i<n;i++) cin>>a[i];
	move(a,n,m);
	print(a,n);	
	return 0;
}
