#include<stdio.h>
#include<malloc.h>
#include<limits.h>

typedef struct node{
	int num;
	struct node *next;
}list;

void print(list *l){
	while(l!=NULL){
		printf("%d -> ",l->num);
		l=l->next;
	}
	printf("\n");
}

void insert(list *l,int num){
	if(l->num==INT_MIN){ 
		l->num=num;
		return;
	}
	while(l->next!=NULL) l=l->next;
	list *l1;
	l1=(list *)malloc(sizeof(list));
	l1->next=NULL;
	l1->num=num;
	l->next=l1;
}

list* reverse(list *l){
	list *p,*c,*n;
	p=NULL;
	c=l;
	n=l->next;
	while(n!=NULL){
		c->next=p;
		p=c;
		c=n;
		n=n->next;
	}
	c->next=p;

	return c;
}

void join(list *t1,list *t2){
	while(t1->next!=NULL) t1=t1->next;
	t1->next=t2;
}

void arrange(list *l){
	list *T1,*T2,*t1,*t2,*temp;
	T1=t1=l;
	T2=t2=l->next;

	while(t2!=NULL && t2->next!=NULL){
		t1->next=t2->next;
		t1=t1->next;
		t2->next=t1->next;
		t2=t2->next;
	}
	t1->next=NULL;
	list* newT2=reverse(T2);
	join(T1,newT2);
}

int main(){
	list *l;
	l=(list *)malloc(sizeof(list));
	l->next=NULL; l->num=INT_MIN;
	int n,i,num;
	scanf("%d",&n);
	i=0;
	while(i<n){
		scanf("%d",&num);
		insert(l,num);
		i++;
	}
	arrange(l);
	print(l);
	
	return 0;
}
