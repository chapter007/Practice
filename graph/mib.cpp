#include <stdio.h>
#define N 10000001

int Tree[N];
int size[N];
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
        size[i]=1;
    }
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        init();
        for(int i=0;i<n;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            a=findRoot(a);
            b=findRoot(b);
            if(a!=b){
                Tree[a]=b;
                size[b]+=size[a];
            }
        }
        int ans=1;
        for(int i=1;i<=N;i++){
            if(Tree[i]==-1&&size[i]>ans) ans=size[i];//统计最大值
        }
        printf("%d\n",ans);
    }
    return 0;
}

