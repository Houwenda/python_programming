/*
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
*/ 
using namespace std;
#include <iostream>
#include <cstring>
int main(){
	
	char str[100];
	int count[5];
	int n;
	cin>>n;
	cin.ignore();
	int i=0;
	while(i<n){
		cin.getline(str,100);
		for(int j=0;j<5;j++) count[j] = 0;
		for(int j=0;j<strlen(str);j++){
			if(str[j]=='a') count[0]++;
			else if(str[j]=='e') count[1]++;
			else if(str[j]=='i') count[2]++;
			else if(str[j]=='o') count[3]++;
			else if(str[j]=='u') count[4]++;
		}
		cout<<"a:"<<count[0]<<endl;
		cout<<"e:"<<count[1]<<endl;
		cout<<"i:"<<count[2]<<endl;
		cout<<"o:"<<count[3]<<endl;
		cout<<"u:"<<count[4]<<endl;
		if(i!=n-1) cout<<endl;	

		i++;
	}
	
	return 0;
}
