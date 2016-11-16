#include<stdio.h>
#define modulo 1000000007

void main(){
	int i,j,t,n;
	long long int a[100];
	long long int mul;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		i=0;
		mul=1;
		while(i<n){
			scanf("%lld",&a[i]);
			a[i]%=modulo;
			i++;
		}
		for(i=0;i<n;i++){
			mul*=a[i];
			mul%=modulo;
		}
		printf("%lld\n",mul);
	}
}

