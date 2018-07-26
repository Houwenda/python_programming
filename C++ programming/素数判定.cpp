using namespace std;
#include <iostream>
#include <cmath>

bool sushu(int n){
	
	int i=2;
	while(i<=sqrt(n)){
		
		if(n%i==0){
			return false;
		}		
		i++;
	}
	
	return true;
}


int main(){
	
	int x,y,i,j;
	while(cin>>x>>y){
		if(x==0&&y==0){
			return 0;
		}
		i = x;
		while(i<=y){
			j = i*i + i +41;
			if(!sushu(j)){
				cout<<"Sorry"<<endl;
				break;
			}			
			i++;
		}
		if(i==y+1){
			cout<<"OK"<<endl;
		}
		
	}
	
	
	
	return 0;
}
