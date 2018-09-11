using namespace std;
#include <iostream>

int main(){
	
	int n,i,j;
	string str[50];
	bool judge[50];
	
	while(cin>>n){
		
		for(i=0;i<n;i++) judge[i] = 1;
		i = 0;
		while(i<n){
			cin>>str[i];
			i++;
		}
		i = 0;
		while(i<n){
//			if(str[i].length() % 2 == 1){
				j = 0;
				while(j < str[i].length()/2){
					if(str[i][j] != str[i][str[i].length()-1-j]){
						judge[i] = 0;
						break;
					}
					j++;
				}
			
			i++;
		}
		
		i = 0;
		while(i<n){
			if(judge[i]==1) cout<<"yes"<<endl;
			else cout<<"no"<<endl;
			i++;
		}
		
	}
	
	return 0;
}
