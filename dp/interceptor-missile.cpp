#include <stdio.h>

int max(int a,int b){
	return a>b ? a:b;
}
int dp[30],m[30];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&m[i]);
		}//input
		for(int i=1;i<=n;i++){
			int tmax=1;
			for(int j=1;j<i;j++){
				if(m[j]>=m[i]){
					tmax=max(tmax,dp[j]+1);
				}
			}
			dp[i]=tmax;
		}//dp 赋值 
		int ans=1;
		for(int i=1;i<=n;i++){
			ans=max(ans,dp[i]);
		}//寻找最长的 
		printf("%d\n",ans); 
	}
	return 0;
}
