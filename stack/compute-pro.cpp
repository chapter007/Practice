#include <stdio.h>

int main(){
	int a,b,sum;
	char c;
	while(scanf("%d",&a)!=EOF){
		sum=0;
		while(scanf("%c",&c)!=EOF&&(c=='+'||c=='-'||c=='*'||c=='/')){//�жϳ�c������� 
			scanf("%d",&b);
			if(c=='+'){//�Ӽ������ȼ��ͣ�ֱ�Ӷ�sum���� 
				sum+=a;
				a=b;
			}else if(c=='-'){
				sum+=a;
				a=-b;
			}else if(c=='*'){//�˳������ȼ����ߣ������Ƕ�a���� 
				a*=b;
			}else if(c=='/'){
				a/=b;
			}
		}
		printf("%d\n",sum+a);
	}
	return 0;
}
