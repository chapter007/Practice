#include <stdio.h>
#include <string.h>

int max(int a,int b){
	return a>b?a:b;
}

int main(){
	char s1[101],s2[101];
	while(scanf("%s %s",s1,s2)!=EOF){
		int L1,L2,dp[101][101];
		L1=strlen(s1);L2=strlen(s2);
		for(int i=0;i<=L1;i++) dp[i][0]=0;
		for(int j=0;j<=L1;j++) dp[0][j]=0;
		//init;
		for(int i=1;i<=L1;i++){
			for(int j=1;j<=L2;j++){
				if(s1[i-1]!=s2[j-1]){
					dp[i][j]=max(dp[i][j-1],dp[i-1][j]);//如果两个字符串不相等，dp[i][j]也要更新，更新为 dp之前的最大值 
				}else{
					dp[i][j]=dp[i-1][j-1]+1;//如果两个字符串相等，则dp[i][j]+1是在他的前一个版本的基础上+1的 
				}
			}
		}
		printf("%d\n",dp[L1][L2]);
	}
	return 0;
} 
