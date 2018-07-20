//using namespace std;
//#include <iostream>
//
//int main(){
//	
//	char c;
//	int x,y,n,i,j;
//	int result[10][2]; 
//	
//	n = 0;
//	while(true){
//		c = cin.get();
//		if(c=='\n'){
//			break;
//		}
//		x = int(c)-48;
//		cin>>y;
//		cin.get();
//	
//		if(x%2 == 0){
//			j = 0;
//			for(i=x;i<=y;i+=2){
//				j += i*i;
//			}
//			result[n][0] = j;
//			j = 0;
//			for(i=x+1;i<=y;i+=2){
//				j += i*i*i;
//			}
//			result[n][1] = j;
//		}
//		else{
//			j = 0;
//			for(i=x;i<=y;i+=2){
//				j += i*i*i;
//			}
//			result[n][1] = j;
//			j = 0;
//			for(i=x+1;i<=y;i+=2){
//				j += i*i;
//			}
//			result[n][0] = j;						
//		}
//	
//		n++;	
//	}
//	
//	for(i=0;i<n;i++){
//		cout<<result[i][0]<<' '<<result[i][1]<<endl;
//	}
//	
//	return 0;
//} 
using namespace std;
#include <iostream>
int main(){
	int x,y,m,i,j;
	while(cin>>x>>y){
		if(x>y){
			m = x;
			x = y;
			y = m;		
		}
		if(x%2 == 0){
			j = 0;
			for(i=x;i<=y;i+=2){
				j += i*i;
			}
			cout<<j<<' ';
			j = 0;
			for(i=x+1;i<=y;i+=2){
				j += i*i*i;
			}
			cout<<j<<endl;
		}
		else{
			j = 0;
			for(i=x+1;i<=y;i+=2){
				j += i*i;
			}
			cout<<j<<' ';
			j = 0;
			for(i=x;i<=y;i+=2){
				j += i*i*i;
			}
			cout<<j<<endl;
									
		}	
	}

	return 0;
} 
