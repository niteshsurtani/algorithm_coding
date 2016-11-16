#include<stdio.h>
#include<string.h>
#include<malloc.h>

void toggle(char* s, int start, int len, int k){
	int i;
	for(i=start;i<len,i<start+k;i++){
		if(s[i]=='G') s[i]='R';
		else s[i]='G';
	}
}

int main(){
	int t,len,k;
	char *s;
	int i,j,step;
	char tmp;
	s=(char*)malloc(sizeof(char)*100000);
	scanf("%d",&t);
	while(t--){
		step=0;
		scanf("%d%d%s",&len,&k,s);
		for(i=0;i<len;i++){	
			for(j=0;j<k;j++){
				if(s[i]=='G') continue;
				else{
					toggle(s,i,len,k);
					step++;
				}
			}
		}
		printf("%d\n",step);

	}
	return 0;
}
