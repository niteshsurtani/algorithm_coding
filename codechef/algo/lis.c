#include<stdio.h>

int main(){
	int i,j,n,a[100],lis[100],max=-1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	lis[0]=0;
	int m;
	for(i=0;i<n;i++){
		m=0;
		for(j=i-1;j>=0;j--){
			if(a[i]>a[j])
				if(lis[j+1]>m) m=lis[j+1];
		}
		lis[i+1]=m+1;
		if(lis[i+1]>max) max=lis[i+1];
	}
	printf("%d\n",max);
	return 0;
}
