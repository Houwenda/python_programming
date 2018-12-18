using namespace std;
#include <iostream>
#define MAX_SIZE 100
#define DATATYPE int

//≥ı ºªØ
DATATYPE stack[MAX_SIZE];
int j=0,k=MAX_SIZE-1; 

bool push(DATATYPE x, int i) {
	if(j == k){
		cout<<"’ª¬˙"<<endl;
		return false; 
	} 
	else{
		if(i == 1){
			stack[j] = x;
			j++;
			return true;
		}
		else if(i == 2){
			stack[k] = x;
			k--;
			return true;
		}
		return false;
	}
}

bool pop(DATATYPE& y, int i) {
	if(i == 1){
		if(j == -1){
			cout<<"’ªø’"<<endl;
			return false;
		}
		else{
			j--;
			y = stack[j+1];
			return true;
		}
	}
	else if(i == 2){
		if(k == MAX_SIZE){
			cout<<"’ªø’"<<endl;
			return false;
		}
		else{
			k++;
			y = stack[k-1];
			return true;
		}
	}
	else return false;
}

int main() {		
	return 0;
} 
