#include<stdio.h>

void main(){
	int t,n;
	int sum,this,prev,diff_prev,diff_this,num;
	scanf("%d",&t);
	while(t--){
		sum=0;
		scanf("%d",&n);
		n--;
		num=0;
		scanf("%d",&prev);
		while(n--){
			scanf("%d",&this);
			if(prev!=this){
				num=1;
				sum++;
			}
			else{
				if(num==1){
				       num=0;
			       	       sum++;
				}
			}
//			printf("%d %d %d %d\n",prev,this,sum,num);

			prev=this;
		}
		if(num==1) sum++;
		printf("%d\n",sum);
	}
}

