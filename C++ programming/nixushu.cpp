using namespace std;
#include <iostream>
#include <cstring>
#define MAX 3
int getRev(char a[])
{
	int how_many,rev_num=0,i,j;
	how_many=strlen(a);
	for(i=0;i<how_many-1;i++)
	for(j=i+1;j<how_many;j++)
		if(a[i]>a[j]) rev_num+=1;
	return rev_num;
}

int main()
{
	int m,i,j,temp;
	char a[20],rev_num[MAX],string[MAX*20];
	for(m=0;m<MAX;m++)
	{
		cin.getline(a,20);
		rev_num[m]=getRev(a);
	}
	for(i=0;i<strlen(a)-1;i++)
	for(j=0;j<strlen(a)-1-i;j++)
	if(rev_num[i]<rev_num[j]) 
	{
		temp=rev_num[i];
		rev_num[i]=rev_num[j];
		rev_num[j]=temp;
	}
	cout<<rev_num;
	return 0;
}

