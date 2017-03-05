#include <stdio.h>
#include <algorithm>
#define N 100001

using namespace std;

int max(int a,int b){
	return a>b?a:b; 
}

int dp[100];

int main()
{
    int T;
    while(scanf("%d",&T)!=EOF)
    {
        while(T--)
        {
            int n;
            int a[100],b[N]= {0},c[N]= {0};
            scanf("%d",&n);
            for(int i=0; i<n; i++)
            {
                scanf("%d",&a[i]);
            }//input
            for(int i=0;i<n;i++){
            	int tmax=1;
            	for(int j=0;j<i;j++){
            		int d=a[j]-a[j+1];
            		if(a[j+1]-a[j+2]==d){
            			tmax=max(tmax,dp[j]+1);
					}
				}
				dp[i]=tmax;
			}
			int ans=1;
			for(int i=0;i<n;i++){
				ans=max(ans,dp[i]);
			}
			printf("%d\n",ans+1);
        }
    }
    return 0;
}
