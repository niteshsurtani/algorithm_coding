#include<stdio.h>

void rev(int a[], int x, int y){
	if(x==-1) return;
	rev(a, x-1, y+1);
	a[x]=a[y];
}

int main(){
	int a[5]={1,2,3,4,5};
	rev(a,4,0);
	int i;
	for(i=0;i<5;i++)
		printf("%d\n",a[i]);
	return 0;
}
