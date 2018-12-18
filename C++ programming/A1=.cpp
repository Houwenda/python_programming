/*
using namespace std; 
#include<iostream>  
#include<iomanip>  

const int maxn = 3003;  
double a[maxn], c[maxn];  
int main()
{
    int n, i, j;  
    while (cin>>n){  
    	cin>>a[0]>>a[n+1]; 
        for (i = 1; i <= n; i++)  
        {  
            cin>>c[i];  
        }  
        a[1] = n*a[0] + a[n+1];  
        double sum = 0;  
        for (i = n, j = 1; i >=1&&j <= n; j++,i--)  
        {  
            sum += i*c[j];  
        }  
        a[1] = (a[1] - 2*sum)/(n+1);  
        cout<<fixed<<setprecision(2)<<a[1]<<endl;          
    }
    
    return 0;  
}  
*/
/*
using namespace std;
#include <iostream>

int main(){
	
	int n;
	int a[3003],c[3003];
	while(cin>>n){
		cin>>a[0]>>a[n+1];
		for(int i=1;i<=n;i++) cin>>c[i];
		a[1] = n*a[0] + a[n+1];
		double sum = 0;
		for(int i=n,int j=1;i>=1&&j<=n;j++,i--){
			sum += c[j]*i;
		}
		a[1] = (a[1] - 2*sum)/(n + 1); 
		cout<<fixed<<setprecision(2)<<a[1]<<endl; 
	}
	return 0;
} 
*/
/*
using namespace std;
#include <iostream>
#include <iomanip>
#include <cmath>

int main(){
	int n;
	while(cin>>n){
		double a[3003],c[3003];
		cin>>a[0]>>a[n+1];
		for(int i=1;i<=n;i++) cin>>c[i];
		a[1] = n*a[0] + a[n+1];
		double sum = 0;
		int i,j;
		for(i=n,j=1;i>=1&&j<=n;j++,i--){
			sum += i * c[j];
		}
		a[1] = (a[1] - 2*sum) / (n + 1);
		cout<<fixed<<setprecision(2)<<a[1]<<endl;		
	}
	
	return 0;
} 
*/
using namespace std;
#include <iostream>
#include <iomanip>
 
int main(){
	int n;
	while(cin>>n){
		double a[3003],c[3003];
		cin>>a[0]>>a[n+1];
		a[1] = n*a[0] + a[n+1];
		for(int i=1;i<=n;i++) cin>>c[i];
		double sum = 0;
		for(int i=n,j=1;i>=1&&j<=n;j++,i--) sum += i*c[j];
		a[1] = (a[1] - 2*sum) / (n+1);
		cout<<fixed<<setprecision(2)<<a[1]<<endl;
	}
	return 0;
}
