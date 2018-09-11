using namespace std;
#include <iostream>
#include <iomanip>
 
int main(){
	
	int m,n,i,j,count;
	double score[50][5];
	double sum;
	double average,score_average[5];
	while(cin>>n>>m){
		i = 0;
		while(i<n){
			j = 0;
			while(j<m){
				cin>>score[i][j];
				j++;
			}
			i++;
		}
		
		i = 0;
		while(i<n-1){
			j = 0;
			sum = 0;
			while(j<m){
				sum += score[i][j];
				j++;
			}
			average = sum/m;
			cout<<fixed<<setprecision(2)<<average<<' ';
			i++;
		}
		j = 0;
		sum = 0;
		while(j<m){
			sum += score[i][j];
			j++;
		}
		average = sum/m;
		cout<<fixed<<setprecision(2)<<average<<endl;
		
		i = 0;
		while(i<m-1){
			j = 0;
			sum = 0;
			while(j<n){
				sum += score[j][i];
				j++;
			}
			average = sum/n;
			score_average[i] = average;
			cout<<fixed<<setprecision(2)<<average<<' ';
			i++; 
		}
		j = 0;
		sum = 0;
		while(j<n){
			sum += score[j][i];
			j++;
		}
		average = sum/n;
		score_average[i] = average;
		cout<<fixed<<setprecision(2)<<average<<endl;
		
		i = 0;
		count = 0;
		while(i<n){
			j = 0;
			while(j<m){
				if(score[i][j]<score_average[j]) break;
				j++;
			}
			if(j==m) count++;
			i++;
		}
		cout<<count<<endl;
		cout<<endl;
	}

	return 0;
}
