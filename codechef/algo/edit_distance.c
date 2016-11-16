#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int min(int a, int b){
	if(a<b) return a;
	return b;
}

int minimum(int a,int b, int c){
	return min(a,min(b,c));
}

int main(){
	int i,j,n,m;
	char a[100],b[100];
	int dist[100][100];
	
	scanf("%s%s",a,b);
	n=strlen(a);
	m=strlen(b);

	for(i=0;i<=n;i++){
		dist[i][0]=i;
	}
	for(j=0;j<=m;j++){
		dist[0][j]=j;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i-1]==b[j-1])		
				dist[i][j]=dist[i-1][j-1];
			else
				dist[i][j]=minimum(dist[i-1][j-1],dist[i-1][j],dist[i][j-1])+1;
		}
	}
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			printf("%d ",dist[i][j]);
		}
		printf("\n");
	}
	printf("%d\n",dist[n][m]);
	return 0;
}

