/* 
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
*/
using namespace std;
#include <iostream>

int main(){
	
	int n;
	int num[100];
	while(cin>>n){
		for(int i=0;i<n;i++) cin>>num[i];
		int result = 1;
		for(int i=0;i<n;i++){
			if(num[i]%2==1) result *= num[i];
		}
		cout<<result<<endl;
	}
	

	return 0;
}
