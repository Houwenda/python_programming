/* 
using namespace std;
#include <iostream>
#include <cstring>

int main(){
	
	int n,i,j;
	bool flag,result[50];
	string str[50];
//	string keyword[] = {"char","double","enum","float","int","long","short","signed","struct","union","unsigned","void","for","do","while","break","continue","if","else","goto","switch","case","default","return","auto","extern","register","static","const"};
	while(cin>>n){
		i = 0;
		while(i<n){
			cin>>str[i]; 
			i++;
		}
		i = 0;
		while(i<n){
			flag = 0;
//			cout<<str[i][0];
			if((str[i][0]>='a'&&str[i][0]<='z')||str[i][0]=='_'||(str[i][0]>='A'&&str[i][0]<='Z')){}
			else{
				flag = 1;
//				break;
			}
 
			j = 1;
//			cout<<str[i].length();
			while(j<str[i].length()){
				if((str[i][j]>='0'&&str[i][j]<='9')||(str[i][j]>='a'&&str[i][j]<='z')||str[i][j]=='_'||(str[i][0]>='A'&&str[i][0]<='Z')){}
				else{
					flag = 1;
					break;
				}
				j++;
			} 
//			j = 0;
//			while(j<n){
//				if(strcmp(str+i,keyword+j)==0){
//					flag = 1;
//					break;
//				} 
//				j++;
//			}
			
			if(flag==1) result[i] = 1;
			else result[i] = 0;
			
			i++;
		}
		i = 0;
		while(i<n){
			if(result[i]==0) cout<<"yes"<<endl;
			else cout<<"no"<<endl;
			i++;
		}
		
		
	}
	
	
	return 0;
}
*/
using namespace std;
#include <iostream>
#include <cstring>
int main(){
	
	int n;
	cin>>n;
	cin.ignore();
	char str[50];
	int i=0;
	while(i<n){
		cin.getline(str,50);
		bool flag = true;
		if((str[0]>='a'&&str[0]<='z')||(str[0]>='A'&&str[0]<='Z')||str[0]=='_'){
		}
		else flag = false;
		for(int j=0;j<strlen(str);j++){
			if((str[j]>='0'&&str[j]<='9')||(str[j]>='a'&&str[j]<='z')||(str[j]>='A'&&str[j]<='Z')||str[j]=='_'){
			}
			else flag = false;
		}	
		if(flag) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
		i++;
	} 
	
	
	return 0;
}
