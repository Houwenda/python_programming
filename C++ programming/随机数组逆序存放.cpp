using namespace std;
#include <iostream>
#include <stdlib.h>
#include <time.h>
#define NUM 20
void getRev(int a[],int n)
{
	int i,temp;
	for(i=0;i<=(n/2)-1;i++)
	{
		temp=a[i];
		a[i]=a[n-i-1];
		a[n-i-1]=temp;
	}
}
void getRandom(int a[],int n)
{
	int i=1;
	srand((unsigned)time(NULL));
	while(i<=n)
	{
		
		a[i]=rand()%101;
		i++;		
	}
}
void printArr(int a[],int n)
{
	int i;
	for(i=0;i<n;i++) cout<<a[i]<<" ";
}
int main()
{
	int x[NUM];
	getRandom(x,NUM);
	printArr(x,NUM);
	getRev(x,NUM);
	printArr(x,NUM);
	return 0;
}
