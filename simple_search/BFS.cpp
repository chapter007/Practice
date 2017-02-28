#include <stdio.h>
#include <queue>

using namespace std;

bool mark[50][50][50];//��ǵ���û���߹�
int maze[50][50][50];//������������Ϣ

struct N
{
    int x,y,z;//��ά����
    int t;//ʱ��
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
};//����任���飬�ɣ�x,y,z����չ�����飬����ͨ��x+go[i][0]�����õ�

int BFS(int a,int b,int c)
{
    while(!Q.empty())
    {
        N now=Q.front();//ȡ����
        Q.pop();
        for(int i=0; i<6; i++)
        {
            int nx=now.x+go[i][0];
            int ny=now.y+go[i][1];
            int nz=now.z+go[i][2];//����������
            if(nx<0||nx>=a||ny<0||ny>=b||nz<0||nz>=c) continue;//������������������
            if(maze[nx][ny][nz]==1) continue;//����ǽ��
            if(mark[nx][ny][nz]==true) continue;//�Ѿ���ǹ���
            N tmp;
            tmp.x=nx;
            tmp.y=ny;
            tmp.z=nz;
            tmp.t=now.t+1;
            Q.push(tmp);//�µ����
            mark[nx][ny][nz]=true;//��������ϱ��
            if(nx==a-1&&ny==b-1&&nz==c-1)
                return tmp.t;//���ʱ���Ѿ����յ���
        }
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d",&n);//����
    while(n--)
    {
        int a,b,c,t;//a,b,c�ǳǱ��Ĵ�С��t�Ǵ�ħ��������ʱ��
        scanf("%d %d %d %d",&a,&b,&c,&t);
        for(int i=0; i<a; i++)
        {
            for(int j=0; j<b; j++)
            {
                for(int k=0; k<c; k++)
                {
                    scanf("%d",&maze[i][j][k]);//¼������
                    mark[i][j][k]=false;//��ʼ���������
                }
            }
        }

        while(!Q.empty()) Q.pop();//��ʼ������
        mark[0][0][0]=true;
        N tmp;
        tmp.x=tmp.y=tmp.z=tmp.t=0;//000��Ϊ���
        Q.push(tmp);
        int rec=BFS(a,b,c);
        if(rec<=t) printf("%d\n",rec);//ʱ���ڴ�ħ��������ʱ���ڼ���
        else printf("-1\n");
    }

    return 0;
}
