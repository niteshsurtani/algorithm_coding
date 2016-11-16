#include<stdio.h>
#include "linkedlist.c"

int compare(const void *a, const void *b){
	return (*(int *)a - *(int *)b);
}

int main(){
	int i,a[100],n,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	list *l;
	l=NULL;
	qsort(a,n,sizeof(int),compare);
	for(i=0;i<n;i++)
		l=insertEnd(l,a[i]);
	int num1, num2;
	while(l->next){
		l=deleteBegin(l, &num1);
		l=deleteBegin(l, &num2);
		int num=num1+num2;
		insertSort(l, num);
	}
	return 0;
}
