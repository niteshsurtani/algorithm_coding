#include<stdio.h>
#include<malloc.h>

typedef struct node{
	int val;
	int index;
}pair;

int main(){
	int i,j,n;
	long long int this, max;
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		int a[n];
		pair *stack;

		stack=(pair *)malloc(sizeof(pair)*(n+1));

		this=0;
		max=0;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		pair s;
		s.val=-1;
		s.index=0;
		stack[0]=s;
	}

	return 0;
}
