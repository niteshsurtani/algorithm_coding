#include <iostream>

using namespace std;

typedef struct node{
	int num;
	struct node *next;
}list;


list* insertFront(list *l, int num){
	list *t = new list();
	t->num = num;
	t->next=l;
	return t;
}

list* insertEnd(list *l,int num){
	if(l==NULL){
		list *t = new list();
		t->num = num;
		t->next=NULL;
		return t;
	}
	l->next = insertEnd(l->next,num);
	return l;
}

list* insertElement(list *l,int num){
	if(l==NULL || l->num > num){
		list *t = new list();
		t->num = num;
		t->next=l;
		return t;
	}
	l->next = insertElement(l->next,num);
	return l;
}

void print(list *l){
	while(l!=NULL){
		cout << l->num << " -> ";
		l = l->next;
	}
	cout << endl;
}

list* deleteFront(list *l){
	if(l == NULL) return l;
	list *next = l->next;
	
	return next;
}

list* deleteBack(list *l){
	if(l == NULL) return NULL;
	if(l->next == NULL){
		delete(l);
		return NULL;
	}

	l->next = deleteBack(l->next);
	return l;
}

list* deleteElement(list *l, int num){
	if(l == NULL) return NULL;
	if(l->num == num){
		list *t = l->next;
		delete(l);
		return t;
	}

	l->next = deleteElement(l->next,num);
	return l;
}

list* reverseIter(list *l){
	list *prev, *curr, *next;
	prev = NULL; curr = l;
	while(curr != NULL){
		next = curr->next;
		curr->next = prev;

		prev = curr;
		curr = next;
	}
	return prev;
}

void reverseRec(list *l, list **c){
	if(l==NULL || l->next==NULL){
		*c = l;
		return;
	}
	reverseRec(l->next,c);
	l->next->next = l;
	l->next = NULL;
}

int main(){
	list *l;
	cout << "Sizeof List = " << sizeof(l) << endl;

	l = NULL;
	l = insertEnd(l,1);
	cout << "Sizeof Node = " << sizeof(*l) << endl;

	l = insertEnd(l,2);
	l = insertElement(l,3);
	print(l);

	list *c;
	// l=reverseIter(l);
	reverseRec(l,&c);
	// l = c;
	print(c);

	return 0;
}

