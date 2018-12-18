/* 
using namespace std;
#include <iostream>

int main(){
	int n,i,j,temp;
	int num[100];
	int sign[100];
	while(cin>>n){
		if(n==0) return 0;
		i=0;
		while(i<n){
			cin>>num[i];
			i++;
		}
		for(i=0;i<n;i++) sign[i] = 0;	
		for(i=0;i<n;i++){
			if(num[i]<0){
				num[i] = -num[i];
				sign[i] = 1; 
			}	
		}
		for(i=0;i<n-1;i++){
			for(j=0;j<n-1-i;j++){
				if(num[j]<num[j+1]){
					temp = num[j];
					num[j] = num[j+1];
					num[j+1] = temp;
					temp = sign[j];
					sign[j] = sign[j+1];
					sign[j+1] = temp;
				}
				
			} 
		} 
		i = 0;
		while(i<n-1){
			if(sign[i]==0) cout<<num[i]<<' ';
			else cout<<-num[i]<<' ';
			i++;
		}
		if(sign[i]==0) cout<<num[i]<<endl;
		else cout<<-num[i]<<endl;
	}
	
	return 0;
}
*/
using namespace std;
#include <iostream>

int main(){
	
	int n;
	int num[100];
	bool sign[100];
	while(cin>>n){
		if(n==0) return 0;
		for(int i=0;i<n;i++) cin>>num[i];
		for(int i=0;i<n;i++){
			if(num[i]<0){
				num[i] = - num[i];
				sign[i] = 1;
			}
			else{
				sign[i] = 0;
			}
		}
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n-1-i;j++){
				if(num[j]<num[j+1]){
					int tmp = num[j];
					num[j] = num[j+1];
					num[j+1] = tmp;
					bool temp = sign[j];
					sign[j] = sign[j+1];
					sign[j+1] = temp;
				}
			}
		}
		int i=0;
		for(i=0;i<n-1;i++){
			if(sign[i]==1) cout<<'-'<<num[i]<<' ';
			else cout<<num[i]<<' ';
		}
		if(sign[n-1]==1) cout<<'-'<<num[i]<<endl;
		else cout<<num[n-1]<<endl; 
	}
	
	return 0;
}
