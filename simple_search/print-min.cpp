#include <stdio.h>
#include <string.h>

int main(){
	int m,n;
	int num[81];
	scanf("%d",&m);
	while(m--){
		memset(num,0,sizeof(num));
		//getchar();
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&num[i]);
		}
		bool first=true;
		for(int i=0;i<n;i++){
			if(i>0&&i<n-1){
				if(num[i]>num[i-1]&&num[i]>num[i+1]){
					if(first) {
						printf("%d",i);
						first=false;
					}
					else printf(" %d",i);
				}
				if(num[i]<num[i-1]&&num[i]<num[i+1]){
					if(first) {
						printf("%d",i);
						first=false;
					}
					else printf(" %d",i);
				}
			}
			if(i==0){
				if(num[i]>num[i+1]||num[i]<num[i+1]){
					if(first) {
						printf("%d",i);
						first=false;
					}
					else printf(" %d",i);
				}
			}
			if(i==n-1){
				if(num[i]>num[i-1]||num[i]<num[i-1]){
					if(first) {
						printf("%d",i);
						first=false;
					}
					else printf(" %d",i);
				}
			}
		}
		printf("\n");
	}
	return 0;
}
