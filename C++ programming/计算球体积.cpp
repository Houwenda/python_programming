//using namespace std;
//#include <iostream>
//#include <iomanip>
//#define PI 3.1415927
//
//int main(){
//	double r;
//	int i=0,j;
//	double v[10];
//	while(cin>>r){
//		v[i] = 1.3333*PI*r*r*r;
//		i++;
//	}
//	
//	j = 0;
//	while(j<i-1){		
//		cout<<fixed<<setprecision(3)<<v[j]<<endl;
//		j++;
//	}
//	cout<<fixed<<setprecision(3)<<v[j];
//	
//	return 0;
//}
using namespace std;
#include <iostream>
#include <iomanip>
#define PI 3.1415927
#define A  1.33333333
int main(){
	
	double r,v;
	while(cin>>r){		
		v = (4.0000000/3)*PI*r*r*r;
//		cout<<fixed<<setprecision(3)<<v<<endl;
		printf("%.3lf\n",v);
	}
	
	
	return 0;
} 
