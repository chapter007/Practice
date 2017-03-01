#include <stdio.h>

long long hanuo(int n){
	if(n==1) return 2;
	else return 3*hanuo(n-1)+2;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		printf("%lld\n",hanuo(n));
	}
	return 0;
} 
