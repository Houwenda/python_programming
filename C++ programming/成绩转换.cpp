using namespace std;
#include <iostream>

int main(){
	
	int i,j,score[10];
	char c,c1,c2;
	i = 0;
	while(true){
		c = 0;
		c1 = cin.get();
		if(c1 == '\n'){
			break;
		}
		c += int(c1)-48;
		while(true){
			c2 = cin.get();
			if(c2 == '\n'){
				break;
			}
			c *= 10;
			c+= int(c2)-48;
		}
		score[i] = c;
		i++;		 
	}
	j = 0;
	while(j<i){
		if(score[j]>100 || score[j]<0) cout<<"Score is error!"<<endl;
		else if(score[j]>=90) cout<<'A'<<endl;
		else if(score[j]>=80) cout<<'B'<<endl;
		else if(score[j]>=70) cout<<'C'<<endl;
		else if(score[j]>=60) cout<<'D'<<endl;
		else cout<<'E'<<endl;
		j++;
	}
	
	return 0;
}
