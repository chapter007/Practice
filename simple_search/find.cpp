#include <stdio.h>
#include <string.h>

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
			if(cmd[0]=='0'){//·­×ª 
				for(int i=0;i<l;i++){
					if(i>=s&&i<=len-1){
						int k=len-1;
						while(k>=s){
							printf("%c",str[k]);
							k--;
						}
					}else printf("%c",str[i]);
				}
			}
			if(cmd[0]=='1'){//Ìæ»» 
				
			}
		}
	}
	return 0;
}
