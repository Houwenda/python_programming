using namespace std;
#include <iostream>
#include <stdlib.h>
#include <time.h>
#define NUM 20
bool insertSort(int a[],int maxnum,int n,int x)
{
	int i,j,temp;
	if(n==maxnum) return false;
	else
	{
		a[n]=x;
		for(i=0;i<n;i++)
		for(j=0;j<n-i;j++)
			if(a[j]>=a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}	
		return true;	
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
	int i;
	srand((unsigned)time(NULL));
	for(i=0;insertSort(x,NUM,i,rand()%100);i++);
	printArr(x,i);
	return 0;	
}
