using namespace std;
#include <iostream>
#define MAX_INPUT 10

typedef struct {
	int module, index;
}element;

void process() {
	element input[MAX_INPUT];
	int mod,ind;
	int count = 0;
	while(cin>>mod>>ind){
		if(count == MAX_INPUT){
			cout<<"overflow"<<endl;
			return ;
		}
		else if(mod==0 && ind==0) {
			break;
		} 
		else{
			input[count].module = mod;
			input[count].index = ind;
			count++;
		} 

	}
	cout<<input[0].module<<"X^"<<input[0].index;
	for(int i=1;i<count;i++) {
		if(input[i].module > 0) {
			if(input[i].index == 0) cout<<"+"<<input[i].module;
			else if(input[i].index == 1) cout<<"+"<<input[i].module<<"X";
			else cout<<"+"<<input[i].module<<"X^"<<input[i].index;
		} 
		else if(input[i].module < 0){
			if(input[i].index == 0) cout<<input[i].module;
			else if(input[i].index == 1) cout<<input[i].module<<"X";
			else cout<<input[i].module<<"X^"<<input[i].index;
		}
	}
}

int main() {
	process();
	return 0;
}
