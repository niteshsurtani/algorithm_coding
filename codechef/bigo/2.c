#include<stdio.h>
#include<math.h>
#define modulo 1000000007

void main(){
	int i,j,t,n;
	double num,a[1000000];
	scanf("%d",&t);
	for(i=1;i<=1000000;i++){
		a[i-1]=log10(i);
	}
	while(t--){
		num=0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			num+=a[i];
		}
		printf("%.0lf\n",ceil(num));
	}
}

