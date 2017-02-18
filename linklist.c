#include <stdio.h>
#include <stdlib.h>

//build a simple linklist
typedef struct Lnode{
	int data;
	struct Lnode *next;

}Lnode, *Linklist;

void createLinklist(Linklist L);
void showLinklist(Linklist L);
void deleteMin(Linklist L);
void deleteX(Linklist L,int x);

int main(){
	Linklist L=(Linklist)malloc(sizeof(Lnode)); //create Lnode as header
	createLinklist(L);
	showLinklist(L);
	printf("\n");
	//deleteMin(L);
	deleteX(L,2);
	printf("\n");
	showLinklist(L);
	return 0;
}

void createLinklist(Linklist L){
	L->next=NULL;
	Lnode *s,*r=L;
	int i=0;
	scanf("%d",&i);
	while(i!=233){
		s=(Lnode *)malloc(sizeof(Lnode));
		s->data=i;
		//s->next=L->next; //head insert
		//L->next=s;
		s->next=NULL;
		r->next=s; //tail insert
		r=s;
		scanf("%d",&i);
	}
}

void showLinklist(Linklist L){
	Lnode *head=L->next;
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
}

void deleteMin(Linklist L){
	Lnode *pre,*q;
	//Lnode *head=L->next;
	int min=L->next->data;
	while(L->next){
		if(L->next->data<=min){
			pre=L;
			q=L->next;
			min=L->next->data;
		}
		L=L->next;
	}
	printf("min is %d\n",min);
	pre->next=q->next;
	free(q);
}

void deleteX(Linklist L,int x){
	Lnode *pre,*q;
	while(L->next){
		if(L->next->data==x){
			pre=L;
			q=L->next;
			pre->next=q->next;
			free(q);
		}
		L=L->next;
	}
}
