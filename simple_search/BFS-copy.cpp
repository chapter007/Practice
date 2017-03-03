#include <stdio.h>
#include <queue>
using namespace std;
bool mark[50][50][50]; //�������
int maze[50][50][50]; //������������Ϣ
struct N   //״̬�ṹ��
{
    int x, y, z;
    int t;
};
queue<N> Q; //����,�����е�Ԫ��Ϊ״̬
int go[][3] =
{
    1,0,0,
    -1,0,0,
    0,1,0,
    0,-1,0,
    0,0,1,
    0,0,-1
};
int BFS(int a,int b,int c)   //�����������,���������ٺ�ʱ
{
    while(Q.empty() == false)   //������������Ԫ�ؿ�����չʱѭ��
    {
        N now = Q.front(); //�õ���ͷ״̬
        Q.pop(); //�Ӷ����е�����ͷ״̬
        for (int i = 0; i < 6; i ++) //������չ���������ڽڵ�
        {
            int nx = now.x + go[i][0];
            int ny = now.y + go[i][1];
            int nz = now.z + go[i][2]; //����������
            if (nx < 0 || nx >= a || ny < 0 || ny >= b || nz < 0 || nz >= c)
                continue; //������������������,����������
            if (maze[nx][ny][nz] == 1) continue; //����λ��Ϊǽ,����������
            if (mark[nx][ny][nz] == true) continue; //�������������״̬�Ѿ���
            N tmp; //�µ�״̬
            tmp.x = nx;
            tmp.y = ny;
            tmp.z = nz; //��״̬����������
            tmp.t = now.t + 1; //��״̬�ĺ�ʱ
            Q.push(tmp); //����״̬�������
            mark[nx][ny][nz] = true; //��Ǹ�����
            if (nx == a - 1 && ny == b - 1 && nz == c - 1) return tmp.t;
        }
    }
    return -1; //�����е�״̬���������,�Եò�����������,�򷵻�-1
}
int main ()
{
    int T;
    scanf ("%d",&T);
    while (T --)
    {
        int a, b, c, t;
        scanf ("%d%d%d%d",&a,&b,&c,&t); //����
        for (int i = 0; i < a; i ++)
        {
            for (int j = 0; j < b; j ++)
            {
                for (int k = 0; k < c; k ++)
                {
                    scanf ("%d",&maze[i][j][k]); //������������Ϣ
                    mark[i][j][k] = false; //��ʼ���������
                }
            }
        }
        while(Q.empty() == false) Q.pop(); //��ն���
        mark[0][0][0] = true; //������
        N tmp;
        tmp.t = tmp.y = tmp.x = tmp.z = 0; //��ʼ״̬
        Q.push(tmp); //����ʼ״̬�������
        int rec = BFS(a,b,c); //�����������
        if (rec <= t) printf("%d\n",rec); //������ʱ���������,�����
        else printf("-1\n"); //�������-1
    }
    return 0;
}