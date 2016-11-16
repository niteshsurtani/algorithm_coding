#include<stdio.h>

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
		if(i==len-1){
			printf("%s\n",s);
			continue;
		}
		p=i;
		
		i++;
		q=i;
		char min=s[q];
		
		i++;
		while(i<len){
			if(s[i]<=min){
				min=s[i];
				q=i;
			}
			i++;
		}

	//	printf("%d %d %c\n",p,q,min);
		int step=0;
		int last_loc=0;
		for(i=q-1;i>=0;i--){
			if(s[i]>=min){
				s[i+1]=s[i];
				 if(s[i]>min){
					last_loc=i+1;
					step++;
				 }
			}
			else{
				break;
			}
		}
		s[i+1]=min;
//		printf("%d %d %s\n",p,q,s);
		if(step==1){
			char tmp=s[last_loc];
			for(i=last_loc+1;i<len;i++){
				if(s[i]<=tmp){
					s[i-1]=s[i];
				}
				else
					break;
			}
			s[i-1]=tmp;
		}

		printf("%s\n",s);
	}

	return 0;
}
