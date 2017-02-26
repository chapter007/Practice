#include <stdio.h>
#include <algorithm>
#include <math.h>
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
    double cost;
    bool operator < (const edge &A)const{
        return cost<A.cost;
    }
}edge[6000];

struct points{
    double x,y;
    double getDistance(points A){
        double tmp=(x-A.x)*(x-A.x)+(y-A.y)*(y-A.y);
        return sqrt(tmp);
    }
}list[101];

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        init();
        for(int i=1;i<=n;i++){
            scanf("%lf %lf",&list[i].x,&list[i].y);
        }
        int size=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                edge[size].a=i;
                edge[size].b=j;
                edge[size].cost=list[i].getDistance(list[j]);
                size++;
            }
        }
        sort(edge,edge+size);
        double ans=0;
        for(int i=0;i<size;i++){
            int a=findRoot(edge[i].a);
            int b=findRoot(edge[i].b);
            if(a!=b){
                Tree[a]=b;
                ans+=edge[i].cost;
                //printf("fuck%.2lf\n",ans);
            }
         }

        printf("%.2lf\n",ans);
    }
    return 0;
}

