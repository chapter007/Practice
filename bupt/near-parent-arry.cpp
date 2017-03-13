#include <stdio.h>
#include <string.h>
#define N 101

using namespace std;

int Tree[N];
int Q1[N],Q2[N];

void clean(){
	memset(Q1,0,sizeof(Q1));
	memset(Q2,0,sizeof(Q2));
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		memset(Tree,0,sizeof(Tree));
		scanf("%d",&n);
		Tree[1]=0;
		for(int i=0;i<n-1;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			Tree[b]=a;
		}
		int m;
		scanf("%d",&m);
		while(m--){
			int x,y,ans=1,i=1,j=1;
			bool flag=false;
			scanf("%d %d",&x,&y);
			clean();
			Q1[0]=x;Q2[0]=y;
			while(Tree[x]!=0){
				Q1[i]=Tree[x];//Q1 Q2中保存着x,y的父节点序列 
				x=Tree[x];
				i++;
			}
			while(Tree[y]!=0){
				Q2[j]=Tree[y];
				j++;
				y=Tree[y];
			}
			
			for(int q=0;q<i;q++){
				for(int w=0;w<j;w++){
					//printf("test x %d y %d Q1 Q2 %d %d\n",t,r,Q1[q],Q2[w]);//输出测试一下 
					if(Q1[q]==Q2[w]){
						ans=Q1[q];
						flag=true;
						break;
					}
				}
				if(flag) break;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
