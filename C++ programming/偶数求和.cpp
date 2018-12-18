/* 
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
*/
using namespace std;
#include <iostream>

int main(){
	
	int n,m;
	int num[100];
	for(int i=0;i<100;i++) num[i] = 2*i+2;
	while(cin>>n>>m){
		if(n%m==0){
			int i = 0;
			while(i<n/m){
				int sum = 0;
				for(int j=0;j<m;j++){
					sum += num[i*m+j];
				} 
				if(i==n/m-1) cout<<sum/m<<endl;
				else cout<<sum/m<<' ';
				i++;
			}
		}
		else{
			int i = 0;
			while(i<n/m){
				int sum = 0;
				for(int j=0;j<m;j++){
					sum += num[i*m+j];
				}
				cout<<sum/m<<' ';
				i++;
			}
			int sum = 0;
			//cout<<"i="<<i<<endl;
			for(int j=0;j<n-i*m;j++) sum += num[i*m+j];
			cout<<sum/(n%m)<<endl;
		}	
	}
	return 0;
} 
