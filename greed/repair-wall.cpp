#include <stdio.h>
#include <algorithm>

using namespace std;

bool cmp(long long a,long long b){
	return a>b;
}

int main(){
	int N;
	long long L,Ai[601];
	while(scanf("%lld %d",&L,&N)!=EOF){
		long long sum=0;
		int cnt=0;
		for(int i=0;i<N;i++){
			scanf("%lld",&Ai[i]);
		}
		sort(Ai,Ai+N,cmp);
		bool finish=false;
		for(int i=0;i<N;i++){
			sum+=Ai[i];
			cnt++;
			if(sum>=L){
				printf("%d\n",cnt);
				finish=true;
				break;
			}
		}
		if(!finish) printf("impossible\n");
	}
	return 0;
}
