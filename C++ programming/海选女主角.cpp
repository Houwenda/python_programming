using namespace std;
#include <iostream>

int main(){
	int m,n,i,j;
	int location[2]={0,0};
	long temp,score[1005],score1[1005],max_score;
	bool sign[1005];
	while(cin>>m>>n){
		i = 0;
		while(i<(m*n)){
			cin>>score[i];
			i++;	
		} 
		i = 0;
		while(i<(m*n)){
			score1[i] = score[i];
			i++;
		}
		for(i=0;i<(m*n);i++) sign[i] = 0;
		for(i=0;i<(m*n);i++){
			if(score[i]<0){
				score[i] = -score[i];
				sign[i] = 1;
			}
		}
		for(i=0;i<(m*n-1);i++){
			for(j=0;j<(m*n-1-i);j++){
				if(score[j]<score[j+1]){
					temp = score[j];
					score[j] = score[j+1];
					score[j+1] = temp;
					temp = sign[j];
					sign[j] = sign[j+1];
					sign[j+1] = temp;
				}
			}
		}
//		for(i=0;i<)
		if(sign[0] = 1){
			max_score = -score[0];
		}
		else max_score = score[0];
		i = 0;
		while(i<m*n){
			if(score1[i] == max_score){
				j = i+1;
				if(j%n==0){
					location[0] = j/n;
					location[1] = n;	
				} 
				else{
					location[0] = j/n + 1;
					location[1] = j - n*(j/n);
				}	
				break;
			}
			i++;
		}
		cout<<location[0]<<' '<<location[1]<<' '<<max_score<<endl;
	}
	
	return 0;
} 
