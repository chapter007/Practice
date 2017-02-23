#include <stdio.h>
#include <string.h>
//c
int main(){
	int a,b;
	char n[20];
	while(scanf("%d %s %d",&a,n,&b)!=EOF){
		int tmp=0,lenth=strlen(n),c=1;
		for(int i=lenth-1;i>=0;i--){
			int x;
			if(n[i]>='0'&&n[i]<='9'){
				x=n[i]-'0';
			}else if(n[i]>='a'&&n[i]<='z'){
				x=n[i]-'a'+10;
			}else x=n[i]-'A'+10;
			tmp+=x*c;
			c*=a;
		}//convert to ten
		char ans[40],size=0;
		do{
			int x=tmp%b;
			ans[size++]=(x<10) ? x+'0' : x-10+'A';
			tmp/=b;
		}while(tmp);
		//convert to b
		for(int i=size-1;i>=0;i--){
			printf("%c",ans[i]);
		}
		printf("\n");
	}
	return 0;
}
