#include<stdio.h>
#include<malloc.h>

typedef struct node{
	int num;
	struct node *next;
}list;

/*
void insertBegin(list *l,int num){
	list *m = (list *) malloc(sizeof(list));
	m->next = l->next;
	m->num=num;
	l->next = m;
}
*/

void insertEnd(list *l,int num){
	list *m = (list *) malloc(sizeof(list));
	m->next = NULL;
	m->num=num;
	while(l->next!=NULL){
		l=l->next;
	}
	l->next=m;
}

/*
void deleteBegin(list *l){
	list *temp = l->next;
	l->next = temp->next;
	temp->next = NULL;
}

void printList(list *l){
	while(l->next!=NULL){
		l=l->next;
		printf("%d -> ",l->num);
	}
	printf("\n");
}
*/

void printList(list *l){
	while(l!=NULL){
		printf("%d -> ",l->num);
		l=l->next;
	}
	printf("\n");
}

void alternate(list *l, list *m){
	list *prev;
        prev = NULL;

	while(l!=NULL && m!=NULL){
		l->next = m->next;
		int fwd = 0;
		if(l->next !=NULL){
			l=l->next;
			fwd=1;
		}
		m->next=prev;
		prev=m;

		if(fwd==1 && l->next!=NULL)
			m=l->next;
		else
			break;
	}
	l->next = m;
}
/*
list* reverseLoop(list *l){
	list *next, *prev;
        prev = NULL;
	
	while(l!=NULL){
		next = l->next;
		l->next = prev;
		prev = l;
		l = next;
	}
	l = prev;
	return l;
}

void reverseRec(list* l, list *m){
	
	if(l->next==NULL){
		m->next = l;
		return;
	}
	reverseRec(l->next, m);
//	printf("NUM = %d %d\n",l->num,l->next->num);
	l->next->next = l;
	return;
}
*/

int main(){
	list *l = (list *) malloc(sizeof(list));
	l->num=1;	
	l->next=NULL;	
	insertEnd(l,2);	
	printList(l);
	insertEnd(l,3);	
	printList(l);
	insertEnd(l,4);	
	printList(l);
	insertEnd(l,5);	
	printList(l);
	insertEnd(l,6);	
	printList(l);

	list *m=l->next;
	alternate(l,m);
	printList(l);
	return 0;
}
