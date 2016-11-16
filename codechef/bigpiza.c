#include<stdio.h>

void main(){
	int res[10001]={0};
	res[0]=res[1]=0;
	res[2]=1;
	int i,j,k,n,t,sum;
	for(i=3;i<=10000;i++){
		j=i-2;
		for(k=0;k<=j/2;k++){
			sum=0;
			if(k<j/2){
				sum=res[k]+res[j-k];
			}
			else{
				if(j%2==1){
					sum=res[k]+res[k+1];
				}
				else{
					sum=2*res[k];
				}
			}
			if(sum%2==0){
				res[i]=1;
				break;
			}
		}
	}
	for(i=0;i<10001;i++){
		printf("i=%d then %d\n",i,res[i]);
	}	
}
