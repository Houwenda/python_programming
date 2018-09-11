using namespace std;
#include <iostream>

int main(){
	
	int t,i;
	int time[10][3];
	int angle1,angle2,angle;
	while(cin>>t){
		i = 0;
		while(i<t){
			cin>>time[i][0]>>time[i][1]>>time[i][2];
			i++;
		}
		i = 0;
		while(i<t){		
			if(time[i][0]>12) time[i][0] -= 12;
			angle1 = 30*time[i][0] + 0.5*time[i][1] + double(0.5)/60*time[i][2];
			angle2 = 6*time[i][1] + 0.1*time[i][2];
			angle = int(angle2-angle1);
			if(angle<0) angle = -angle;
			if(angle>180) angle = 360 - angle;
			cout<<angle<<endl;
			i++;
		}
	}
	return 0;
}
