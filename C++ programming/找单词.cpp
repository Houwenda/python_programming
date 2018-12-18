/*
using namespace std;
#include <iostream>
#include <cstring> 
int main(){
	int N;
	cin>>N;
	while(N--){
		int w[30],num[30],dp[55][55];
		memset(w,0,sizeof(w));
		memset(dp,0,sizeof(dp));
		
		for(int i=1;i<=26;i++){
			w[i] = i;
			cin>>num[i];
		}
		dp[0][0] = 1;
		for(int i=1;i<=26;i++)
			for(int j=0;j<=50;j++)
				for(int k=0;k<=num[i]&&w[i]*k<=j;k++)
					dp[i][j] += dp[i-1][j-w[i]*k];
		int ans = 0;
		for(int i=1;i<=50;i++) ans += dp[26][i];	
		cout<<ans<<endl;	
	}
	return 0;
} 
*/
/*
using namespace std;
#include <iostream>
#include <cstring>
 
int main(){
	
	int n;
	cin>>n;
	while(n--){
		int w[30],num[30],dp[55][55];
		memset(w,0,sizeof(w));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=26;i++){
			w[i] = i;
			cin>>num[i];
		} 
		dp[0][0] = 1;
		for(int i=1;i<=26;i++)
			for(int j=0;j<=50;j++)
				for(int k=0;k<=num[i]&&w[i]*k<=j;k++)
					dp[i][j] += dp[i-1][j-w[i]*k];
		int ans = 0;
		for(int i=1;i<=50;i++) ans += dp[26][i];
		cout<<ans<<endl;		
	}
	return 0;
}
*/
using namespace std;
#include <iostream>
#include <cstring>

int main(){
	int N;
	cin>>N;
	while(N--){
		int w[30],num[30],dp[55][55];
		memset(w,0,sizeof(w));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=26;i++){
			w[i] = i;
			cin>>num[i];
		} 
		dp[0][0] = 1;
		for(int i=1;i<=26;i++)
			for(int j=0;j<=50;j++)
				for(int k=0;k<=num[i]&&w[i]*k<=j;k++)
					dp[i][j] += dp[i-1][j-w[i]*k];
		int ans=0;
		for(int i=1;i<=50;i++)	ans += dp[26][i];
		cout<<ans<<endl;
	}
	return 0;
}
