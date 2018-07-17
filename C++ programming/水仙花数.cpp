using namespace std;
#include <iostream>

bool cube(int num){
	
	int n,sum=0;
	n = num-(num/10)*10;
	sum += n*n*n;
	n = num/10-(num/100)*10;
	sum += n*n*n;
	n = num/100;
	sum += n*n*n;
	
	if(sum==num) {
		return true;
	}
	return false;
}


int main(){

    int num[10][2];
    int m=0,n=0,count=0,i=0,j=0,line;
	int daffodil[10];
	

	
	
	for(i=0;i<10;i++){
		daffodil[i] = 0;
	} 
	i = 0;
	j = 0;
	while(true){
		char c1 = cin.get();
		if(c1=='\n') break;
		cin>>m>>n;
		m += 100*(int(c1)-48);
		num[j][0] = m;
        num[j][1] = n;
  		j++;
  		
		char c = cin.get();
	
//		cout<<m<<' '<<n<<endl;		
	}

	i = 0;
	line = j;
	while(i<line){
		j = 0;
		while(j<10){
			daffodil[j] = 0;
			j++;
		}		 
		j = num[i][1] - num[i][0];
		count = 0;
		while(j>=0){
			
			if(cube(num[i][0]+j)){
				daffodil[count] = num[i][0]+j;
				count++;
			}
			
			j--;
		}
		count--;	
			
		if(count==-1){
			cout<<"no"<<endl;
		}
		
		else if(count==0){
			
			cout<<daffodil[0]<<endl;
				
		}
		
		else{
		
			while(count>0){
				
				cout<<daffodil[count];
				cout<<" ";
				count--;
				
			}
			cout<<daffodil[0]<<endl;
		}

		i++;
	}

    return 0;
}
