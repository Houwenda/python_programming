using namespace std;
#include <iostream>
int count(int money){
	int a=0,b=0,c=0,d=0,e=0,f=0;
	int n,m;
	a = money/100;
	n = money - a*100;
	b = n/50;
	m = n - 50*b;
	c = m/10;
	n = m - 10*c;
	d = n/5;
	m = n - 5*d;
	e = m/2;
	f = m - 2*e;

	return (a+b+c+d+e+f);
}
int main(){
	
	int n,i,num;
	int salary[100];
	while(cin>>n){
		if(n==0) return 0;
		i = 0;
		while(i<n){
			cin>>salary[i];
			i++;
		}
		num = 0;
		i = 0;
		while(i<n){
			num += count(salary[i]);
			i++;
		}
		cout<<num<<endl;	
	}
	
	
	return 0;
} 
