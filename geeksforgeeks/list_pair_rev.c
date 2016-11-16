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
list* reverse_pair(list *l){
	if(l==NULL || l->next==NULL) return l;

	list *p,*c,*n;
	list *x1,*x2,*ptr;
	
	x1=l->next;
	ptr=l;
	x2=x1->next;
	x1->next=ptr;
	ptr->next=NULL;

	while(x2!=NULL){
		c=x2;
		p=NULL;
		n=c->next;
		if(n==NULL){
		       	ptr->next=c;
			break;
		}
		
		x2=n->next;
		
		c->next=p;
		n->next=c;
		ptr->next=n;
		ptr=c;

	}
	return x1;
}

list* reverse_k(list *l, int k){
	if(l==NULL || l->next==NULL) return l;

	list *p,*c,*n;
	list *x1,*x2,*ptr;

	c=l;	
	p=NULL;
	n=c->next;

	ptr=l;

	int i=0;
	while(i<k){
		if(n==NULL){
			c->next=p;
		       	return c;
		}
		c->next=p;
		p=c;
		c=n;
		n=c->next;
		i++;
	}
	x2=c;
	x1=p;

	int flag=0;
	while(x2!=NULL){
		i=0;
		flag=0;
		c=x2;	
		p=NULL;
		n=c->next;
		if(n==NULL){
			c->next=p;
		       	ptr->next=c;
			break;
		}


		while(i<k){
			if(n==NULL){
			        c->next=p;
		       		ptr->next=c;
			 	flag=1;
				break;
			}
			c->next=p;
			p=c;
			c=n;
			n=c->next;
		
			i++;
		}
		if(flag==1) break;
		ptr->next=p;
		ptr=x2;
		x2=c;
	}
	return x1;
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
	print(l);
//	l=reverse_pair(l);	
	l=reverse_k(l,3);	
	print(l);
	return 0;
}
