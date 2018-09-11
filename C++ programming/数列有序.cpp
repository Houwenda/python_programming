using namespace std;
#include <iostream>

int main(){
	
	bool flag;
	int m,n,i;
	int num[100];
	while(cin>>n>>m){
		
		if(n==0&&m==0){
			return 0;
		}
		i = 0;
		while(i<n){
			cin>>num[i];
			i++;
		}
		i = 0;
		flag = 0;
		while(i<n-1){
			if(m<num[i]){
				cout<<m;
				flag = 1;
			}
			else{
				cout<<num[i]<<' ';
			}
			i++;
		}
		if(flag==0){
			if(m<num[i]){
				cout<<m<<' '<<num[i]<<endl;
			}
			else{
				cout<<num[i]<<' '<<m<<endl;
			}
		}
		else{
			cout<<num[i]<<endl;
		}
	}

	return 0;
}
