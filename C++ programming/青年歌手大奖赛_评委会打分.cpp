using namespace std;
#include <iostream>
#include <iomanip>

int main(){
	int n,i,max,min;
	double sum;
	int score[100];
	while(cin>>n){
		i = 0;
		while(i<n){
			cin>>score[i];			
			i++;
		}
		i = 0;
		max = score[0];
		min = score[0];
		while(i<n){
			if(score[i]>max){
				max = score[i];
			}
			if(score[i]<min){
				min = score[i];
			}
			i++;
		}
		sum = 0;
		i = 0;
		while(i<n){
			sum += score[i];			
			i++;
		}
		sum -= max;
		sum -= min;
		cout<<fixed<<setprecision(2)<<(sum/(n-2))<<endl;
		
	}

	return 0;
}
