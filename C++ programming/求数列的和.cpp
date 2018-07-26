using namespace std;
#include <iostream>
#include <cmath>
#include <iomanip> 

int main(){
	
	int m,n,i,j;
	double result,k;
	while(cin>>n>>m){
		i = 0;
		result = 0;
		while(i<m){
			j = 0;
			k = n;
			while(j<i){
				k = sqrt(k);
				j++;
			} 
			result += k;
			
			
			i++;
		}
		
		cout<<fixed<<setprecision(2)<<result<<endl;
		
		
		
	}
	
	return 0;
}
