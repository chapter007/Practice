#include <stdio.h>
int main(){
	int n;
	int num[200];
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&num[i]);
		}
		int x,ans=-1;
		scanf("%d",&x);
		for(int i=0;i<n;i++){
			if(x==num[i]){
				ans=i;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

