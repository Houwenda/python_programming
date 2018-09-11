using namespace std;
#include <iostream>

int main(){
	
	string str;
	int n,i,j;
	
	while(cin>>str){
		
		n = 0;
		i = 0;
		while(i<str.length()){
			if(int(str[i]) > n){
				n = int(str[i]);
			}
			i++;
		}
		i = 0;
		while(i<str.length()-1){
			
			if(n==str[i]){
				cout<<str[i]<<"(max)";
			}
			else cout<<str[i];
			
			i++;
		}	
		if(str[i]==n){
			cout<<str[i]<<"(max)"<<endl;
		}
		else cout<<str[i]<<endl;
		
	}
	
	return 0;
}
