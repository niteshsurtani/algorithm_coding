#include<stdio.h>
#include<string.h>

int max(int a,int b){
	if(a>b) return a;
	return b;
}

void main(){
	char a[100],b[100];
	int i,j,m,n;
	scanf("%s%s",a,b);
	m=strlen(a);
	n=strlen(b);
	int lcs[m+1][n+1];
	
	for(i=0;i<=m;i++)
		for(j=0;j<=n;j++)
			lcs[i][j]=0;

	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(a[i-1]==b[j-1])
				lcs[i][j]=lcs[i-1][j-1]+1;
			else
				lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
		}
	}
	char common[10][lcs[m][n]];
	i=m;
	for(j=n;j>0;j--){
		if(a[i-1]==b[j-1]){
			printf("%c",a[i-1]);
			i--;
		}
	}
	
}

