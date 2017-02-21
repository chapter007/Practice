#include <stdio.h>
#include <stack>
using namespace std;

int main(){
	char origin[100];
	char newc[100];
	stack<int> S;
	while(scanf("%s",origin)!=EOF){
		int i;
		for(i=0;origin[i]!=0;i++){
			if(origin[i]==')'){
				if(S.empty()){
					newc[i]='?';
				}else{
					S.pop();
					newc[i]=' ';
				}
			}else if(origin[i]=='('){
				S.push(i);
				newc[i]=' ';
			}else newc[i]=' ';

		}
		while(!S.empty()){
			newc[S.top()]='$';
			S.pop();
		}
		newc[i]=0;
		puts(origin);
		puts(newc);
	}
	return 0;
}
