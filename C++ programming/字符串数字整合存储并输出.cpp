using namespace std;
#include <iostream>
int StrToInt(char *str,int *b)
{ 
	int n=0,i=0,j=0,m,number=0;
    while(i<40)
	{                
		if(*(str+i)>47&&*(str+i)<58)                
		{                   
			m=0;                   
			while(*(str+i+m)>47&&*(str+i+m)<58)
			{                      
				number*=10;                    
				number+=*(str+i+m)-48;
				m++; 
			}                   
			*(b+j)=number;
			number=0;                  
			j++;
			n++;
			i+=m-1;
    	}
		i+=1;
    }
	return n;
}
int main(void)
{    
	char str[100];
	int a[50],num,i=0;
	cin.getline(str,99);
	num=StrToInt(str,a);
    while(i<num) 
	{
		cout<<*(a+i)<<endl;
		i++;
	}
	cout<<num<<endl;
}

