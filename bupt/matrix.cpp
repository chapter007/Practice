#include <stdio.h>
#define N 11

struct matric{
	long long v[N][N];
}m;

matric multi(matric a,matric b,int n){
	matric c;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			c.v[i][j]=0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				c.v[i][j]+=a.v[i][k]*b.v[k][j];
			}
		}
	}
	return c;
}

void print(matric a,int n){
	for(int i=0;i<n;i++){
		bool first=true;
		for(int j=0;j<n;j++){
			if(first){
				printf("%lld",a.v[i][j]);
				first=false;
			}else{
				printf("% lld",a.v[i][j]);
			}
		}
		printf("\n");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,k;
		bool first=true;
		matric res;
		scanf("%d %d",&n,&k);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%lld",&m.v[i][j]);
			}//input
		}
		if(k==1){
			print(m,n);
		}else{
			for(int i=0;i<k-1;i++){
				if(first){
					res=multi(m,m,n);
					first=false;	
				}else{
					res=multi(res,m,n);
				}
			}
			print(res,n);	
		}
	}
	return 0;
} 
