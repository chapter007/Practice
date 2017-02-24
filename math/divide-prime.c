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
	int c=2;
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

void outPut(){
		for(int i=2;i<10000;i++){
		if(mark[i])
			printf("%d ",i);
	}
}
int main(){
	int n;
	init();

	while(scanf("%d",&n)!=EOF){
		int c[100],ans=0;
		for(int i=0;i<n;i++){
			if(mark[i]&&n%i==0){
				int m=n;
				while(m%i==0){
					m/=i;
					//printf("%d ",i);
					ans++;
				}
			}
		}
		
		printf("%d\n",ans);
	}
	return 0;
}
