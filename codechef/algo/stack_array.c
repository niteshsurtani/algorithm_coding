#include<stdio.h>
#include<malloc.h>

#define SIZE 100 

typedef struct node{
	int a[SIZE];
	int top;
}stack;

void push(stack *s, int num){
	if(!isFull(s))
		s->a[s->top++]=num;
	else
		printf("Stack is full\n");
}

int pop(stack *s){
	if(!isEmpty(s))
		return s->a[--s->top];
	else
		printf("Stack is empty\n");
}

int isEmpty(stack *s){
	if(s->top==0)
		return 1;
	return 0;
}

int isFull(stack *s){
	if(s->top==SIZE)
		return 1;
	return 0;
}

int main(){
	stack s;
	s.top=0;

	push(&s,1);
	push(&s,2);	
	push(&s,3);	
	push(&s,4);	
	printf("%d\n",pop(&s));
	return 0;
}

