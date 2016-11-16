#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void bucket_sort(char a[100][10], int k, int n){
	char bucket[10][n][10];
	int pointer[10]={0};
	int i,j;
	
	for(i=0;i<n;i++){
		char c=a[i][k%strlen(a[i])];
		int num=c-48;
		strcpy(bucket[num][pointer[num]++],a[i]);
	}
	for(j=9;j>=0;j--){
		if(pointer[j]==1){
			printf("%s",bucket[j][0]);
		}
		else if(pointer[j]>1){
			bucket_sort(bucket[j],k+1,pointer[j]);
		}
	}
}

int main(){
	int i,j,k,n;
	scanf("%d",&n);
	char a[n][10]; // Each num in of max length 10.

	for(i=0;i<n;i++){
		scanf("%s",a[i]);
	}

	bucket_sort(a,0,n);
	printf("\n");	
	return 0;
}
