#include <stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,num[400]={0};
		bool order=false;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&num[i]);
		}
		for(int i=n-1;i>0;i--){
			if(num[i]>num[i-1]){
				//printf("test true %d %d\n",num[i],num[i-1]);
				order=true;
			}else{
				//printf("test false %d %d\n",num[i],num[i-1]);
				order=false;
				break;
			}
		}
		if(order){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}
