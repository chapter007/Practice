#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

stack<string> S;
queue<char> Q; 
int main(){
	char str[1000];
	while(gets(str)){
		int i=0,j=0;
		int len=strlen(str);
		while(j<=len){
			while(str[i]!=' '&&str[i]!=0){
				Q.push(str[i]);
				if(str[i+1]==' '){
					i+=2;
					break;
				}else{
					i++;
				}
			}
			string word;
			while(!Q.empty()){
				word+=Q.front();//±£´æµ½Õ» 
				Q.pop();
			}
			S.push(word);
			j++;
		}
		bool isfirst=true;
		while(!S.empty()){
			if(S.top()!=""){
				if(isfirst){
					cout<<S.top();
					isfirst=false;
				}else cout<<" "<<S.top();
			}
			S.pop();
		}
		printf("\n");
	}
	return 0;
} 
