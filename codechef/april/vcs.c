#include<stdio.h>

void main(){
	int i,t,n,m,k,ptr1,ptr2,r1,r2;
	int a[1000],b[1000];
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&k);
		for(i=0;i<m;i++)
			scanf("%d",&a[i]);
		for(i=0;i<k;i++)
			scanf("%d",&b[i]);
		
		ptr1=ptr2=0;
		r1=r2=0;
		for(i=1;i<=n;i++){
			if(i==a[ptr1] && a[ptr1]==b[ptr2]){
			       ptr1++;
		       	       ptr2++;
			       r1++;
			}	
			else if(i!=a[ptr1] && i!=b[ptr2])
				r2++;
			else if(i==a[ptr1]) ptr1++;	
			else if(i==b[ptr2]) ptr2++;	
		}
		printf("%d %d\n",r1,r2);
	}
}

