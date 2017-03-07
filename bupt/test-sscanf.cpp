#include <stdio.h>

int main(){
	int a,b,c,d;
	char str[20],k;
	scanf("%s",str);
	k=0;
	int m=sscanf(str,"%d.%d.%d.%d%c",&a,&b,&c,&d,&k);
	printf("%d\n",m);
	return 0;
} 
