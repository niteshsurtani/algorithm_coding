#include<stdio.h>

int main(){
	int i,j,m,n;
	scanf("%d%d",&m,&n);
	int m_even=m%2;
	int n_even=n%2;
	if(m_even==0 && n_even==0){
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				if(((i<=m/2 && i%2==0)||(i>m/2 && i%2==1)) && 	((j<=n/2 && j%2==0)||(j>n/2 && j%2==1))){
					printf("0 ");
				}
				else		
					printf("X ");
			}
			printf("\n");
		}	
	}
	return 0;
}
