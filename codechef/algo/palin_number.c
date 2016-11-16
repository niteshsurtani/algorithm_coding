#include<stdio.h>
#include<string.h>
#include<malloc.h>

int main(){
	int n;
	scanf("%d",&n);
	int i;
	int k;
	for(i=0;i<n;i++){
		char *c;
		c=(char *) malloc(sizeof(char)*1000002);
		scanf("%s",c);
		int len=strlen(c);
		int change=0;
		int mid=len/2;
		int odd=0;
		if(len%2==0){
			// even
			odd=0;
		}
		else{
			// odd
			odd=1;
		}
		int j;
		for(j=mid-1;j>=0;j--){
			if(c[j]>c[len-j-1]){
				change=1;
				break;

			}
			else if(c[j]<c[len-j-1]){
				break;
			}
		}
		int point=j;
		if(change==1){
			for(j=point;j>=0;j--){
				c[len-j-1]=c[j];
			}
		}
		else{
			int carry=0;
			int inc=0;
			int dec;
			for(j=mid-(1-odd);j>=0;j--){
				dec=c[j]-48;
				if(j==mid-1+odd) inc=1;
				else inc=0;
				
				dec=dec+inc+carry;
				carry=0;
				if(dec>9){
					dec=0;
					carry=1;
				}
				c[j]=dec+48;
				if(odd==0 || j!=mid)
					c[len-j-1]=c[j];
			}
			if(carry>0){
				printf("1");
				c[len-1]=carry+48;
			}
		}
		printf("%s\n",c);
	}
	return 0;
}
