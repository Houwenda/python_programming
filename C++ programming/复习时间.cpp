#include <iostream>
#include <algorithm>

int main(){
	int _,n,m;
	int i,j,a;
	while(std::cin>>_){
		i = 0;
		while(i<_){
			
			std::cin>>n>>m;
			j = 0;
			a = 0;
			int ans = 100;
			while(j<n){
				std::cin >> a;
				ans = std::min(ans, a);
				j++;
			}
			i++;
			printf("%d\n", (100-ans)*(100-ans));
		}
				
	}
	return 0;
} 
