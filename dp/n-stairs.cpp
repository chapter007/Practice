#include <stdio.h>

int main(){
	long long F[99];
	int n;
	F[1]=1;
	F[2]=2;
	for(int i=3;i<=99;i++){
		F[i]=F[i-1]+F[i-2];
	}
	while(scanf("%d",&n)!=EOF){
		printf("%lld\n",F[n]);
	}
	return 0;
}
