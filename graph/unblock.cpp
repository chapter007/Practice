#include <stdio.h>

int Tree[1000];
int findRoot(int x){
    if(Tree[x]==-1) return x;
    else{
        int tmp=findRoot(Tree[x]);
        Tree[x]=tmp;
        return tmp;
    }
}
void init(){
    for(int i=0;i<1000;i++){
        Tree[i]=-1;
    }
}

int main(){
    int n,m;
    while(scanf("%d",&n)!=EOF&&n!=0){
        scanf("%d",&m);
        init();
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            a=findRoot(a);
            b=findRoot(b);
            if(a!=b){
                Tree[a]=b;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(Tree[i]==-1) ans++;
        }
        printf("%d\n",ans-1);
    }
    return 0;
}
