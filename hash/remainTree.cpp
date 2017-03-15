#include <stdio.h>
#include <string.h>

int main(){
	int L,M;
	int buf[10001];
	while(scanf("%d %d",&L,&M)!=EOF){
		memset(buf,0,sizeof(buf));
		int cnt=0; 
		for(int i=0;i<M;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			for(int i=x;i<=y;i++){
				buf[i]=1;
			}
		}
		for(int i=0;i<10001;i++){
			if(buf[i]==1) cnt++;
		}
		printf("%d\n",L-cnt+1);
	}
	return 0;
}
