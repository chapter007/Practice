#include <stdio.h>

int main(){
	int a,b,sum;
	char c;
	while(scanf("%d",&a)!=EOF){
		sum=0;
		while(scanf("%c",&c)!=EOF&&(c=='+'||c=='-'||c=='*'||c=='/')){//判断出c是运算符 
			scanf("%d",&b);
			if(c=='+'){//加减的优先级低，直接对sum操作 
				sum+=a;
				a=b;
			}else if(c=='-'){
				sum+=a;
				a=-b;
			}else if(c=='*'){//乘除的优先级更高，所以是对a操作 
				a*=b;
			}else if(c=='/'){
				a/=b;
			}
		}
		printf("%d\n",sum+a);
	}
	return 0;
}
