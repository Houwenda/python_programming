/* 
using namespace std;
#include <iostream>

int main(){
	
	int t,i,j;
	int f[30];
	int n[10];
	while(cin>>t){
		i = 0;
		while(i<t){
			cin>>n[i];
			i++;
		}
		i = 0;
		for(i=0;i<30;i++) f[i] = 0;  //初始化数组 
		i = 0;
		while(i<t){
			f[1] = 2;
			for(j=2;j<n[i];j++) f[j] = f[j-1]*3 + 2;
			f[n[i]] = f[n[i]-1] + 2;
			cout<<f[n[i]]<<endl;
			
			i++;
		}
	}
	return 0;
}
*/
/* 
using namespace std;
#include <iostream>
#include <cmath>

int main(){
	int t;
	while(cin>>t){
		int i = 0;
		int n;
		while(i<t){
			cin>>n;
			int count = 2;
			for(int j=2;j<n;j++) count = count*3 + 2;
			if(n==1) count = 0;
			cout<<(count+2)<<endl;
			i++;
		}
	}
	return 0;
}
*/
using namespace std;
#include <iostream>

int main(){
	int t;
	while(cin>>t){
		int i = 0;
		int n;
		while(i<t){
			cin>>n;
			int count = 2;
			for(int j=2;j<n;j++) count = 3 * count + 2;
			if(n==1) count = 0;
			cout<<count+2<<endl;
			i++;
		}
	}
	return 0;
}

