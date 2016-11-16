#include<stdio.h>
#include<malloc.h>

int main(){
	int t;
	int i;

	scanf("%d",&t);
	for(i=0;i<t;i++){
		int n, k;
		int *a;
		scanf("%d %d",&n,&k);

		int j;
		a=(int *)malloc (sizeof(int)*n);
		for(j=0;j<n;j++){
			scanf("%d",&a[j]);
		}
		int count = 0;
		int diff = 2147483647;
		int p,q;
		int sum;
		for(p=0;p<n;p++){
			for(q=p+1;q<n;q++){
				sum=a[p]+a[q]-k;
				if(sum<0) sum*=-1;
				if(sum<diff){
				       diff=sum;
			       	       count=1;
				}
				else if(sum==diff) count++;
			}
		}
		printf("%d %d\n",diff, count);
	}
	return 0;
}
