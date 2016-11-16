#include<stdio.h>

int main(){
	int m,n,i,j,odd;
	scanf("%d%d",&m,&n);

	odd=n%2;
	for(i=0;i<m/2+odd;i++){
		for(j=0;j<n;j++){
			if(j<i){
				if(j%2==0) printf("X");
				else printf("O");
			}
			else if(j<m-i){
				if(i%2==0) printf("X"); 
				else printf("O");
			}
			else{
				if(j%2==0) printf("X");
				else printf("O");
			}
		}
		printf("\n");
	}

	for(i=m/2-1;i>=0;i--){
		for(j=0;j<n;j++){
			if(j<i){
				if(j%2==0) printf("X");
				else printf("O");
			}
			else if(j<m-i){
				if(i%2==0) printf("X"); 
				else printf("O");
			}
			else{
				if(j%2==0) printf("X");
				else printf("O");
			}
		}
		printf("\n");
	}
	return 0;
}
