using namespace std;
#include <iostream>

int main(){
	
	char str[50][50];
	int n,i,j;
	int count[50][5];
	
	while(cin>>n){
		cin.ignore();
		i = 0;
		while(i<n){
			cin.getline(str[i],50);
//			cout<<str[i];
			i++;
		}
		i = 0;
		while(i<n){
			
			for(j=0;j<5;j++) count[i][j]=0;
			
			j = 0;
			while(str[i][j]!='\0'){
				if(str[i][j]=='a') count[i][0] += 1;
				else if(str[i][j]=='e') count[i][1] += 1;
				else if(str[i][j]=='i') count[i][2] += 1;
				else if(str[i][j]=='o') count[i][3] += 1;
				else if(str[i][j]=='u') count[i][4] += 1;
				j++;
			}
			i++;
		}
		i = 0;
		while(i<n-1){
			
			cout<<"a:"<<count[i][0]<<endl;
			cout<<"e:"<<count[i][1]<<endl;
			cout<<"i:"<<count[i][2]<<endl;
			cout<<"o:"<<count[i][3]<<endl;
			cout<<"u:"<<count[i][4]<<endl;
			cout<<endl;
			
			i++;
		}
		cout<<"a:"<<count[i][0]<<endl;
		cout<<"e:"<<count[i][1]<<endl;
		cout<<"i:"<<count[i][2]<<endl;
		cout<<"o:"<<count[i][3]<<endl;
		cout<<"u:"<<count[i][4]<<endl;
		
	}
	
	return 0;
}
