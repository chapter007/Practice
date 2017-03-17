#include <stdio.h>
#include <string.h>

int main(){
	int n,t,t2,sum,sum2;
	while(scanf("%d",&n)!=EOF){
		sum=0;
		sum2=0;
		t=0;t2=0;
		int m=n*n;
		if(n==0) break;
		while(n!=0){
			t=n%10;
			n/=10;
			sum+=t;
		}
		while(m!=0){
			t2=m%10;
			m/=10;
			sum2+=t2;
		}
		printf("%d %d\n",sum,sum2);
	}
	return 0;
} 
