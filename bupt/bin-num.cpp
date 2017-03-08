#include <stdio.h>
#include <stack>

using namespace std;

stack<int> S;
void convert(long long num){
	//��һ���ܴ��numת��Ϊ2����
	while(num>0){
		int y=num%2;
		num/=2;
		S.push(y);
	}
	while(!S.empty()){
		int t=S.top();
		printf("%d",t);
		S.pop();
	}
	printf("\n");
}

int main(){
	int T;
	long long num[1001];
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%lld",&num[i]);//input
		convert(num[i]);
	}
	return 0;
}
