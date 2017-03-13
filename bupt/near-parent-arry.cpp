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
			int x,y,ans=1,i=0,j=0;
			bool flag=false;
			scanf("%d %d",&x,&y);
			clean();
			int t=x;
			int r=y;
			while(Tree[x]!=0){
				Q1[i]=Tree[x];
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
					//printf("test Q1 Q2 %d %d\n",Q1[q],Q2[w]);
					if(Q1[q]==Q2[w]){
						ans=Q1[q];
						flag=true;
						break;
					}
					if(Q1[q]==r){
						//printf("test Q1 %d\n",r);
						ans=r;
						flag=true;
						break;
					}
					if(Q2[w]==t){
						//printf("test Q2 %d\n",t);
						ans=t;
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
