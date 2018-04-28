using namespace std;
#include <iostream>
bool searchCond1(float f)
{
	if(f/10==5) return true;
}
float *searchCond2(float *f)
{
	int i=0;
	while(i<8)
	{
		if(*(f+i)/10==1) return f+i;		
		i++;
	}

}
int main()
{
	bool (*searchcond1)(float f);
	float *(*searchcond2)(float *f);
	float a[8]={1,2,3,4,5,6,7,8};
	searchcond1=searchCond1;
	searchcond2=searchCond2;	
	searchcond2(a);
	searchcond1(5);
	return 0;
}
