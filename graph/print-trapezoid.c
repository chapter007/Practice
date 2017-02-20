#include <stdio.h>

int main(){
	int h;
	while(scanf("%d",&h)!=EOF){
		int maxline=h+(h-1)*2;
		for(int i=1;i<=h;i++){
			for(int j=0;j<maxline;j++){
				int tmp=h+(i-1)*2;
				if(j<maxline-tmp) printf(" ");
				else printf("*");
			}
			printf("\n");
		}
	}
	return 0;
}
