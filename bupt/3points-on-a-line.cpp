#include<stdio.h>

//暴力求解，枚举出所有的三点 
int main(){
    int t,n,i,j,k;
    double x[105],y[105];
    for(scanf("%d",&t);t--;){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lf%lf",x+i,y+i);
        int sig=0;
        for(i=0;i<n&&!sig;i++)
            for(j=i+1;j<n&&!sig;j++){
                for(k=j+1;k<n&&!sig;k++){
                    if((y[k]-y[i])/(x[k]-x[i])==(y[j]-y[i])/(x[j]-x[i]))sig=1;
                }
            }
        if(sig)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

