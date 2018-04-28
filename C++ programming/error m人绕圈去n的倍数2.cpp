using namespace std;
#include <iostream>
#include <cstring>
int whichnum(int a[],int m)
{
	int i=0;
	for(;i<m;i++) 
	if(a[i]!=-1) 
	return i;	
} 




bool numleft(int a[],int m)  //判断a中是否只剩一个 
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
	int i,j=0,k=0,a[m],b[n],num;
	for(i=0;i<m;i++) a[i]=i+1;
	memset(b,0,sizeof(b)); 
	
	while(numleft(a,m),m)  //a中不止一个时 
	{
		while(j!=m)  //a没有过完时 
		{
			while(k!=n)  //b没有过完时 
			{
				if(a[j]!=-1)  //a[j]未被排除 
				{
					b[k]=a[j];
					k++;
					j++;
					if(j==m) break;
				}
				else 
				{
					j++;  //a[j]已被排除 
					if(j==m) break;	
				} 
			//b过完时
			k=0; 
			a[j-1]=-1;  //排除第n个 
			if(~numleft(a,m),m) 
			{
				num=whichnum(a,m);  //剩余的一个编号
				return num;
			}
			} 		
		//a过完后 
		j=0;  //围成圈		
		}
	}
	
}



int main()
{
	int m,n;
	cin>>m>>n;
	cout<<game(m,n);
	return 0;
} 
