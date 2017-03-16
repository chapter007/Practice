#include <stdio.h>
#include <stack>
#include <iostream>

using namespace std;

stack<int> S;

void clean(){
	while(!S.empty()){
		S.pop();
	}
}
int main(){
	int n;
	char cmd[5];
	while(scanf("%d",&n)!=EOF){
		if(n==0) break;
		clean();
		while(n--){
			scanf("%s",cmd);
			//cin>>cmd;
			//gets(cmd);
			if(cmd[0]=='A'){
				if(S.empty()){
					printf("E\n");
					//break;
				}else{
					printf("%d\n",S.top());
					//break;
				}
			}else if(cmd[0]=='P'){
				int x;
				//sscanf(cmd,"%*s%d",&x);
				scanf("%d",&x);
				S.push(x);
			}else if(cmd[0]=='O'){
				if(!S.empty()){
					S.pop();
					//break;
				}
			}
		}
		if(n==-1)
			printf("\n");
	}
	return 0;
}
