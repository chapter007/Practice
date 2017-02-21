#include <stdio.h>
#include <string.h>

struct Node{
	Node *lchild;
	Node *rchild;
	int c;
}Tree[100];
int loc;
Node *creat(){
	Tree[loc].lchild=Tree[loc].rchild=NULL;
	return &Tree[loc++];
}

void preOrder(Node *T){
	printf("%d ",T->c);
	if(T->lchild!=NULL) preOrder(T->lchild);
	if(T->rchild!=NULL) preOrder(T->rchild);

}
void inOrder(Node *T){
	if(T->lchild!=NULL) inOrder(T->lchild);
	printf("%d ",T->c);
	if(T->rchild!=NULL) inOrder(T->rchild);
}
void postOrder(Node *T){
	if(T->lchild!=NULL) postOrder(T->lchild);
	if(T->rchild!=NULL) postOrder(T->rchild);
	printf("%d ",T->c);
}
Node *build(Node *T,int x){
	if(T==NULL){
		T=creat();
		T->c=x;
		return T;
	}else if(x<T->c){
		T->lchild=build(T->lchild,x);
	}else if(x>T->c){
		T->rchild=build(T->rchild,x);
	}
	return T;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		loc=0;
		Node *T=NULL;
		for(int i=0;i<n;i++){
			int m;
			scanf("%d",&m);
			T=build(T,m);
		}
		preOrder(T);
		printf("\n");
		inOrder(T);
		printf("\n");
		postOrder(T);
		printf("\n");
	}
	return 0;
}
