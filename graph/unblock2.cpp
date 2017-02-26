#include <stdio.h>
#include <algorithm>
#define N 101

using namespace std;

int Tree[N];
int findRoot(int x){
    if(Tree[x]==-1) return x;
    else{
        int tmp=findRoot(Tree[x]);
        Tree[x]=tmp;
        return tmp;
    }
}
void init(){
    for(int i=0;i<N;i++){
        Tree[i]=-1;
    }
}
struct edge{
    int a,b;
    int cost;
    bool operator < (const edge &A)const{
        return cost<A.cost;
    }
}edge[6000];

int main(){
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0){
        init();
        for(int i=1;i<=n*(n-1)/2;i++){
            scanf("%d %d %d",&edge[i].a,&edge[i].b,&edge[i].cost);
        }
        sort(edge+1,edge+1+n*(n-1)/2);
        int ans=0;
        for(int i=1;i<=n*(n-1)/2;i++){
            int a=findRoot(edge[i].a);
            int b=findRoot(edge[i].b);
            if(a!=b){
                Tree[a]=b;
                ans+=edge[i].cost;
            }
         }

        printf("%d\n",ans);
    }
    return 0;
}

