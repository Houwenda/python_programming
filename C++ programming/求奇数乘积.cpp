using namespace std;
#include <iostream>

int main(){
	
	int n,i,result;
	while(cin>>n){
		i = 0;
		result = 1;
		while(i<n){
			int* num = NULL;
			num = new int;
			cin>>*num;
			if(*num%2 == 1){
				result *= *num;	
			}	
			delete num;	
			i++;		
		}
		
		cout<<result<<endl;
				
	} 
		
	return 0;
} 
