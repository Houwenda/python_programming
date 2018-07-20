//using namespace std;
//#include <iostream>
//#include <iomanip>
//#include <cmath>
//
//int main(){
//	char c;
//	float distance[10]; 
//	int i=0,j=0;
//	float x1,x2,y1,y2;
//	while(true){
//		c = cin.get();
//		if(c == '\n'){
//			break;
//		}
//		x1 = float(c)-48;
//		cin>>y1>>x2>>y2;
//		cin.get();
//		distance[i] = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//		i++;
//	}
//	while(j<i){
//		
//		cout<<fixed<<setprecision(2)<<distance[j]<<endl;
//		
//		j++;
//	}
//	
//	return 0;
//}
using namespace std;
#include <iostream>
#include <cmath> 
#include <iomanip>

int main(){
	
	float x1,x2,y1,y2,distance;
	while(cin>>x1>>y1>>x2>>y2){
		
		distance = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		cout<<fixed<<setprecision(2)<<distance<<endl;
	}
	
	
	return 0;
} 
