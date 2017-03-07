#include <stdio.h>
#include <string.h>

int convert(char ip[]){
	int j=strlen(ip)-1;
	//int i=j;
	int flag=0;
	int p=0;
			while(j>=0){
				int ans=0,c=1;
				bool check=false;
				while(ip[j]!='.'&&ip[j]!=0){
					if(ip[j]>='0'&&ip[j]<='9'){	
						int tmp=ip[j]-'0';
						//printf("test %d\n",tmp);
						tmp=tmp*c;
						c*=10;
						ans+=tmp;
						check=true;
					}else{
						ans=-1;
						break;
					}
					j--;
					
				}
				j--;
				p++;
				//printf("test %d\n",p);
				//printf("test %d\n",ans);
				if(ans>=0&&ans<=255&&check) flag=1;
				else{
					flag=-1;
					break;
				}
				if(p==4) flag=1;
				else flag=-1;
			}
			return flag;
}
int main(){
	int T;
	scanf("%d",&T);
		while(T--){
			//printf("test %d\n",T);
			int flag=-1;
			char ip[30];
			
			scanf("%s",ip);
			flag=convert(ip);
			if(flag==1)
				printf("Yes\n");
			else
				printf("No\n");
		}
	
	return 0;
}

