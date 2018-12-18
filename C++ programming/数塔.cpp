/*
using namespace std;
#include <iostream>
#include <algorithm>
#include <cstring>
 
int main(){
	
	int n[105][105],dp[105][105];
	int C;
	cin>>C;
	while(C--){
		int N;
		cin>>N;
		for(int i=1;i<=N;i++)
			for(int j=1;j<=i;j++)
				cin>>n[i][j];
		memset(dp,0,sizeof(dp));
		for(int i=N;i>=1;i--){
			for(int j=1;j<=i;j++){
				dp[i][j] = n[i][j] + max(dp[i+1][j],dp[i+1][j+1]);
			}
		}
		cout<<dp[1][1]<<endl;
	}
	
	return 0;
}
*/
/*
using namespace std;
#include <iostream>
#include <algorithm>
#include <cstring>

int main(){
	
	int C;
	int a[105][105],dp[105][105];
	cin>>C;
	while(C--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
				cin>>a[i][j];
		memset(dp,0,sizeof(dp));
		for(int i=n;i>=1;i--)
			for(int j=1;j<=i;j++)
				dp[i][j] = a[i][j] + max(dp[i+1][j],dp[i+1][j+1]);
		cout<<dp[1][1]<<endl;
	}
	return 0;
} 
*/
using namespace std;
#include <iostream>
#include <cstring>

int main(){
	int C;
	cin>>C;
	int a[105][105],dp[105][105];
	while(C--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
				cin>>a[i][j]; 
		memset(dp,0,sizeof(dp));
		for(int i=n;i>=1;i--)
			for(int j=1;j<=i;j++)
				dp[i][j] = a[i][j] + max(dp[i+1][j],dp[i+1][j+1]);
		cout<<dp[1][1]<<endl; 
	}
	return 0;
}
