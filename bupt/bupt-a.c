#include <stdio.h>

int main(){
//give n num,calcu these num odd sum and oshu sum
	int T,N;
	int num[101];
	while(scanf("%d",&T)!=EOF){
		for(int i=0;i<T;i++){
			int ansj=0,anso=0;
			scanf("%d",&N);
			for(int j=0;j<N;j++){
				scanf("%d",&num[j]);
				if(num[j]%2==0) anso+=num[j];
				else ansj+=num[j];
			}
			printf("%d %d\n",ansj,anso);
		}
	}
	return 0;
}
