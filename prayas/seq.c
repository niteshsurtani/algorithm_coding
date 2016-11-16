#include<stdio.h>

int minimum(int x, int y){
	if(x<y) return 1;
	return 2;
}

void main(){
	int t,n,i,rep;
	long long int sum;
	scanf("%d",&t);
	while(t--){
		sum=0;
		scanf("%d",&n);
		int a[n],min[n];
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			min[i]=i;
			sum+=a[i];
		}
		
		rep=1;
		int k;
		while(rep<n){
			for(i=0;i<n-rep;i++){
				k=minimum(a[min[i]],a[min[i+1]]);
				if(k==2){
					min[i]=min[i+1];
				}
				sum+=a[min[i]];
			}
			rep++;
		}
		printf("%lld\n",sum);
	}
}

