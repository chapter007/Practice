#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

int op[][5]{
	1,0,0,0,0,
	1,0,0,0,0,
	1,0,0,0,0,
	1,1,1,0,0,
	1,1,1,0,0,
};

char str[100];
stack<int> num,ope;

void getOp(int &retn,bool &isOp,int &i){
	if(i==0&&ope.empty()){
		isOp=true;
		retn=0;
		return;
	}
	if(str[i]==0){
		isOp=true;
		retn=0;
		return;
	}
	if(str[i]>='0'&&str[i]<='9'){
		isOp=false;
	}else{
		isOp=true;
		if(str[i]=='+'){
			retn=1;
		}else if(str[i]=='-'){
			retn=2;
		}else if(str[i]=='*'){
			retn=3;
		}else if(str[i]=='/'){
			retn=4;
		}
		i++;
		return;
	}
	retn=0;
	
	for(;str[i]!='+'&&str[i]!='-'&&str[i]!='*'&&str[i]!='/'&&str[i]!=0;i++){
		retn*=10;
		retn+=str[i]-'0';
	}
	return;
}

void clean(){
	while(!num.empty()){
		num.pop();
	}
	while(!ope.empty()){
		ope.pop();
	}
}

int main(){
	while(gets(str)){
		clean();
		int idx=0,retn;
		bool isOp;
		while(true){
			getOp(retn,isOp,idx);
			if(!isOp){
				num.push(retn);
			}else{
				if(ope.empty()==true||op[retn][ope.top()]==1){//优先级高的运算符入栈 
					ope.push(retn);
				}else{
					while(op[retn][ope.top()]==0){
						int tmp=ope.top();
						ope.pop();
						int a=num.top();
						num.pop();
						int b=num.top();
						num.pop();
						if(tmp==1){
							num.push(a+b);
						}else if(tmp==2){
							num.push(b-a);
						}else if(tmp==3){
							num.push(a*b);
						}else if(tmp==4){
							if(a!=0)
								num.push(b/a);
							else return 0;
						}
					}
					ope.push(retn);
				}
			}
			if(ope.size()==2&&ope.top()==0){
				break;
			}
		}
		printf("%d\n",num.top());
	}
	return 0;
}
