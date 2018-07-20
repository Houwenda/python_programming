using namespace std;
#include <iostream>
#include <iomanip>

int main(){
	
	double num;

	while(cin>>num){
		if(num<0){
			cout<<fixed<<setprecision(2)<<-num<<endl;
		}
		else cout<<fixed<<setprecision(2)<<num<<endl;
	}

	return 0;
}
