#include <iostream>
using namespace std;

int main()
{
	int b,p;																	//声明变量 
	cout<<"Don't you have a little b number in your heart?(y=1/n=0)"<<'\n';		//输出 
	cin>>p;																		//读入 
	/*判断有无*/ 
	if (p==1) 																	//若有 
	{
		cout<<"Then what's your b number?"<<'\n';  								 
		cin>>b;
		cout<<"Good!Your b number is    "<<b<<'\n';	
	}
	else if (p==0)																//若无 
	{
		cout<<"没有？那你很棒棒哦！";
	}
	else																		//错误输入 
	{
		cout<<"蛤？";
		
	}
	return 0;
 } 
