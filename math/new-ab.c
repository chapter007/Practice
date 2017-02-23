#include <stdio.h>

int main(){
	long long a,b;
	int m;
	while(scanf("%d",&m)!=EOF&&m!=0){
		scanf("%lld %lld",&a,&b);
		a=a+b;
		int idx=0;
		char num[50];
		do{
			num[idx++]=a%m;
			a/=m;
		}while(a!=0);
		num[idx]=0;
		for(int i=idx-1;i>=0;i--){
			printf("%d",num[i]);
		}
		printf("\n");
	}
	return 0;
}
