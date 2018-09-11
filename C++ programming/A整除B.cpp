using namespace std;
#include <iostream>

int main(){
	
	int t,i;
	int  data[20][2];
	while(cin>>t){
		
		i = 0;
		while(i<t){
			cin>>data[i][0]>>data[i][1];
			i++;
		}
		i = 0;
		while(i<t){
			
			if(data[i][0]%data[i][1]==0) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
			
			i++;
		}
		
	}
	
	return 0;
} 
