#include <stdio.h>
#include <queue>

using namespace std;

struct N
{
    int a,b,c;//三个杯子里可乐的量
    int t;//倒的次数
};
queue<N> Q;
bool mark[101][101][101];

void AtoB(int &a,int sa,int &b,int sb)
{
//sa,sb是a，b两个杯子的容量， a，b是引用一开始原始杯子里的可乐量，调用后就是新的可乐容量
    if(sb-b>=a)
    {
        b+=a;
        a=0;
    }
    else
    {
        a-=sb-b;
        b=sb;
    }
}

int BFS(int s,int n,int m)
{
    while(!Q.empty())
    {
        N now=Q.front();//取队首
        Q.pop();
        int a=now.a;
        int b=now.b;
        int c=now.c;
        AtoB(a,s,b,n);
        if(mark[a][b][c]==false){
            mark[a][b][c]=true;
            N tmp;
            tmp.a=a;
            tmp.b=b;
            tmp.c=c;
            tmp.t=now.t+1;
            if(a==s/2&&b==s/2) return tmp.t;
            if(c==s/2&&b==s/2) return tmp.t;
            if(a==s/2&&c==s/2) return tmp.t;
            Q.push(tmp);
        }
        a=now.a;
        b=now.b;
        c=now.c;
        AtoB(b,n,a,s);
        if(mark[a][b][c]==false){
            mark[a][b][c]=true;
            N tmp;
            tmp.a=a;
            tmp.b=b;
            tmp.c=c;
            tmp.t=now.t+1;
            if(a==s/2&&b==s/2) return tmp.t;
            if(c==s/2&&b==s/2) return tmp.t;
            if(a==s/2&&c==s/2) return tmp.t;
            Q.push(tmp);
        }
        a=now.a;
        b=now.b;
        c=now.c;
        AtoB(a,s,c,m);
        if(mark[a][b][c]==false){
            mark[a][b][c]=true;
            N tmp;
            tmp.a=a;
            tmp.b=b;
            tmp.c=c;
            tmp.t=now.t+1;
            if(a==s/2&&b==s/2) return tmp.t;
            if(c==s/2&&b==s/2) return tmp.t;
            if(a==s/2&&c==s/2) return tmp.t;
            Q.push(tmp);
        }
        a=now.a;
        b=now.b;
        c=now.c;
        AtoB(c,m,a,s);
        if(mark[a][b][c]==false){
            mark[a][b][c]=true;
            N tmp;
            tmp.a=a;
            tmp.b=b;
            tmp.c=c;
            tmp.t=now.t+1;
            if(a==s/2&&b==s/2) return tmp.t;
            if(c==s/2&&b==s/2) return tmp.t;
            if(a==s/2&&c==s/2) return tmp.t;
            Q.push(tmp);
        }
        a=now.a;
        b=now.b;
        c=now.c;
        AtoB(b,n,c,m);
        if(mark[a][b][c]==false){
            mark[a][b][c]=true;
            N tmp;
            tmp.a=a;
            tmp.b=b;
            tmp.c=c;
            tmp.t=now.t+1;
            if(a==s/2&&b==s/2) return tmp.t;
            if(c==s/2&&b==s/2) return tmp.t;
            if(a==s/2&&c==s/2) return tmp.t;
            Q.push(tmp);
        }

        a=now.a;
        b=now.b;
        c=now.c;
        AtoB(c,m,b,n);
        if(mark[a][b][c]==false){
            mark[a][b][c]=true;
            N tmp;
            tmp.a=a;
            tmp.b=b;
            tmp.c=c;
            tmp.t=now.t+1;
            if(a==s/2&&b==s/2) return tmp.t;
            if(c==s/2&&b==s/2) return tmp.t;
            if(a==s/2&&c==s/2) return tmp.t;
            Q.push(tmp);
        }
    }
    return -1;
}

int main()
{
    int s,n,m;
    while(scanf("%d %d %d",&s,&n,&m)!=EOF)
    {
        if(s==0) break;
        if(s%2==1){
            puts("NO");
            continue;
        }
        for(int i=0;i<=s;i++){
            for(int j=0;j<=n;j++){
                for(int k=0;k<=m;k++){
                    mark[i][j][k]=false;
                }
            }
        }
        N tmp;
        tmp.a=s;
        tmp.b=0;
        tmp.c=0;
        tmp.t=0;

        while(!Q.empty()) Q.pop();//初始化队列
        mark[s][0][0]=true;
        Q.push(tmp);
        int rec=BFS(s,n,m);
        if(rec==-1) puts("NO");
        else printf("%d\n",rec);;
    }
    return 0;
}

