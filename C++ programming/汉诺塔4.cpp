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
