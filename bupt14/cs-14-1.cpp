#include <stdio.h>
#include <algorithm>
#define N 100001

using namespace std;

struct S{
	int num;
	int cnt;
	bool operator < (const S &A) const{
		return cnt>A.cnt;
	}
}s1[N];

void clean(){
	for(int i=0;i<N;i++){
		s1[i].num=0;		
		s1[i].cnt=0;				
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int num[101]={0},n;
		clean();
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&num[i]);
			s1[num[i]].num=num[i];
			s1[num[i]].cnt++;
			//cnt[num[i]]++;
		}//input
		int max=0,ans[N]={0};
		for(int i=0;i<N;i++){
			if(s1[i].cnt>max) max=s1[i].cnt; 
		}
		for(int i=0;i<N;i++){
			if(s1[i].cnt==max){
				ans[i]=s1[i].num;
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
