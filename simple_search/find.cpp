#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

queue<char> Q;

int main(){
	char str[101],cmd[20];
	while(scanf("%s",str)!=EOF){
		int n;
		int l=strlen(str);
		scanf("%d",&n);
		while(n--){
			scanf("%s",cmd);
			int s=cmd[1]-'0';
			int len=cmd[2]-'0';
			len+=s;
			int k=len-1; 
			if(cmd[0]=='0'){//·­×ª 
				for(int i=0;i<l;i++){
					if(i>=s&&i<=len-1){
						Q.push(str[k]);
						k--;
					}else Q.push(str[i]);;
				}
				int i=0;
				while(!Q.empty()){
					str[i]=Q.front();
					i++;
					Q.pop();
				}
				printf("%s\n",str);
			}
			if(cmd[0]=='1'){//Ìæ»» 
				char newstr[50];
				int k=0;
				for(int i=3;cmd[i]!=0;i++){
					newstr[k]=cmd[i];
					k++;
				}
				k=0;
				for(int i=0;i<l;i++){	
					if(i>=s&&i<=len-1){
						str[i]=newstr[k];
						k++;
					}
				}
				printf("%s\n",str);
			}
		}
	}
	return 0;
}
