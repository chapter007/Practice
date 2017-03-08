#include <stdio.h>

struct tree{
	tree *lchild;
	tree *rchild;
	int data;
}t[101];
int loc;

tree *create(){
	t[loc].lchild=t[loc].rchild=NULL;
	return &t[loc++];
}

tree *insert(tree *t,int x,int parent){
	if(t==NULL){
		t=create();
		t->data=x;
		printf("%d\n",parent);
	}else if(t->lchild==NULL&&x<t->data){
		t->lchild=insert(t->lchild,x,t->data);
	}else if(t->rchild==NULL&&x>t->data){
		t->rchild=insert(t->rchild,x,t->data);
	}else if(t->lchild!=NULL&&x<t->data){
		insert(t->lchild,x,t->data);
		//t->lchild=insert(t->lchild,x,t->data);
	}else if(t->rchild!=NULL&&x>t->data){
		insert(t->rchild,x,t->data);
		//t->rchild=insert(t->rchild,x,t->data);
	}
	return t;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		tree *Tree=NULL;
		for(int i=0;i<n;i++){
			int x;
			scanf("%d",&x);
			Tree=insert(Tree,x,-1);
		}
	}
	return 0;
}
