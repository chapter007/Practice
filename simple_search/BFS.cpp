#include <stdio.h>
#include <queue>

using namespace std;

bool mark[50][50][50];//标记点有没有走过
int maze[50][50][50];//保存立方体信息

struct N
{
    int x,y,z;//三维坐标
    int t;//时间
};
queue<N> Q;
int go[][3]=
{
    1,0,0,
    -1,0,0,
    0,1,0,
    0,-1,0,
    0,0,1,
    0,0,-1
};//坐标变换数组，由（x,y,z）扩展的数组，可以通过x+go[i][0]这样得到

int BFS(int a,int b,int c)
{
    while(!Q.empty())
    {
        N now=Q.front();//取队首
        Q.pop();
        for(int i=0; i<6; i++)
        {
            int nx=now.x+go[i][0];
            int ny=now.y+go[i][1];
            int nz=now.z+go[i][2];//计算新坐标
            if(nx<0||nx>=a||ny<0||ny>=b||nz<0||nz>=c) continue;//新坐标在立方体外面
            if(maze[nx][ny][nz]==1) continue;//碰到墙壁
            if(mark[nx][ny][nz]==true) continue;//已经标记过的
            N tmp;
            tmp.x=nx;
            tmp.y=ny;
            tmp.z=nz;
            tmp.t=now.t+1;
            Q.push(tmp);//新的入队
            mark[nx][ny][nz]=true;//这个点做上标记
            if(nx==a-1&&ny==b-1&&nz==c-1)
                return tmp.t;//这个时候已经到终点了
        }
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d",&n);//组数
    while(n--)
    {
        int a,b,c,t;//a,b,c是城堡的大小，t是大魔王回来的时间
        scanf("%d %d %d %d",&a,&b,&c,&t);
        for(int i=0; i<a; i++)
        {
            for(int j=0; j<b; j++)
            {
                for(int k=0; k<c; k++)
                {
                    scanf("%d",&maze[i][j][k]);//录入数据
                    mark[i][j][k]=false;//初始化标记数组
                }
            }
        }

        while(!Q.empty()) Q.pop();//初始化队列
        mark[0][0][0]=true;
        N tmp;
        tmp.x=tmp.y=tmp.z=tmp.t=0;//000作为起点
        Q.push(tmp);
        int rec=BFS(a,b,c);
        if(rec<=t) printf("%d\n",rec);//时间在大魔王回来的时间内即可
        else printf("-1\n");
    }

    return 0;
}
