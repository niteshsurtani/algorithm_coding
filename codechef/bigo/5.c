#include<stdio.h>
#include<string.h>

int cmpfnc (const void * a, const void * b)
{
	   return ( *(char*)a - *(char*)b );
}

void main(){
	int i,j,t;
	char a[100],b[100],c[100],d[100];
	int A,B,C,D;
	int min, rem;
	char min_str[100];
	scanf("%d",&t);
	while(t--){
		scanf("%s%s%s%s",a,b,c,d);
		A=strlen(a);
		B=strlen(b);
		C=strlen(c);
		D=strlen(d);
		
		qsort(a,A,sizeof(char),cmpfnc);
		qsort(b,B,sizeof(char),cmpfnc);
		qsort(c,C,sizeof(char),cmpfnc);
		qsort(d,D,sizeof(char),cmpfnc);

		rem=0;

		min=A;
		strcpy(min_str,a);
		if(B<min){
		       	min=B;
			strcpy(min_str,b);
		}
		if(C<min){
		       	min=C;
			strcpy(min_str,c);
		}
		if(D<min){
		       	min=D;
			strcpy(min_str,d);
		}
	
		char v;
		int ptr1,ptr2,ptr3,ptr4;
		ptr1=ptr2=ptr3=ptr4=0;
		int flag=0;
		for(i=0;i<min;i++){
			v=min_str[i];
			while(a[ptr1]<v){
				ptr1++;
				rem++;
				if(ptr1==A){
					flag=1;
					break;
				}
			}
			if(flag==1) break;
			ptr1++;
			while(a[ptr2]<v){
				ptr2++;
				rem++;
				if(ptr2==B){
					flag=1;
					break;
				}
			}
			if(flag==1) break;
			ptr2++;
			while(a[ptr3]<v){
				ptr3++;
				rem++;
				if(ptr3==C){
					flag=1;
					break;
				}
			}
			if(flag==1) break;
			ptr3++;
			while(a[ptr4]<v){
				ptr4++;
				rem++;
				if(ptr4==D){
					flag=1;
					break;
				}
			}
			if(flag==1) break;
			ptr4++;
		}
		rem+=((A-ptr1)+(B-ptr2)+(C-ptr3)+(D-ptr4));
		printf("%d\n",rem);
	}
}

