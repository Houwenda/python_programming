using namespace std;
#include <iostream>
#include <cmath>
int main()
{
	int n,sushu=2,cha,i,j;
	cin>>n;
	while(sushu<=n/2)
	{
		i=2;
		while(i<sqrt(sushu))
		{
			if(sushu%i==0)  break; //sushu不是素数	
			i++;
    	}
		if(i>=sqrt(sushu)) //sushu是素数
		{
			cha=n-sushu;
			j=2;
			while(j<cha)
			{
				if(cha%j==0) break; //cha不是素数
				j++;
			}
			if(j==cha) cout<<n<<'='<<sushu<<'+'<<cha<<' ';
		}
		sushu++;
	}
	return 0;
} 
