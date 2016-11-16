#include<stdio.h>
#include<string.h>

int main(){
	int t,len;
	char s[100];
	int p,q,i;
	scanf("%d",&t);
	while(t--){
		scanf("%d%s",&len,s);
	       	p=q=i=0;
		while(i<len-1 && s[i]<=s[i+1]){
			i++;
		}
		p=i;
		if(p>=len-1){
			printf("%s\n",s);
			continue;
		}
		i++;
		char min=s[i];
		q=i;
		i++;
		while(i<len){
			if(s[i]<min){
			       	min=s[i];
				q=i;
			}
			i++;
		}
		while(p>=0 && s[q]<s[p]){
			p--;
		}
		char temp=s[q];
		for(i=q-1;i>p;i--){
			s[i+1]=s[i];
		}
		s[p+1]=temp;
		printf("%s\n",s);

	}
	return 0;
}

