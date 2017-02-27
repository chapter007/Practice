#include <stdio.h>
#include <vector>
#define N 1001
using namespace std;

struct E
{
    int next,c;
    int cost;
};

vector<E> edge[N];
int dis[N];
int cost[N];
bool mark[N];

int main()
{
    int n,m;
    int S,T;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(m==0&&n==0) break;
        for(int i=1;i<=n;i++) edge[i].clear();
        while(m--)
        {
            int a,b,c,cost;
            scanf("%d %d %d %d",&a,&b,&c,&cost);
            E tmp;
            tmp.c=c;
            tmp.cost=cost;
            tmp.next=b;
            edge[a].push_back(tmp);
            tmp.next=a;
            edge[b].push_back(tmp);
        }//录入信息
        scanf("%d %d",&S,&T);
        for(int i=1; i<=n; i++)
        {
            dis[i]=-1;
            mark[i]=false;
        }//初始化
        dis[S]=0;
        mark[S]=true;
        int newP=S;
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<edge[newP].size(); j++)
            {
                int t=edge[newP][j].next;
                int c=edge[newP][j].c;
                int co=edge[newP][j].cost;
                if(mark[t]==true) continue;
                if(dis[t]==-1||dis[t]>dis[newP]+c||dis[t]==dis[newP]+c&&cost[t]>cost[newP]+co)
                {
                    dis[t]=dis[newP]+c;
                    cost[t]=cost[newP]+co;//更新花费和路程
                }
            }//dijstra处理过程
            int min=123123123;
            for(int j=1; j<=n; j++)
            {
                if(mark[j]==true) continue;
                if(dis[j]==-1) continue;
                if(dis[j]<min)
                {
                    min=dis[j];
                    newP=j;
                }
            }
            mark[newP]=true;
        }
        printf("%d %d\n",dis[T],cost[T]);
    }
    return 0;
}
