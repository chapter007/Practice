#include <stdio.h>
#include <stack>
using namespace std;

int main(){
	char origin[100];
	char newc[100];
	stack<int> S;
	while(scanf("%s",origin)!=EOF){
		for(int i=0;origin[i]!=0;i++){
			if(origin[i]==')'){
				if(S.empty()){
					newc[i]='?';
				}else if(origin[S.top()]=='('){
					S.pop();
					newc[i]=' ';
				}
			}else if(origin[i]=='('){
				S.push(i);
				newc[i]=' ';
			}else newc[i]=' ';

		}
		while(!S.empty()){
			int i=S.top();
			newc[i]='$';
			S.pop();
		}
		puts(origin);
		puts(newc);
	}
	return 0;
}
