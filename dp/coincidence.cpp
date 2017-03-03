#include <stdio.h>
#include <string.h>

int max(int a,int b){
	return a>b?a:b;
}
int dp[101][101];
char s1[101],s2[101];
int main(){
	while(scanf("%s %s",s1,s2)!=EOF){
		int L1=strlen(s1);
		int L2=strlen(s2);
		for(int i=0;i<L1;i++){
			dp[i][0]=0;
		}
		for(int j=0;j<L2;j++){
			dp[0][j]=0;
		}
		for(int i=1;i<=L1;i++){
			for(int j=1;j<=L2;j++){
				if(s1[i-1]==s2[j-1]){//字符下标从0开始 
					dp[i][j]=dp[i-1][j-1]+1;
				}else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		printf("%d\n",dp[L1][L2]);
	}
	return 0;
} 
