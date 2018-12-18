using namespace std;
#include <iostream>
#include <math.h>
#include <iomanip>

int main(){
	int t;
	double location[10][4];
	double angle;
	
	cin>>t;
	int i=0;
	while(i<t){
		cin>>location[i][0]>>location[i][1]>>location[i][2]>>location[i][3];		
		i++;
	}
	i=0;
	while(i<t){
		double mo = location[i][0] * location[i][2] + location[i][1] * location[i][3];
		double ji = sqrt(location[i][0]*location[i][0]+location[i][1]*location[i][1])
			* sqrt(location[i][2]*location[i][2]+location[i][3]*location[i][3]);
		angle =  acos(mo / ji) / 3.1415927 * 180.0;
		cout<<fixed<<setprecision(2)<<angle<<endl;
		i++;
	}
	
	return 0;
} 
