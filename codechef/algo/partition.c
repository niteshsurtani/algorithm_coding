#include<stdio.h>

int max(int a, int b){
	if(a>b) return a;
	return b;
}

int main(){
	int i,j,n,sum,a[100];
	scanf("%d",&n);
	sum=0;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if(sum%2==1) printf("No\n");
	else{
		sum/=2;
		int dp[sum+1][n+1];
		for(j=0;j<=sum;j++){
			for(i=0;i<=n;i++){
			       	dp[j][i]=0;
			}
		}
		for(i=0;i<=n;i++) dp[0][i]=1;
		for(i=1;i<=sum;i++){
			for(j=1;j<=n;j++){
				int num;
				if(i-a[j-1]<0) num=0;
				else num=dp[i-a[j-1]][j-1];	
				dp[i][j]=max(dp[i][j-1],num);
			}
		}
		if(dp[sum][n]==1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
