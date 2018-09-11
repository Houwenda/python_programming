using namespace std;
#include <iostream> 

int main(){
	
	int n,i,j,count;
	char str[10][1000];
	while(cin>>n){
		cin.ignore();
		i = 0;
		while(i<n){
			cin.getline(str[i],1000);
			i++;
		}
		i = 0;
		while(i<n){
			count = 0;
			j = 0;
			while(str[i][j]!='\0'){
				
				if(str[i][j]<0) count++;
				
				j++;
			}
			cout<<count/2<<endl;	
			i++;
		}
		
	}
		
	return 0;
}
