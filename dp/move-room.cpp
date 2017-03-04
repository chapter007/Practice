#include <stdio.h>
#include <algorithm>
#define INF 0x7fffffff

using namespace std;

int weight[2001];
int dp[2001][2001];


int main(){
	int n,k;
	while(scanf("%d %d",&n,&k)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&weight[i]);
		}
		sort(weight+1,weight+1+n);
		for(int i=0;i<2001;i++) dp[0][i]=0;
		for(int i=1;i<=k;i++){
			for(int j=2*i;j<=n;j++){
				if(j>2*i){
					dp[i][j]=dp[i][j-1];
				}else{
					dp[i][j]=INF;
				}
				int tmp=(weight[j]-weight[j-1])*(weight[j]-weight[j-1]);
				//printf("Test %d\n",tmp);
				if(dp[i][j]>dp[i-1][j-2]+tmp){
					dp[i][j]=dp[i-1][j-2]+tmp;
				}
				//printf("Test %d\n",dp[i][j-1]);
			}
		}
		printf("%d\n",dp[k][n]);
	}
	return 0;
} 
