#include <stdio.h>
#include <queue>

using namespace std;

struct node{
	node *lchild;
	node *rchild;
	int data;
	int depth;
	int visit;
}Tree[101];

int loc=0;
queue<node *> Q;

int main(){
	int t,k=1,i,j,flag;
	int c[101];
	scanf("%d",&t);
	while(t--){
		int n,m,x,y;
		scanf("%d %d",&n,&m);
		for(int i=0;i<101;i++){
			Tree[i].lchild=Tree[i].rchild=NULL;
			Tree[i].depth=0;
			Tree[i].visit=0;
		}
		Tree[1].depth=1;
		for(int i=0;i<n;i++){
			scanf("%d %d",&x,&y);
			Tree[x].data=x;
			Tree[y].data=y;
			if(Tree[y].lchild==NULL) Tree[y].lchild=&Tree[x];
			else Tree[y].rchild=&Tree[x];
			Tree[x].depth=Tree[y].depth+1;
		}//input
		printf("Q%d:\n",k);
		//print_pre(Tree);this tree is different
		int c=1,l=1;
		while(c<102){
			if(Tree[c].data>0){
				if(Tree[c].depth==l){
					printf("%d",Tree[c].data);
				}
				printf("\n");	
			}
			c++;
			l++;
		}
		k++;
		printf("\n");
		/*i=j=c[1]=1; flag=1;  
        while(i<=j){  
            if(Tree[c[i]].lchild!=NULL) c[++j]=(*Tree[c[i]].lchild).data;  
            if(Tree[c[i]].rchild!=NULL) c[++j]=(*Tree[c[i]].rchild).data;  
            if(i>1) putchar(Tree[c[i]].depth!=flag?'\n':' ');  
            printf("%d",Tree[c[i]].data);  
            flag=Tree[c[i]].depth;  
            i++;  
        }
        k++;
        puts("");*/  
	}
	return 0;
} 
