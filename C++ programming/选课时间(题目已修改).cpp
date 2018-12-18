/*
using namespace std;
#include <iostream> 
#include <math.h>
#include <string.h>
#include <algorithm>
#include <cmath>
 
const int N = 55;
 
int sum;
int dp[N];
 
struct node
{
	int a, b;
}cla[N];
 
int main()
{

    int t, n, k;
    cin>>t;
    while(t--)
    {
        memset(dp, 0, sizeof(dp));
        cin>>n>>k;
        for(int i = 1; i <= k; i ++)
        {
        	cin>>cla[i].a>>cla[i].b;
        }
        dp[0] = 1;
        for(int i = 1; i <= k; i ++)
            for(int j = n; j >= cla[i].a; j --)//ÈÝÁ¿
                for(int l = 1; l <= cla[i].b; l ++)//ÊýÁ¿
                {
                    if(j - cla[i].a * l >= 0) dp[j] += dp[j - cla[i].a * l];
                    else break;
                }
    	cout<<dp[n]<<endl;
    }
    return 0;
}
*/
/* 
using namespace std;
#include <iostream>
#include <cstring>

struct node{
	int a,b;
}cla[55];

int main(){
	int T;
	cin>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=k;i++) cin>>cla[i].a>>cla[i].b;
		int dp[55];
		memset(dp,0,sizeof(dp));
		dp[0] = 1;
		for(int i=1;i<=k;i++)
			for(int j=n;j>=cla[i].a;j--)
				for(int l=1;l<=cla[i].b;l++){
					if(j-cla[i].a*l>=0) dp[j] += dp[j-cla[i].a*l];
					else break;
				}
		cout<<dp[n]<<endl;				
	}
	return 0;
}
*/
using namespace std;
#include <iostream>
#include <cstring>

struct node{
	int a,b;
}cla[55];

int main(){

	int T;
	cin>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=k;i++) cin>>cla[i].a>>cla[i].b;
		int dp[55];
		memset(dp,0,sizeof(dp));
		dp[0] = 1;
		for(int i=1;i<=k;i++)
			for(int j=n;j>=cla[i].a;j--)
				for(int l=1;l<=cla[i].b;l++){
					if(j-cla[i].a*l>=0) dp[j] += dp[j-cla[i].a*l];
					else break;
				}
		cout<<dp[n]<<endl;
	}

	return 0;
}
