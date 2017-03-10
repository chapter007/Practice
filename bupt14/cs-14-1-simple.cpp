#include <stdio.h>
#include <algorithm>
#define N 100001

using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int num[101]={0},cnt[N]={0},n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&num[i]);
			cnt[num[i]]++;
		}//input
		int max=0,ans[N]={0};
		for(int i=0;i<N;i++){
			if(cnt[i]>max) max=cnt[i]; 
		}
		for(int i=0;i<N;i++){
			if(cnt[i]==max){
				ans[i]=i;
			}
		}
		sort(ans,ans+N);
		for(int i=0;i<N;i++){
			if(ans[i]>0){
				printf("%d\n",ans[i]);
				break;
			}
		}
		
	}
	return 0;
} 
