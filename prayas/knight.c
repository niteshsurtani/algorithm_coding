#include<stdio.h>

void main(){
	int t,i,opp;
	long long int m,n;
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld",&n,&m);
		if(m<=n/2){
			printf("%lld\n",m+n/2);
		}
		else{
			printf("%lld\n",m-n/2);
		}
	}
}

