using namespace std;
#include <iostream>

int main(){
	
	char str[100];
	int i;
	while(cin.getline(str,100)){
		
		str[0] -= 32;
		
		i = 0;
		while(str[i]!='\0'){
			
			if(str[i]==' '){
				
				str[i+1] -= 32;
			}
			
			i++;
		} 
		
		cout<<str<<endl;
		
		
	}
	
	return 0;
}
