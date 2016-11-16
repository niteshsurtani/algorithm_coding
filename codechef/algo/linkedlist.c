// Implements linked list functions with
// First node as first Data Node
// ========================
// This makes it difficult for all linked list functions except reverse.


#include<stdio.h>
#include<malloc.h>

typedef struct node{
	int num;
	struct node *next;
}list;

list* insertBegin(list *l,int num){
	list *m = (list *) malloc(sizeof(list));
	m->next = l;
	m->num=num;
	return m;
}

list* insertEnd(list *l,int num){
	if(l==NULL){
		list *m = (list *) malloc(sizeof(list));
		m->next = NULL;
		m->num=num;
		return m;
	}
	l->next=insertEnd(l->next,num);
	return l;
}

list* insertSort(list *l,int num){
	if(num<l->num) return insertBegin(l,num);
	while(l->next)
		if(l->next->num<num) l=l->next;

	list *m = (list *) malloc(sizeof(list));
	m->next = l->next;
	m->num=num;
	l->next=m;
}
/*
list* deleteBegin(list *l){
	if(l==NULL)return l;
	list *temp = l->next;
	free(l);
	return temp;
}
*/
list* deleteBegin(list *l, int *val){
	if(l==NULL)return l;
	*val=l->num;
	list *temp = l->next;
	free(l);
	return temp;
}
list* deleteEnd(list *l){
	if(l==NULL)return l;
	else if(l->next==NULL) return NULL;

	list* start=l;
	list* temp=l->next;
	while(temp->next!=NULL){
		l=temp;
		temp=temp->next;
	}
	l->next=temp->next;
	temp->next=NULL;
	free(temp);
	return start;
}

list* deleteAtK(list *l, int k){
	if(l==NULL)return l;
	if(k==1)
		return l->next;
	else{
		k-=2;
		list* start=l;
		list* temp=l->next;
		while(k--){
			l=temp;
			temp=temp->next;
		}
		l->next=temp->next;
		temp->next=NULL;
		free(temp);
		return start;
	}
}

void printList(list *l){
	while(l!=NULL){
		printf("%d -> ",l->num);
		l=l->next;
	}
	printf("\n");
}

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

void reverseRec(list* l, list **m){
	
	if(l->next==NULL){
		*m = l;
		return;
	}
	reverseRec(l->next, m);
	l->next->next = l;
	l->next=NULL;
}


list* reverseBlockLoop(list *l,int k){
	list *next, *prev;
        prev = NULL;
	
	while(l!=NULL && k>0){
		next = l->next;
		l->next = prev;
		prev = l;
		l = next;
		k--;
	}
	l = prev;
	return l;
}

int main(){
	list *l = (list *) malloc(sizeof(list));
	l=NULL;	
	l=insertEnd(l,1);	
	l=insertEnd(l,2);	
	l=insertEnd(l,3);	
	l=insertEnd(l,4);	
	l=insertEnd(l,5);	
	l=insertEnd(l,6);	
	l=insertEnd(l,7);	
	l=insertEnd(l,8);	
	l=insertEnd(l,9);	
	l=insertEnd(l,10);	
	l=insertEnd(l,11);	
	printList(l);


	int n = 11;
	int k = 3;

	list *head,*thisBlock,*nextBlock,*s,*e,*pe,*ps;

	int start = 1,count=0;
	int finish = 0;
	while(!finish){
		thisBlock = l;
		nextBlock = l;
		count = 0;
		while(nextBlock!=NULL && count<k){
			nextBlock=nextBlock->next;
			count++;
		}
		if(nextBlock == NULL)
			finish = 1;
		else{
			printf("%d %d --> \n",thisBlock->num,nextBlock->num);
		}
		e = l;
		s = reverseBlockLoop(l,k);
		if(start){
			e->next = NULL;
			head = s;
			start = 0;
		}
		else{
			pe->next = s;
		}
		ps = s;
		pe = e;
		l = nextBlock;
	}
	printList(head);
	return 0;
}
