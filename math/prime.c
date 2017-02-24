#include <stdio.h>
#include <math.h>

bool judge(int x){
	if(x<=1) return false;
	int bound=(int)sqrt(x)+1;
	for(int i=2;i<bound;i++){
		if(x%i==0) return false;
	}
	return true;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		puts(judge(n)?"yes":"no");
	}
	return 0;
}
