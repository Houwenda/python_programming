using namespace std;
#include <iostream>
#include <cmath>
int main(){
	int m;
	cin>>m;
	int i=0;
	int location[10000];
	while(i<m){
		int n;
		cin>>n;
		for(int j=0;j<n;j++) cin>>location[j];
		int j = 0;
		int time = 1000000000;
		while(j<n){
			int tmp_time = 0;
			for(int k=0;k<n;k++) tmp_time += abs(location[k] - location[j]);
			if(tmp_time < time) time = tmp_time;
			j++;
		}
		cout<<time<<endl; 
		i++;
	}
	
	return 0;
} 
