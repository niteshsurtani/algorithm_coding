#include<stdio.h>
#include<malloc.h>
#include<limits.h>

typedef struct node
{
	int value;
	int count;
}block;


void find_majority(int *a, block *majority, int n, int k){
	int i,j,flag,zero;
	for(i=0;i<n;i++){
		int num = a[i];
		printf("NUM = %d\n", num);
		flag = 0;
		zero = INT_MIN;
		for(j=0;j<k;j++){

			if(majority[j].value == num){
				majority[j].count++;
				flag = 1;
				break;
			}
			else if(zero == INT_MIN && majority[j].value == 0){
				zero = j;
			}

		}
		
		if(zero > INT_MIN){
			majority[zero].value = num;
			majority[zero].count = 1;
		}

		else if(flag == 0){
			for(j=0;j<k;j++){
				if(majority[j].count > 0){
					majority[j].count--;	
					if(majority[j].count == 0)
						majority[j].value = 0;
				}
			}
		}
		for(j=0;j<k;j++){
			printf("%d %d\n", majority[j].value, majority[j].count);
		}

	}
}

int confirmCount(int num, int *a, int n, int k){
	int i, c = 0;
	for(i=0;i<n;i++){
		if(a[i] == num) c++;
	}
	if(c > n/k) return 1;
	return 0;
}

int main(){
	int i,j,n,k;
	scanf("%d%d",&n,&k);
	int a[n];

	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	block *majority;
	majority = (block *) malloc (sizeof(block) * k);
	
	for(j=0;j<k;j++){
		majority[j].count = 0;
		majority[j].value = 0;
	}

	find_majority(a,majority,n,k);

	printf("MAJORITY VOTED ELEMENTS  = ");
	for(j=0;j<k;j++){
		if(majority[j].value != 0){
			if(confirmCount(majority[j].value, a, n, k))
				printf("%d ", majority[j].value);
		}
	}
	printf("\n");

	return 0;
}