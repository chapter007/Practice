#include <stdio.h>

char outputbuf[20][20];
int main(){
	int T;
	while(scanf("%d",&T)!=EOF){
		while(T--){
			int m,n;
			scanf("%d %d",&n,&m);
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if(j==0||j==m-1||i==0||i==n-1){
						outputbuf[i][j]='#';
					}else{
						outputbuf[i][j]='*';
					}
				}
			}
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					printf("%c",outputbuf[i][j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
