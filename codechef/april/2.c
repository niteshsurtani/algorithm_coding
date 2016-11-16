#include<stdio.h>
#include<math.h>

void main(){
	int t,n,sr,i;
	long long int sum;
	scanf("%d",&t);
	while(t--){
		sum=0;
		scanf("%d",&n);
		sr=floor(sqrt(n));
		for(i=1;i<=sr;i++){
			if(n%i==0){
				sum+=i;
				if(i!=(n/i))
					sum+=(n/i);
			}
		}
		printf("%lld\n",sum);
	}
}

