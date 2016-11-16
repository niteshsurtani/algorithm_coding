#include<stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	int i;
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",a+i);
	}

	int start=0;
	int end=n-1;

	int mid=(start+end)/2;
	while(mid-start != 1){
		if(a[mid]==1){
			start=mid;
		}
		else{
			end=mid;
		}


	return 0;
}
