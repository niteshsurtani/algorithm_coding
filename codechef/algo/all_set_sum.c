#include<stdio.h>
#include<malloc.h>
#include<math.h>
			
int mod=1000000007;

int **factor;
int prime[10000];
int nmr[10000],dmr[10000];
int prime_count;


int comb(int n, int k){
	int i,j;
	for(i=0;i<prime_count;i++){
		nmr[i]+=factor[n-k][i];
		dmr[i]+=factor[k-1][i];
		nmr[i]-=dmr[i];
		dmr[i]=0;	
	}
	long long int mul=1;
	for(i=0;i<prime_count;i++){
		for(j=0;j<nmr[i];j++){
			mul*=prime[i];
		}
		mul%=mod;
	}
	return mul;	
}

int main(){
	int i,j,n,t;
	int *a;

	// Find prime
	n=10000;
	int fl,s,c=0;
	for(i=2;i<=n;i++){
		s=sqrt(i);
		fl=0;
		for(j=2;j<=s;j++){
			if(i%j==0){
			       	fl=1;
				break;
			}
		}
		if(fl==0) prime[c++]=i;
	}

	prime_count=c;
	
	factor=(int **)malloc(sizeof(int *)*10000);
	for(i=0;i<10000;i++)
		factor[i]=(int *)malloc(sizeof(int)*prime_count);

	for(i=0;i<n;i++){
		for(j=0;j<prime_count;j++){
			factor[i][j]=0;
		}
	}

	int num;
	for(i=2;i<=n;i++){
		num=i;
		for(j=0;j<c;j++){
			while(num!=1 && num%prime[j]==0){
				
				num/=prime[j];
				factor[i-1][j]++;
			}
			if(i==1) break;
		}
	}


	long long int sum;
	long long int mul;
	long long int prod;
	a=(int *) malloc(10000*sizeof(int));
	scanf("%d",&t);
	while(t--){
		sum=0;
		for(i=0;i<prime_count;i++){
			nmr[i]=0;
			dmr[i]=0;
		}

		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}

		sum%=mod;

		if(n==1) printf("%lld\n",sum);
		else{
			prod=2;
			for(i=1;i<=(n-1)/2;i++){
				mul=comb(n-1,i);
				if(n%2==1 && i==(n-1)/2)
					prod+=mul;
				else
					prod+=(2*mul);
				prod%=mod;
			}
			prod*=sum;
			prod%=mod;
			printf("%lld\n",prod);
		}
	}
			

	return 0;
}
