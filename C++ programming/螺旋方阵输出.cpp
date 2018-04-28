using namespace std; 
#include <iostream>
#include <cstring>
#include <iomanip>
void generate(int a[][100], int n)
{
	int num=1,round=1,i;
	while(num<=n*n)
	{
		if(n%2==1&&round==n/2+1) 
		{
			a[round-1][round-1]=num;
			break; 
		} 
		i=round-1;
		while(i<n-round)
		{
			a[round-1][i]=num;
			//cout<<num;
			num++;
			i++;
		}
		i=round-1;
		while(i<n-round)
		{
			a[i][n-round]=num;
			//cout<<num;
			num++;
			i++;			
		}
		i=round-1;
		while(i<n-round)
		{
			a[n-round][n-i-1]=num;
			//cout<<num;
			num++;
			i++;			
		}
		i=round-1;
		while(i<n-round)
		{
			a[n-i-1][round-1]=num;
			//cout<<num;
			num++;
			i++;			
		}
		round++;		
	}
}
void print(int a[][100], int n)
{
	int i=0,j=0;
	while(i<n)
	{
		j=0;
		while(j<n)
		{
			cout<<setw(2)<<a[i][j]<<' ';
			j++;
		} 
		cout<<'\n';
		i++;
	}				
}
int main()
{
	int x[100][100],n;
    cin>>n;
    generate (x,n);
    print(x,n);
    return 0;
} 
