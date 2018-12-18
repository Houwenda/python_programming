//using namespace std;
//#include <iostream>
//
//int main(){
//	char str[10][3];
//	char c,c1;
//	int line,i,j,m,n;
//	int flag[3];
//	
//	line = 0;
//	while(true){
//		c1 = cin.get(); 
//		if(c1 == '\n'){
//			break;
//		}
//		str[line][0] = c1;
//		str[line][1] = cin.get();
//		str[line][2] = cin.get();
//		c = cin.get();
////		cout<<str[line][0]<<' '<<str[line][1]<<' '<<str[line][2];
//		line++;
//	}
//	
//	i = 0;
////	cout<<line;
//	while(i<line){
//		
//		c = (str[i][0]<=str[i][1]?str[i][0]:str[i][1])<=str[i][2]?(str[i][0]<=str[i][1]?str[i][0]:str[i][1]):str[i][2];
////		cout<<c;
//		for(j=0;j<3;j++) flag[j] = 0;
//		j = 0;
//		while(j<3){
//			if(str[i][j] == c){
//				flag[j] = 1;
//				break;
//			}
//			j++; 
//		}
//		cout<<c<<' ';
//		
//		for(j=0;j<3;j++){
//			if(flag[j]==0){
//				m = str[i][j];
//				flag[j] = 1;
//				break;	
//			}			
//		}
//		for(j=0;j<3;j++){
//			if(flag[j]==0){
//				n = str[i][j];
//				break;
//			}
//		}
//		
//		if(m<=n){
//			cout<<char(m)<<' '<<char(n)<<endl;
//		}
//		else{
//			cout<<char(n)<<' '<<char(m)<<endl;
//		}
////		c1 = (str[i][0]>=str[i][1]?str[i][0]:str[i][1])>=str[i][2]?(str[i][0]>=str[i][1]?str[i][0]:str[i][1]):str[i][2];
////		j = 0;
////		while(j<3){
////			if(str[i][j] == c1){
////				flag[j] = 1;
////				break;
////			} 
////			j++;		
////		}
////		
////		for(j=0;j<3;j++){
////			if(flag[j]==0){
////				cout<<str[i][j]<<' ';
////				break;
////			}
////		}			
////		cout<<c1<<endl;
//		i++;
//	}
//	
//	return 0;
//}
/*
using namespace std;
#include <iostream>

int main(){
	
	char x,y,z,c,c1;
	int flag[3] = {0,0,0};
	while(cin>>x>>y>>z){
		
	for(int i=0;i<3;i++)	flag[i]=0;
	cin.get();		
	c = (x<y?x:y)<z?(x<y?x:y):z;
	cout<<c<<' ';
	if(c==x) flag[0] = 1;
	else if(c==y) flag[1] = 1;
	else flag[2] = 1;
	
	c1 = (x>y?x:y)>z?(x>y?x:y):z;
	if(c1==x) flag[0] = 1;
	else if(c1==y) flag[1] = 1;
	else flag[2] = 1;
		
	if(flag[0]==0)	cout<<x<<' ';
	else if(flag[1]==0)  cout<<y<<' ';
	else  cout<<z<<' ';
	
	cout<<c1<<endl;
	}
	
	return 0;
} 
*/
using namespace std;
#include <iostream>
#include <algorithm>

int main(){
	char letter[3];
	while(cin>>letter[0]>>letter[1]>>letter[2]){
		sort(letter,letter+3,less<char>());
		cout<<letter[0]<<' '<<letter[1]<<' '<<letter[2]<<endl;
	}
	return 0;
}
