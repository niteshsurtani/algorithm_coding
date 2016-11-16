#include<stdio.h>

int max(int a, int b){
	if(a>b) return a;
	return b;
}

void main(){
	int i, n, j, sum[100], a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sum[0]=0;
	sum[1]=a[0];
	for(i=1;i<n;i++)
		sum[i+1]=max(sum[i],sum[i-1]+a[i]);
	printf("%d\n",sum[n]);
}
