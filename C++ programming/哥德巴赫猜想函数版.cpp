using namespace std;
#include <iostream>
bool panduan(int n)
{
	bool sushu=0;
	int a=2;
	while(a<n)
	{
		if(n%a==0) break;
		a++;
	}
	if(a==n) sushu=1;
	return sushu;
}
int main()
{
	int input,i=2;
	bool sushu;
	cin>>input;
	while(i<=input/2)
	{
		if(panduan(i)==1)
		{
			if(panduan(input-i)==1) cout<<input<<'='<<i<<'+'<<input-i<<' ';
		}
		i++;
	}
	return 0;
}
