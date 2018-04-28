using namespace std;
#include <iostream>
#include <cstring>
#include <time.h>
#include <stdlib.h>
void generateCard(int a[][13],int n)
{
	int num=1,i=0,j=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<13;j++)
			a[i][j]=0;
			//cout<<a[i][j];
	}
	//memset(a,0,sizeof(a));
	srand((unsigned)time(NULL));
	while(num<53)
	{
		i=rand()%4;
		j=rand()%13;
		if(a[i][j]==0)
		{
				a[i][j]=num;
				//cout<<i<<' '<<j<<' '<<num<<'\n';
				num++;
		}
		else 
		{
			continue;
		}
	}
}
void printCard(int a[][13],int n)
{
	int i=0,j=0;
	while(i<4)
	{
		cout<<"Íæ¼Ò"<<i+1<<':'; 
		j=0;
		while(j<13)
		{
			if(a[i][j]<=13)
			{
				cout<<'\5';
				if(a[i][j]<=10&&a[i][j]!=1) 
					cout<<a[i][j];
				else if(a[i][j]==1) cout<<'A';
				else if(a[i][j]==11) cout<<'J';
				else if(a[i][j]==12) cout<<'Q';
				else if(a[i][j]==13) cout<<'K';
			} 
			else if(a[i][j]>=14&&a[i][j]<=26)
			{
				cout<<'\4';
				if(a[i][j]<=23&&a[i][j]!=14) 
					cout<<a[i][j]-13;
				else if(a[i][j]==14) cout<<'A';
				else if(a[i][j]==24) cout<<'J';
				else if(a[i][j]==25) cout<<'Q';
				else if(a[i][j]==26) cout<<'K';
			}
			else if(a[i][j]>=27&&a[i][j]<=39)
			{
				cout<<'\3';
				if(a[i][j]<=36&&a[i][j]!=27) 
					cout<<a[i][j]-26;
				else if(a[i][j]==27) cout<<'A';
				else if(a[i][j]==37) cout<<'J';
				else if(a[i][j]==38) cout<<'Q';
				else if(a[i][j]==39) cout<<'K';
			}
			else if(a[i][j]>=40&&a[i][j]<=52)
			{
				cout<<'\6';
				if(a[i][j]<=49&&a[i][j]!=40) 
					cout<<a[i][j]-39;
				else if(a[i][j]==40) cout<<'A';
				else if(a[i][j]==50) cout<<'J';
				else if(a[i][j]==51) cout<<'Q';
				else if(a[i][j]==52) cout<<'K';
			}
			j++;
		}
		cout<<'\n';	
		i++;
	}
}
int main()
{
	int x[4][13];
    generateCard(x,4);
    printCard(x,4);
    return 0;
}
