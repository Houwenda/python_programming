using namespace std;
#include <iostream>

int count(int year){
	if(year<4){
		return year;
	}
	else{
		return count(year-1)+count(year-3);
	}
}

int main(){
	
	int n;
	
	while(cin>>n){
		
		if(n == 0) return 0;
		
		cout<<count(n)<<endl;

	}
	
	return 0;
}
