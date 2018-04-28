using namespace std;
#include <iostream>
#include <cstring>
char *findChar(char *s, char c)
{
	int i=0;
	while(i<100)
	{
		if(*(s+i)==c) return s+i;		
		else i++;
	}
	return NULL;
}
int main(void)
{
	char s[100],c,*p;
	cin.getline(s,99);
	cin.get(c);
	p=findChar(s,c);
	if(p==NULL)
		cout<<"No found"<<endl;
	else
		cout<<p;
}

