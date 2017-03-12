#include<stdio.h>
#include<string.h>
int vis[40040],head[40040],n,m,x[40040],y[40040],cnt,pre[40040],z[40040];
struct s
{
    int u,v,next;
}edge[4000*2];
void init()
{
    memset(vis,0,sizeof(vis));
    memset(head,-1,sizeof(head));
    cnt=0;
}
void add(int u,int v)
{
    edge[cnt].u=u;
    edge[cnt].v=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
int find(int x)
{
    if(x==pre[x])
        return x;
    return find(pre[x]);
}
void tarjan(int u)
{
    int i;
    pre[u]=u;
    vis[u]=1;
    for(i=1;i<=m;i++)
    {
        if(x[i]==u&&vis[y[i]])
            z[i]=find(y[i]);
        else
            if(y[i]==u&&vis[x[i]])
                z[i]=find(x[i]);
    }
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].v;
        if(!vis[v])
        {
            tarjan(v);
            pre[v]=u;
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int i;
        init();
        for(i=0;i<n-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            add(u,v);
            add(v,u);
        }
        scanf("%d",&m);
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
        }
        tarjan(1);
        for(i=1;i<=m;i++)
        {
            printf("%d\n",z[i]);
        }
    }
}
