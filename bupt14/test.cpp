#include <stdio.h>

int main(){
	int T,a,b,c;
	scanf("%d",&T);
	while(T--){
		getchar();
		scanf("%d/%d/%d",&a,&b,&c);
		printf("%d/%d/%d\n",a,b,c);
	}
	return 0;
}
