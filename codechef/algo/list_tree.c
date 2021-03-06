// Implements linked list functions with
// First node as Empty Node
// ========================
// This makes it easy for all linked list functions except reverse in which a extra node needs to be added.

#include<stdio.h>
#include<malloc.h>

typedef struct node{
	int num;
	struct node *left,*right;
}tree;

typedef struct node{
	tree* treeptr;
	struct node *next;
}list;

void insertBegin(list *l,tree *t){
	list *m = (list *) malloc(sizeof(list));
	m->next = l->next;
	m->treeptr=t;
	l->next=m;
}

void insertEnd(list *l,tree *t){
	while(l->next) l=l->next;
	list *m = (list *) malloc(sizeof(list));
	m->next = l->next;
	m->treeptr=t;
	l->next=m;

}

void insertSort(list *l,tree *t){
	while(l->next){
		if(l->next->num<num) l=l->next;
		else break;
	}
	list *m = (list *) malloc(sizeof(list));
	m->next = l->next;
	m->treeptr=t;
	l->next=m;
}

tree* deleteBegin(list *l){
	if(l->next!=NULL){
		list *t=l->next;
		l->next=t->next;
		tree *c=t->treeptr;
		free(t);
		return c;
	}
	
	printf("EMPTY LIST\n");
	return NULL;
}

tree* deleteEnd(list *l){
	if(l->next==NULL){
	       	printf("EMPTY LIST\n");
		return;
	}
	
	list *prev=NULL;

	while(l->next!=NULL){
		prev=l;
		l=l->next;
	}

	prev->next=NULL;
	
	tree *c=l->treeptr;
	free(l);
	return c;
}

void printList(list *l){
	while(l->next!=NULL){
		l=l->next;
		printf("%d -> ",l->num);
	}
	printf("\n");
}

int main(){
	list *l = (list *) malloc(sizeof(list));
	l->next=NULL;	

	insertEnd(l,1);	
	insertEnd(l,3);	
	insertEnd(l,4);	
	insertEnd(l,5);	
	printList(l);

	insertSort(l,2);
	printList(l);
	return 0;
}
