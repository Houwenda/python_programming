#include<iostream>
using namespace std;
struct player{
	int number;
	char name[100];
	double score[5];
	double point;
};
void input(player a[], int n);
void compute(player a[], int n);
void sort(player a[], int n);
void print(player a[], int n);
int main()
{
	player a[5];
	input(a,5);
	compute(a,5);
	sort(a,5);
	print(a,5);
	return 0;
}
void input(player a[], int n)
{
	for(int i=0;i<5;i++)
	{
		cin>>a[i].number>>a[i].name;
		for(int j=0;j<5;j++) cin>>a[i].score[j];
	}
	return;
}
void sort(player a[], int n)
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<4;j++)
		for(int k=0;k<5-j-1;k++)
		if(a[i].score[k]<a[i].score[k+1])
		{
			double c=a[i].score[k];
			a[i].score[k]=a[i].score[k+1];
			a[i].score[k+1]=c;
		}
	}
	return;
}
void compute(player a[], int n)
{
	sort(a,5);
	int s=0;
	for(int i=1;i<4;i++)
	{
		for(int j=1;j<4;j++)
		s=s+a[i].score[j];
		a[i].point=s/3;
	}
	return;
}
void print(player a[], int n)
{
	for(int i=0;i<5;i++)
	{
		cout<<a[i].number<<' '<<a[i].name<<endl;
		for(int j=0;j<5;j++) cout<<a[i].score[j]<<' ';
		cout<<' '<<a[i].point<<endl;
	}
	return;
}
