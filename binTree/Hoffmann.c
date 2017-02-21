#include <stdio.h>
#include <queue>

using namespace std;

int main(){
	priority_queue<int,vector<int>,greater<int>> Q;
	int n;
	int m[1000];
	while(scanf("%d",&n)!=EOF){
		int ans=0;
		for(int i=0;i<n;i++){
			scanf("%d",&m[i]);
			Q.push(m[i]);
		}
		while(true){
			if(!Q.empty()){
				int a=Q.top();
				Q.pop();
				if(!Q.empty()){
					int b=Q.top();
					Q.pop();
					ans+=a+b;
					Q.push(a+b);
				}else break;
			}else break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
