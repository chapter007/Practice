#include <stdio.h>
#include <string.h>

int main(){
	int T;
	char a,b[100];
	scanf("%d",&T);
	while(T--){
		memset(b,0,sizeof(b));
		getchar();
		scanf("%s",b);
		printf("%s\n",b);
	}
	
	return 0;
}
