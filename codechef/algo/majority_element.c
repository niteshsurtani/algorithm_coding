#include<stdio.h>


int right(int a[100], int s, int e, int num){
	if(s==e){
		if(a[s]==num) return s;
		else return s-1;
	}
	int m=(s+e)/2;
	if(a[m]==num)
		right(a,m+1,e,num);
	else
		right(a,s,m-1,num);
}

int left(int a[100], int s, int e, int num){
	printf(" s = %d\n",s);
	if(s==e){
		if(a[s]==num) return s;
		else return s+1;
	}
	else if(s>e) return s;
	int m=(s+e)/2;
	if(a[m]==num)
		left(a,s,m-1,num);
	else
		left(a,m+1,e,num);
}

int main(){
	
	int i,j,n,a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int mid=(n-1)/2;
	int ele=a[mid];
	printf("%d\n",ele);
	int start=left(a,0,mid-1,ele);
	int end=right(a,mid+1,n-1,ele);
	printf("%d %d\n",start,end);
	if((end-start+1)>(n/2))
		printf("%d\n",a[mid]);
	else
		printf("no\n");
	return 0;
}
