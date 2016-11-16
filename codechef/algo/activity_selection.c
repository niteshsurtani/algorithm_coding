#include<stdio.h>

int main(){
	int i,j,n,start[100],finish[100];

	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&start[i]);
	for(i=0;i<n;i++)
		scanf("%d",&finish[i]);

	int activity=1;
	int last=finish[0];
	// Finish is sorted/
	for(i=1;i<n;i++){
		if(last<start[i]){
			activity++;
			last=finish[i];
		}
	}
	printf("%d\n",activity);
	return 0;
}
