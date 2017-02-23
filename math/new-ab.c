#include <stdio.h>

int main(){
	int a,b,m;
	while(scanf("%d",&m)!=EOF&&m!=0){
		scanf("%d %d",&a,&b);
		long long ans=0;
		ans=a+b;
		int idx=0;
		char num[20];
		while(ans!=0){
			num[idx++]=ans%m;
			ans/=m;
		}
		num[idx]=0;
		for(int i=idx-1;i>=0;i--){
			printf("%d",num[i]);
		}
		printf("\n");
	}
	return 0;
}
