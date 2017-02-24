#include <stdio.h>
#include <math.h>

bool mark[100001];
int prime[100001];
int primeSize;

bool judge(int x){
	if(x<=1) return false;
	int bound=(int)sqrt(x)+1;
	for(int i=2;i<bound;i++){
		if(x%i==0) return false;
	}
	return true;
}
void init(){
	for(int i=2;i<=100000;i++){
		if(mark[i]==true) continue;
		prime[primeSize++]=i;
		if(i>=1000) continue;
		for(int j=i*i;j<=100000;j+=i){
			mark[j]=false;
		}
	}
}
void outPut(){
	for(int i=0;i<100001;i++)
		printf("%d ",mark[i]);
}
int main(){
	int n;
	init();
	//outPut();
	while(scanf("%d",&n)!=EOF){
		int ans=0;
		int ansPrime[30];
		int ansNum[30];
		for(int i=0;i<primeSize;i++){
			if(n%prime[i]==0){
				ansPrime[ans]=prime[i];
				ansNum[ans]=0;
				while(n%prime[i]==0){
					ansNum[ans]++;
					n/=prime[i];
				}
				ans++;
				if(n==1) break;
			}
		}
		if(n!=1){
			ansPrime[ans]=n;
			ansNum[ans++]=1;
		}
		int an=0;
		for(int i=0;i<ans;i++){
			an+=ansNum[i];
		}
		printf("%d\n",an);
	}
	return 0;
}
