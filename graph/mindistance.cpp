#include <stdio.h>
#define N 101
int graph[N][N];

void init(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            graph[i][j]=-1;
        }
        graph[i][i]=0;
    }
}

int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        if(n==0&&m==0) break;
        init();
        while(m--){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            graph[a][b]=graph[b][a]=c;//对邻接矩阵赋值
        }
        for(int k=1;k<=n;k++){
             for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){//三重循环实现的floyid算法
                    if(graph[i][k]==-1||graph[k][j]==-1) continue;
                    if(graph[i][j]==-1||graph[i][k]+graph[k][j]<graph[i][j]) graph[i][j]=graph[i][k]+graph[k][j];
                }
            }
        }
        printf("%d\n",graph[1][n]);//输出结果
    }
    return 0;
}
