#include <stdio.h>
#define N 101

struct Tree{
	Tree *lchild;
	Tree *rchild;
	int data;
}t[N];

void print(){
	for(int i=0;i<N;i++){
			if(t[i].data>0){
				printf("%d",t[i].data);
			}
	}
}

int main(){
	int T;
	scanf("%d",&T); 
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<N;i++){
			t[i].lchild=t[i].rchild=NULL;
			t[i].data=0;
		}//init
		t[1].data=1;
		for(int i=0;i<n-1;i++){
			int u,v;
			scanf("%d %d",&u,&v);
			t[u].data=u;
			t[v].data=v;
			if(t[u].lchild==NULL){
				t[u].lchild=&t[v];
			}else if(t[u].rchild==NULL){
				t[u].rchild=&t[v];
			}
		}//input
		int M;
		scanf("%d",&M);
		while(M--){
			int a,b,ans=1;
			scanf("%d %d",&a,&b);//find a b's parent
			for(int i=0;i<N;i++){
				if(t[i].data==a&&t[i].lchild){
					if(t[i].lchild->data==b){
						ans=a;
						break;
					}
				}
				if(t[i].data==b&&t[i].lchild){
					if(t[i].lchild->data==a){
						ans=b;
						break;
					}
				}
				if(t[i].lchild!=NULL&&t[i].rchild!=NULL){
					if(t[i].lchild->data==a&&t[i].rchild->data==b||
					t[i].lchild->data==b&&t[i].rchild->data==a){
						ans=t[i].data;
						break;
					}
				}
			}
			printf("%d\n",ans);
			
		}
	}
	return 0;
}
