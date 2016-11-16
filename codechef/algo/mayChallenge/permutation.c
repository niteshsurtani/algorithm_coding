#include<stdio.h>
#include<malloc.h>

void perm(int *a, int *b, int i, int j, int n,int q){
	if(j==q){
		int m;
		for(m=0;m<q;m++){
			printf("%d ",b[m]);
		}
		printf("\n");
	}
	int k;
	for(k=i;k<n;k++){
		b[j]=a[k];
		perm(a,b,k+1,j+1,n,q);
	}
}
	
int main(){
	int i;
	int n;
	int *a;
	scanf("%d",&n);

	int j;
	a=(int *)malloc (sizeof(int)*n);
	for(j=0;j<n;j++){
		scanf("%d",&a[j]);
	}

	int *b;
	b=(int *)malloc(sizeof(int)*2);
	perm(a,b,0,0,n,2);
	return 0;
}
