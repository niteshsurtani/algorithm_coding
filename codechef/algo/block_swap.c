#include<stdio.h>

int gcdr(int m, int n){
	if(n==0) return m;
	gcdr(n,m%n);
}

int main(){
	int a[100],d,i,j,n;
	scanf("%d%d",&n,&d);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int gcd=gcdr(d,n);
	int circle=n/gcd;
	int temp, num, ptr;
	for(i=0;i<gcd;i++){
		temp=a[i];
		ptr = i;
		for(j=0;j<circle;j++){
			ptr=(ptr-d+n)%n;
			num=a[ptr];
			a[ptr]=temp;
			temp=num;
		}
	}
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
