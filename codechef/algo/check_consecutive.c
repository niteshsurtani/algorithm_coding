#include<stdio.h>

int main(){
	
	int i,j,n,a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int min=a[0];
	for(i=1;i<n;i++)
		if(a[i]<min) min=a[i];
	int sub=-1*min;

	int count=0;
	j=-1;
	int temp=a[0];

	while(1){
		i=j;
		j=temp+sub;
		
		temp=a[j];
		
		if(i==j){
			j++;
			i=j;
			if(j>=n) break;
			temp=a[j];
			j=temp+sub;
			if(j>=n) break;
			temp=a[j];
		}
		if(j>=n) break;

		if(temp!=-1){
			a[j]=-1;
			count++;
		}
		else{
			temp=i;
		}
	}
	if(count==n) printf("Yes\n");
	else printf("No\n");
	return 0;
}
