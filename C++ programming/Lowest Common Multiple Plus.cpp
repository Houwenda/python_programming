/*
using namespace std;
#include <iostream>

unsigned int getgcd(unsigned int a,unsigned int b){
	
	unsigned int c;
	while(b){
		
		c = a;
		a = b;
		b = c%b;
	}
	return a;
}

int main(){
	
	int n,i;
	unsigned int arr[20];
	 
	while(cin>>n){
		
		i = 0;
		while(i<n){
			cin>>arr[i];
			if(i!=0){
				arr[i] = arr[i-1]/getgcd(arr[i-1],arr[i])*arr[i];	
			}
			
			i++;
		}		
		cout<<arr[n-1]<<endl;
	}
	return 0;
}
*/
using namespace std;
#include <iostream>

int main(){
	
	int n;
	int num[100];
	while(cin>>n){
		for(int i=0;i<n;i++) cin>>num[i];
		int i = 1;
		int result = 0;
		while(true){
			int j = 1;
			for(j=1;j<n;j++){
				if((i*num[0])%num[j]==0){}
				else break;
			}
			if(j==n){
				result = i*num[0]; 
				break;
			} 
			i++;
		} 
		cout<<result<<endl;
	}
 	return 0;
}
