/*
using namespace std;
#include <iostream>
#include <iomanip>
#include <cmath>

int main(){
	
	int t,i;
	double time[10][3];
	double angle1,angle2,angle;
	while(cin>>t){
		i = 0;
		while(i<t){
			cin>>time[i][0]>>time[i][1]>>time[i][2];
			i++;
		}
		i = 0;
		while(i<t){		
			if(time[i][0]>12) time[i][0] -= 12;
			angle1 = 30.0*time[i][0] + 0.5*time[i][1] + double(0.5)/60.0*time[i][2];
			angle2 = 6.0*time[i][1] + 0.1*time[i][2];
			angle = fabs(angle2-angle1);
			if(angle<=180){
				if(angle-int(angle)>=0.5) angle++;
				cout<<fixed<<setprecision(0)<<angle<<endl;
			}	
			else{
				angle = 360 - angle;
				//if(angle-int(angle)>=0.5) angle++;
				cout<<fixed<<setprecision(0)<<angle<<endl;
			}
			i++;
		}
	}
	return 0;
}
*/
using namespace std;
#include <iostream>
#include <cmath>
#include <iomanip>

int main(){
	int T;
	cin>>T;
	while(T--){
		int  h,m,s;
		cin>>h>>m>>s;
		double angle1,angle2;
		angle1 = (h%12) * 30.0 + m * 0.5 + s * 0.5/60.0;
		angle2 = 6.0 * m + 0.1 * s;
		double angle = fabs(angle1-angle2);
		if(angle>180) angle = 360.0 - angle;
		cout<<int(angle)<<endl;
	}
	return 0;
}
