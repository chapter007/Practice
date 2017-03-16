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
void clean(){
	while(!Q.empty()) Q.pop();
} 

int min(int a,int b){
	return a>b b:a;
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
			clean();
			scanf("%d %d",&a,&b);//find a b's parent
			if(t[a].level==t[b].level){//a,bÍ¬²ã 
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
					if(t[c].lchild){
						int tmp=t[c].lchild->data;
						Q.push(tmp);
					}
					if(t[c].rchild){
						int tmp=t[c].rchild->data;
						Q.push(tmp);
					}
				}
			}else{//²»Í¬²ã 
				if(t[a].level>t[b].level){
					Q.push(t[b].data);
				}else{
					Q.push(t[a].data);
				}
				while(!Q.empty()){
					int c=Q.front();
					Q.pop();
					if(t[c].lchild){
						if(t[c].lchild->data==a||t[c].lchild->data==b){
							if(t[a].level>t[b].level){
								ans=b;
							}else{
								ans=a;
							}
							break;
						}
						int tmp=t[c].lchild->data;
						Q.push(tmp);
					}
					if(t[c].rchild){
						if(t[c].rchild->data==a||t[c].rchild->data==b){
							if(t[a].level>t[b].level){
								ans=b;
							}else{
								ans=a;
							}
							break;
						}
						int tmp=t[c].rchild->data;
						Q.push(tmp);
					}
				}
			}
			printf("%d\n",ans);
			
		}
	}
	return 0;
}
