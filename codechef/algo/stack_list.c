#include<stdio.h>
#include<malloc.h>
#define null NULL

typedef struct node{
	int num;
	struct node *next;
}list;

void push(list *l, int num){
	list *t;
	t=(list*)malloc(sizeof(list));
	t->num=num;
	t->next=l->next;
	l->next=t;
}

int pop(list *l){
	if(l->next != null){
		list *temp=l->next;
		l->next=temp->next;
		temp->next=null;
		return temp->num;
	}
	return -1;
}

int main(){
	list *l;
	l=(list*)malloc(sizeof(list));
	l->next=null;
	
	push(l,1);
	push(l,2);
	push(l,3);
	push(l,4);
	printf("%d\n",pop(l));
	printf("%d\n",pop(l));
	printf("%d\n",pop(l));
	printf("%d\n",pop(l));
	printf("%d\n",pop(l));
	return 0;
}
