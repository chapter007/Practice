#include <stdio.h>

int main(){
	int a,b;
	char n[20];
	while(scanf("%d %s %d",&a,n,&b)!=EOF){
		char tmp[20];
		int c=1;
		for(int i=0;n[i]!=0;i++){
			if(n[i]>='0'&&n[i]<='9'){
				tmp[i]=n[i];
			}else if(n[i]>='a'&&n[i]<='z'){
				tmp[i]=n[i]-'a'+10;
			}else tmp[i]=n[i]-'A'+10;
		}
		for(int i=0;tmp[i]!=0;i++)
			printf("%c",tmp[i]);
	}
	return 0;
}
