#include <stdio.h>
#include <queue>
#define N 101

using namespace std;

struct Tree{
	Tree *lchild;
	Tree *rchild;
	int data;
	int level;
}t[N];

struct rem{
	int level;
	int data;
}r[N];
queue<int> Q;

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
			t[i].level=0;
			r[i].data=0;
			r[i].level=0;
		}//init
		t[1].data=1;t[1].level=1;
		for(int i=0;i<n-1;i++){
			int u,v;
			scanf("%d %d",&u,&v);
			t[u].data=u;
			t[v].data=v;
			if(t[u].lchild==NULL){
				t[u].lchild=&t[v];
				t[v].level=t[u].level+1;
			}else if(t[u].rchild==NULL){
				t[u].rchild=&t[v];
				t[v].level=t[u].level+1;
			}
		}//input
		int M;
		scanf("%d",&M);
		while(M--){
			int a,b,ans=1,k=0;
			scanf("%d %d",&a,&b);//find a b's parent
			Q.push(1);
			while(!Q.empty()){
				int c=Q.front();
				Q.pop();
				if(t[c].lchild&&t[c].rchild){
					if(t[c].lchild->data==a&&t[c].rchild->data==b||
					t[c].lchild->data==b&&t[c].rchild->data==a){
						ans=t[c].data;
						break;
					}
				}
				if(t[c].data==a||t[c].data==b){
					r[k].level=t[c].level;
					r[k].data=t[c].data;
					k++;
				}
				if(t[c].lchild){
					int tmp=t[c].lchild->data;
					Q.push(tmp);
				}
				if(t[c].rchild){
					int tmp=t[c].rchild->data;
					Q.push(tmp);
				}	
			}
			printf("test-k %d\n",k);
			if(r[0].level>r[1].level) ans=r[1].data;
			else ans=r[0].data;
			/*for(int i=0;i<N;i++){
				//这个判断太繁杂了，难免会出错，很难把所有情况考虑到 
				if(t[i].data==a&&t[i].lchild){
					if(t[i].lchild->data==b){
						ans=a;
						break;
					}else{
						int tmp=t[i].lchild->data;
						while(t[tmp].data>0){
							if(t[tmp].data==b){
								ans=a;
								break;
							}else if(t[tmp].lchild){
								tmp=t[tmp].lchild->data;
							}else{
								break;
							}
						}
					}
				}
				if(t[i].data==b&&t[i].lchild){
					if(t[i].lchild->data==a){
						ans=b;
						break;
					}else{
						int tmp=t[i].lchild->data;
						while(t[tmp].data>0){
							if(t[tmp].data==a){
								ans=b;
								break;
							}else if(t[tmp].lchild){
								tmp=t[tmp].lchild->data;
							}else{
								break;
							}
						}
					}
				}
				if(t[i].lchild!=NULL&&t[i].rchild!=NULL){
					if(t[i].lchild->data==a&&t[i].rchild->data==b||
					t[i].lchild->data==b&&t[i].rchild->data==a){
						ans=t[i].data;
						break;
					}
				}*/
			 
			printf("%d\n",ans);
			
		}
	}
	return 0;
}
