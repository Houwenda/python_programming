using namespace std;
#include <iostream>
#include <cstring>
bool numleft(int a[])
{
	int i=0,j=0;
	while(i<m)
	{
		if(a[i]!=-1) j+=1;
		i++;
	}
	if(j=1) return false; //a中只剩一个 
	else return true;  //a中还剩多个 
}
int game(int m,int n)
{
	int a[m],i,j=0,b[n];
	for(i=0;i<m;i++) a[i]=i+1;
	while(numleft(a))  //a中还剩多个 
	{
		memset(b,0,sizeof(b));
		while(b[n-1]==0)  //b未被填满 
		{
			for(;j<m;j++) 
			{
				if(a[j]!=-1) b[j]=a[j];  //将a中非-1的编号放入b中 
				else continue;			
			}
			if(j==m) j=0;  //围成一个圈		
		}
		a[j]=-1;  // 
	}	 
	ruturn 
}
int main()
{
	int m,n;
	cin>>m>>n;
	cout<<game(m,n);
	return 0;
}
