#include <stdio.h>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > Q;

void clean(){
	while(!Q.empty()){
		Q.pop();
	}
}

int main(){
	int n,sum;
	while(scanf("%d",&n)!=EOF){
		sum=0;
		clean();
		if(n==0) break;
		for(int i=0;i<n;i++){
			int x;
			scanf("%d",&x);
			Q.push(x);
		}
		while(!Q.empty()&&Q.size()>1){
			int a=Q.top();
			Q.pop();
			int b=Q.top();
			Q.pop();
			sum+=a+b;
			Q.push(a+b);
		}
		if(Q.size()==1){
			//sum+=Q.top();
			printf("%d\n",sum);
		}
	}
	return 0;
}
