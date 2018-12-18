using namespace std;
#include <iostream>

int main(){
	int n,i,min;
	int num[100];
	while(cin>>n){
		if(n==0) return 0;
		i = 0;
		while(i<n){	
			cin>>num[i];		
			i++;
		}
		i = 0;
		min = num[0];
		while(i<n){
			if(num[i]<min){
				min = num[i];
			}
			i++;
		}
		i -= 1;
		while(i>0){
			if(min == num[i]){
				break;
			}			
			i--;
		}
		num[i] = num[0];
		num[0] = min;
		
		i = 0;
		while(i<n-1){
			cout<<num[i]<<' ';
			i++;
		}
		cout<<num[i]<<endl;
	}
	return 0;
}
