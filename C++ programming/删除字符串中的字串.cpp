using namespace std;
#include <iostream>
#include <cstring>
char* delSubstr(char *s, char *ss)
{
	int i=0,j=0,n;
	while(j<strlen(s))
	{
		i=0;
		n=0;
		while(i<strlen(ss))
		{
			if(*(s+j+i)==*(s+i)) n+=1;
			i++;
		}
		if(n==strlen(ss)-1)  //·¢ÏÖ×Ó´® 
		{
			memmove(s+j,s+i,strlen(s)-j-i);
			continue;
		}
		j++;
	}	
	return s;
}
int main()
{
	char s[5],ss[4];
	cin.getline(s,4);
	cin.getline(ss,3);
	cout<<delSubstr(s,ss);
	return 0;
}

