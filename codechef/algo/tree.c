#include<stdio.h>
#include<malloc.h>

typedef struct node{
	int num;
	struct node *left,*right;
}tree;

typedef struct n{
	tree *treeptr;
	struct n *next;
}list;

tree* insert(tree *t, int num){
	if(t==NULL){
		tree *temp;
		temp=(tree *)malloc(sizeof(tree));
		temp->num=num;
		temp->left=temp->right=NULL;
		return temp;
	}
	if(num<t->num)
		t->left=insert(t->left,num);
	else
		t->right=insert(t->right,num);
	return t;
}

void preorder(tree *t){
	if(t==NULL)return;
	printf("%d -> ",t->num);
	preorder(t->left);
	preorder(t->right);
}

void inorder(tree *t){
	if(t==NULL)return;
	inorder(t->left);
	printf("%d -> ",t->num);
	inorder(t->right);
}

void postorder(tree *t){
	if(t==NULL)return;
	postorder(t->left);
	postorder(t->right);
	printf("%d -> ",t->num);
}

list* insertEnd(list *l,tree *t){
	if(l==NULL){
		list *m = (list *) malloc(sizeof(list));
		m->next = NULL;
		m->treeptr=t;
		return m;
	}
	l->next=insertEnd(l->next,t);
	return l;
}

list* deleteBegin(list *l, list **m){
	if(l==NULL){ 
		*m=NULL;  
		return l;
	}
	*m=l;
        l = l->next;
//	(*m)->next=NULL;
	return l;
}

list* enquque(list *l, tree *t){
	l=insertEnd(l,t);
	return l;
}

list* dequque(list *l, tree **t){
	list *m;
	l=deleteBegin(l,&m);
	if(m!=NULL){
		*t=m->treeptr;
	}
	else
		*t=NULL;
	return l;
}

void levelorder(tree *t){
	list *l;
	l = (list *) malloc(sizeof(list));
	l=NULL;
	l=enquque(l,t);
	while(1){
		tree *temp;
		l=dequque(l,&temp);
		t=temp;
		if(temp==NULL) break;
		else{
			printf("%d -> ",temp->num);
			if(t->left!=NULL) l=enquque(l,t->left);
			if(t->right!=NULL) l=enquque(l,t->right);
		}
	}
	printf("\n");
}

void print(tree *t){
	printf("PREORDER : ");
	preorder(t);
	printf("\n");
	
	printf("INORDER : ");
	inorder(t);
	printf("\n");
	
	printf("POSTORDER : ");
	postorder(t);
	printf("\n");
}

int main(){
	tree *t;
	t=(tree *)malloc(sizeof(tree));
	t=NULL;

	t=insert(t,8);
	t=insert(t,4);
	t=insert(t,12);
	t=insert(t,2);
	t=insert(t,1);
	t=insert(t,3);
	t=insert(t,6);
	t=insert(t,11);
	t=insert(t,9);
	print(t);
	printf("LEVELORDER : ");
	levelorder(t);
	return 0;
}
