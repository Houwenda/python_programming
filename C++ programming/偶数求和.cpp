using namespace std;
#include <iostream>

int main(){
	int m,n,i,j,x,sum;
	while(cin>>n>>m){
		i = 0;
		x = 0;
		while(i<n){
		
			j = 0;
			sum = 0;
			while(j<m){
				x += 2;	
				sum += x;
				
				i++;
				if(i==n) break;
				j++;
			}
			if(i<n){
				cout<<sum/m<<' ';
			}
		}
		if(n%m!=0){
			cout<<sum/(n%m)<<endl;
		}
		else cout<<sum/m<<endl;
	}
			
	return 0;
}  
