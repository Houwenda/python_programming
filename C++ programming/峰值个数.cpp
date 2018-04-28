using namespace std;
#include <iostream>
void peak(int *p, int n, int *pn)
{
	int *i;
	*pn=0;
	i=p+1;
	while(i<p+n-1)
	{
		if(*i>*(i-1)&&*i>*(i+1)) *pn+=1;
		if(*i<*(i-1)&&*i<*(i+1)) *pn+=1;
		i++;
	}	
}
int main()
{
	int a[20],n=0;
	for(int i=0;i<20;i++) cin>>a[i];
	peak(a,20,&n); 
	cout<<n<<endl;	
	return 0;
}
