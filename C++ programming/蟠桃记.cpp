using namespace std;
#include <iostream>

int main(){
	int n,m,i;
	while(cin>>n){
		m = 1;
		i = 1;
		while(i<n){
			m += 1;
			m *= 2;			
			i++;
		}
		cout<<m<<endl;
		
	}

	return 0;
}
