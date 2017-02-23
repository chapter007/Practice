#include <stdio.h>

int main(){
	char str1[20],str2[20];
	while(scanf("%s %s",str1,str2)!=EOF){
		int ans=0;
		for(int i=0;str1[i]!=0;i++){
			for(int j=0;str2[j]!=0;j++){
				int a=str1[i]-'0';
				int b=str2[j]-'0';
				ans+=a*b;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
