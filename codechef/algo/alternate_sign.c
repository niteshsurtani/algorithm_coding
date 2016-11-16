#include<stdio.h>

int neg, pos, tog;
int find(int *a, int n){
	if(tog==0){
		while(neg!=n){
			if(a[neg]<0){ 
			       return neg;
			}
			neg++;
		}
	}
	else{
		while(pos!=n){
			if(a[pos]>=0){
			       return pos;
			}
			pos++;
		}
	}
}

void rotate(int *a){
	int temp,ptr,i;
	if(tog==0){
		temp=a[neg];
		for(i=neg-1;i>=pos;i--){
			a[i+1]=a[i];
		}
		a[i+1]=temp;
	}
	else{
		temp=a[pos];
		for(i=pos-1;i>=neg;i--){
			a[i+1]=a[i];
		}
		a[i+1]=temp;
	}

}

void print(int *a, int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

int main(){
	int a[10]={-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
	int i,j,n=10;
	pos=neg=tog=0;
	while(pos!=n && neg!=n){
		if(tog==0){
			neg=find(a,n);
			if(neg>pos){
				rotate(a);
				pos++;
				neg++;
			}
			else neg++;
			tog=1;
		}
		else{
			pos=find(a,n);
			if(pos>neg){
				rotate(a);
				pos++;
				neg++;
			}
			else pos++;
			tog=0;
		}
	}
	print(a,n);
}
