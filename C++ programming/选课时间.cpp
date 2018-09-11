using namespace std;
#include <iostream>

int main(){
	
	int a[9],b[9];
	int dp[55];
	int sum;
	int _,k,n,i,j,l;
	
	cin>>_;
	while(_--){
		for(i=0;i<55;i++) dp[i] = 0;
		cin>>n>>k;
		for(i=1;i<=k;i++){
			cin>>a[i]>>b[i];
		}
		dp[0] = 1;
		for(i=1;i<=k;i++)
			for(j=n;j>=a[i];j--)
				for(l=1;l<=b[i];l++){
					if(j-a[i]*l>=0) dp[j] += dp[j-a[i]*l];
					else break;				
				}
		cout<<dp[n]<<endl;
	}
	
	return 0;
} 
