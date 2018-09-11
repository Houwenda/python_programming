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
