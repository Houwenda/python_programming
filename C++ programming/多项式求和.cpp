using namespace std;
#include <iostream>
#include <iomanip>
int main(){
	
	int m,i,j,k;
	int n[1000];
	double result[1000],x;
	while(cin>>m){
		
		i = 0;
		while(i<m){
			
			cin>>n[i];			
			i++;
		}
		i = 0;
		while(i<m){
			x = 0;
			k = 1;
			j = n[i];
			while(k<=j){
				if(k%2==1){
					x += 1.00/k;
				}
				else{
					x -= 1.00/k;
				}
				k++;
			}
			result[i] = x;
			i++;
		}
		i = 0;
		while(i<m){
			cout<<fixed<<setprecision(2)<<result[i]<<endl;
			i++;
		}	
	}
	
	
	
	return 0;
}
