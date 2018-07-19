using namespace std;
#include <iostream>

bool year_flag(int year){
	
	if(year%100 == 0){
		if(year%400 == 0){
			return true;
		}
		else return false;
	}
	else if(year%4 == 0){
		return true;
	}
	else return false;
	
}

int count_day(char *date){
	
	int m,n,year=0,month=0,day=0,count=0;
	int mon[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	n = 0;
//	cout<<date;
	while(date[n]!='/'){
		year*=10;
		year += date[n]-48;
		n++;
	}
//	cout<<year<<endl;
	n+=1;
	while(date[n]!='/'){
		month*=10;
		month += date[n]-48;
		n++;
	}
//	cout<<month<<endl;
	n+=1;
	while(date[n]!= '\0'){
		day*=10;
		day += date[n]-48;
		n++;
		if(n == 11) break;
	}
//	cout<<day;
	
	if(year_flag(year)){
		mon[1] = 29;
	}
	m = 0;
	while(m<month-1){
		count += mon[m];
		m++;
	}
	
	count += day;
	
	return count;
}



int main(){
	
	char date[5][11];
	char c;
	int i,j;
	
	i = 0;
	while(true){
		
		c = cin.get();
		if(c == '\n'){
			break;
		} 	
		date[i][0] = c;
		cin.getline(*(date+i)+1,10);				
//		cout<<date[i]<<endl;
		i++;
		
	} 
	
	j = i;
//	cout<<i;
	i = 0;
	while(i<j){
//		count_day(date[i]);
		cout<<count_day(date[i])<<endl;
				
		i++;
		
	}
	
	return 0;
}
