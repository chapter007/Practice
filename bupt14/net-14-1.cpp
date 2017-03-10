#include <stdio.h>

int mix(int a){
	int ans=1;
	for(int i=0;i<a;i++){
		ans*=2;
	}
	return ans;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int a,b,c,d;
		scanf("%d %d",&a,&b);
		//printf("%d %d",mix(a),mix(b));
		if(a>b){
			a=mix(a);
			b=mix(b);
			c=a;
			d=a/b+1;
		}else if(a<b){
			a=mix(a);
			b=mix(b);
			c=b;
			d=b/a+1;
		}else{
			a=mix(a);
			c=a/2;
			d=1;
		}
		printf("%d/%d\n",d,c);
	} 
	return 0;
}
