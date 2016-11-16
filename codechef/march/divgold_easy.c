#include<stdio.h>
#include<string.h>
#include<malloc.h>

void move(char *r,int i){
	char tmp=r[i];
	int k;
	for(k=i-1;k>=0;k--){
		r[k+1]=r[k];
	}
	r[0]=tmp;
}

char* compare(char* ans,char *r, int len){
	int i;
//	printf("len=%d r = %s ans_bef=%s ",len,r,ans);
	
	for(i=0;i<len;i++){
		if(r[i]<ans[i]){ 
//			printf("ans_raft = %s\n",r);
			strcpy(ans,r);
		       	return ans;
		}
		else if(r[i]>ans[i]){
//			printf("ans_aaft = %s\n",ans);
		       	return ans;
		}
	}
//	printf("ans_aft = %s\n",ans);
	return ans;
}

int main(){
	int t,len;
	char s[100];
	char *ans,*r;
	ans=(char *)malloc(sizeof(char)*100);
	r=(char *)malloc(sizeof(char)*100);
	int i,j;
	char tmp;
	scanf("%d",&t);
	while(t--){
		scanf("%d%s",&len,s);
		strcpy(ans,s);
		for(i=0;i<len;i++){	
			strcpy(r,s);
			move(r,i);

			ans=compare(ans,r,len);
//			printf("%s\n",ans);
			
			for(j=0;j<len-1;j++){
				tmp=r[j];
				r[j]=r[j+1];
				r[j+1]=tmp;
				ans=compare(ans,r,len);
//				printf("%s %s\n",r,ans);
			}
		}

		printf("%s\n",ans);
	}
	return 0;
}
