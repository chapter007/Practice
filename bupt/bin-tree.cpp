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

node *build(int x){
	node ret=create();
	ret.data=x;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		
	}
	return 0;
} 
