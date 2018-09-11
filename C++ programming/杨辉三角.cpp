using namespace std;
#include <iostream>

int main(){
	
	int tri[31][31];
	int i,j,n;
	
	for(i=0;i<31;i++)
		for(j=0;j<31;j++)
			 tri[i][j] =1;
	for(i=3;i<31;i++)
		for(j=2;j<i;j++)
			tri[i][j] = tri[i-1][j-1]+tri[i-1][j];
	while(cin>>n){
		i = 1;
		while(i<=n){
			j = 1;
			while(j<=i){
				if(j!=1) cout<<' ';
				cout<<tri[i][j];
				j++;
			}
			cout<<endl;
			i++;
		}
		cout<<endl;		
		
	}				 
	
	
	return 0;
} 
