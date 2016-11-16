#include<stdio.h>

int cmp(const void *a, const void *b){
	return (*(int *)a-*(int *)b);
}

int main(){
	int a[8]={10, 2, 3, 4, 5, 9, 7, 8};
	int i,j,k,n=8,x=23;
	qsort(a,8,4,cmp);
	int sum=0,str,end,reqr,sum1;	
	for(i=0;i<n-3;i++){
		for(j=i+1;j<n-2;j++){
			sum=a[i]+a[j];
			reqr=x-sum;
			str=j+1;
			end=n-1;
			while(str<end){
				sum1=a[str]+a[end];
				if(sum1<reqr) str++;
				else if(sum1>reqr) end--;
				else{
				       	printf("%d %d %d %d\n",a[i],a[j],a[str],a[end]);
					str++; end--;
				}
			}
		}
	}
	return 0;
}
