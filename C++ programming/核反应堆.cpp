using namespace std;
#include <iostream>

int main(){
	
	int n;
	while(cin>>n){
		if(n == -1) return 0;
		long long int high = 1;
		long long int low = 0;
		for(int i=0;i<n;i++){
			long long int tmp1 = high * 3 + low * 2;
			long long int tmp2 = high + low;
			high = tmp1;
			low = tmp2;
		}
		cout<<high<<", "<<low<<endl;
	}
	return 0;
}
