#include<stdio.h>
#include<malloc.h>

int perm(int *a, int *b, int sum, int i, int j, int q, int n){
	if(j==q){
		int m;
		if(sum%n==0){
			printf("%d\n",q);
			for(m=0;m<q;m++){
				if(m<q-1)
					printf("%d ",b[m]+1);
				else
					printf("%d\n",b[m]+1);
			}
			return 1;
		}
		return 0;
	}
	int k;
	for(k=i;k<n;k++){
		b[j]=k;
		int c = perm(a,b,sum+a[k],k+1,j+1,q,n);
		if(c==1)return 1;
	}
	return 0;
}
	
int main(){
	int t;
	int i;

	scanf("%d",&t);
	for(i=0;i<t;i++){
		int n;
		int *a;
		scanf("%d",&n);

		int j;
		a=(int *)malloc (sizeof(int)*n);
		for(j=0;j<n;j++){
			scanf("%d",&a[j]);
		}

		int *b;
		for(j=1;j<=n;j++){
			b=(int *)malloc(sizeof(int)*j);
			int c=perm(a,b,0,0,0,j,n);
			if(c==1) break;
		}
	}
}
