#include<stdio.h>

void comb(int a[5], int b[3],int i, int j, int n, int len){
	if(j==n){
		int l;
		for(l=0;l<n;l++)
			printf("%d ",b[l]);
		printf("\n");
	}
	int k;
	for(k=i;k<len;k++){
		b[j]=a[k];
		comb(a,b,k+1,j+1,n,len);
	}
}

int main(){
	int a[]={1,2,3,4,5};
	int b[3];
	comb(a,b,0,0,3,5);
	return 0;
}
