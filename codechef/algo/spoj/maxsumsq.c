#include<stdio.h>

int main(){
	long long int this,max;
	int t,n,i,a[100000],count;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		this=0;
		max=-100000000;
		count=0;
		int fl=0;
		for(i=0;i<n;i++){
			this+=a[i];
			if(this>max){
				fl=0;
				count=1;
				max=this;
			}
			else if(this==max){
				count++;
				count+=fl;
			}
			if(this<0){
				this=0;
				fl=0;
			}
			else if(this==0)
				fl+=1;
		}
		printf("%lld %d\n",max,count);


	}
	return 0;
}
