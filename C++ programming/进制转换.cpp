using namespace std;
#include <iostream>

int main(){
	
	int n,r,i,a,sign;
	int str[32];
	while(cin>>n>>r){
		if(n<0){
			sign = 1;
			a = -n;
		} 
		else{
			sign = 0;
			a = n;
		} 

			i = 0;
			while(a/r!=0){
				str[i] = a%r;
				a = a/r;
				i++;
			}
			i--;
			if(sign==0){}
			else cout<<'-';
			
			if(r<10){
				cout<<a;
				while(i>0){
					cout<<str[i];
					i--;
				}
				cout<<str[i]<<endl;					
			}
			else{
				if(a>9){
					cout<<char(a-10+'A');
				}
				else cout<<a;
				while(i>0){
					if(str[i]>9) cout<<char(str[i]-10+'A');
					else cout<<str[i];
					i--;
				}
				if(str[i]>9) cout<<char(str[i]-10+'A')<<endl;
				else cout<<str[i]<<endl;
			}
			

		
	}
	
	
	
	return 0;
} 
