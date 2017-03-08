#include <stdio.h>

struct node{
	node *lchild;
	node *rchild;
	int data;
}Tree[50];

int loc=0;
node *create(){
	Tree[loc].lchild=Tree[loc].rchild=NULL;
	return &Tree[loc++];
}

node *build(node *t,int x,int y,bool root){
	if(t==NULL){
		t=create();
		if(root)
			t->data=x;
		else
			t->data=y;
	}else if(t->data==x&&t->lchild==NULL){
		t->lchild=build(t->lchild,x,y,false);
	}else if(t->data==x&&t->rchild==NULL){
		t->rchild=build(t->rchild,x,y,false);
	}
	return t;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		node *Tree=NULL;
		scanf("%d %d",&n,&m);
		while(n--){
			int a,b;
			scanf("%d %d",&a,&b);
			Tree=build(Tree,a,b,true);
		}//建立了一棵树
		printf("ok\n");
	}
	return 0;
} 
