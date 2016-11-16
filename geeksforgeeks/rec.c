#include<stdio.h>

int rec(int n){
	if(n==1){
		int sum=0;
		return n;
	}
	int c=rec(n-1);
	sum+=c;
	printf("%d\n",sum);
	return n;
}

void main(){
	rec(5);
}
