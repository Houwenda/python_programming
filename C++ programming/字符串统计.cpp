using namespace std;
#include <iostream>

int main(){
	int n,i,j;
	int result[10];
	string x=" ";
	for(i=0;i<10;i++) result[i] = 0;
	cin>>n;
		i = 0;
		while(i<n){
			
				cin>>x;
				j = 0;
				while(j<x.length()){
					
					if(x[j]>='0'&&x[j]<='9'){
					result[i] += 1;	
					}
					j++;
				}
						
			i++;
		}
				
	i = 0;
	while(i<n){
			
		cout<<result[i]<<endl;
		i++;
	}
	
	return 0;
}
