#include<stdio.h>

void rev(int a[], int x, int y){
	if(x==-1) return;
	rev(a, x-1, y+1);
	a[x]=a[y];
}

int sum(int a,int b){
	return a+b;
}

int sum(int a,int b, int c){
	 return sum(c,sum(a,b));
}

int main(){
	printf("%d\n",sum(1,2,3));
	return 0;
}
