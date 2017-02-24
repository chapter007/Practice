#include <stdio.h>
#include <math.h>

bool mark[10000];

bool judge(int x){
	if(x<=1) return false;
	int bound=(int)sqrt(x)+1;
	for(int i=2;i<bound;i++){
		if(x%i==0) return false;
	}
	return true;
}
void init(){
	int c=1;
	for(int i=2;i<=10000;i++){
		mark[i]=judge(i);
		if(mark[i]){
			//i is prime
			while(i*c<=10000){
				mark[i*c]=false;
				c++;
			}
		}
	}
}

int main(){
	int n;
	init();
	while(scanf("%d",&n)!=EOF){
		bool first=true;
		int k=0;
		for(int i=0;i<n;i++){
			if(mark[i]&&i%10==1){
				if(first){
					printf("%d",i);
					first=false;
				}else printf(" %d",i);

				k=1;
			}
		}
		if(k==0) printf("-1");

		printf("\n");
	}
	return 0;
}
