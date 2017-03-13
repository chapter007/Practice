#include <stdio.h>
#include <string.h>
#define N 1001

int Tree[N];

int main(){
	int n,m,l;
	while(scanf("%d %d %d",&n,&m,&l)!=EOF){
		int a,b;
		memset(Tree,-2,sizeof(Tree));
		for(int i=0;i<m;i++){
			scanf("%d %d",&a,&b);
			Tree[b]=a;	
		}
		Tree[0]=-1;

		int m=l;
		double res=1;
		while(Tree[m]!=-1){
			int i=0;
			double cnt=0;
			while(i<N){
				if(Tree[m]==Tree[i]){
					cnt++;
				}
				i++;
			}
			//printf("cnt %.1f %d\n",cnt,Tree[m]);
			res*=1/cnt;
			
			m=Tree[m];
		}
		
		printf("%.6f\n",res);
	}
	return 0;
}
