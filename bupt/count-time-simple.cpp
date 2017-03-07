#include <stdio.h>

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int h1,h2,m1,m2;
		scanf("%d:%d",&h1,&m1);
		scanf("%d:%d",&h2,&m2);
		h1=h2-h1;
		m1=m2-m1;
		if(h1<0||(h1==0&&m1<0)){
			h1+=24;
		}
		m1+=h1*60;
		printf("%d\n",m1);
	}
	return 0;
}
