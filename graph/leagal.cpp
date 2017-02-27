#include <stdio.h>
#include <vector>
#include <queue>
#define N 501
using namespace std;

vector<int> edge[N];
queue<int> Q;

int main()
{
    int inDegree[N];
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(m==0&&n==0) break;
        for(int i=0;i<n;i++) {
                inDegree[i]=0;
                edge[i].clear();
        }//��ʼ��
        while(m--)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            inDegree[b]++;
            edge[a].push_back(b);
        }//¼����Ϣ

        while(!Q.empty()) Q.pop();//��ն���

        for(int i=0;i<n;i++){
            if(inDegree[i]==0)
                Q.push(i);//�����Ϊ0�����
        }
        int cnt=0;
        while(!Q.empty()){
            int nowP=Q.front();
            Q.pop();//�������Ϊ0 �Ľڵ�
            cnt++;
            for(int i=0;i<edge[nowP].size();i++){
                inDegree[edge[nowP][i]]--;//edge[nowP][i]����ȼ�һ

                if(inDegree[edge[nowP][i]]==0){
                    Q.push(edge[nowP][i]);
                }
            }
        }
        if(cnt==n) puts("YES");
        else puts("NO");
    }
    return 0;
}
