#include <stdio.h>
#include <string.h>
#include <vector>
#define N 100005
#define INF 0x7ffff

using namespace std;

char str[N];

int abs(int a){
	return a>0 a:-a;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int m;
		vector<int> *p;
		p=new vector<int> [27];
		memset(str,0,sizeof(str));
		getchar();
		scanf("%s",str);
		printf("test--%s\n",str);
		int l=strlen(str);
		for(int i=0;i<l;i++) p[str[i]-'a'+1].push_back(i);//装入链表里 
		scanf("%d",&m);
		while(m--){
			char cmd[30],a;
			getchar();
			scanf("%s",cmd);
			if(strcmp(cmd,"INSERT")==0){
				getchar();
				scanf("%c",&a);
				int l=strlen(str);
				str[l]=a;
				p[a-'a'+1].push_back(l);
				l++;
				str[l]='\0';
			}else if(strcmp(cmd,"QUERY")==0){
				int x;
				scanf("%d",&x);
				if(p[str[x]-'a'+1].size()==1){
					printf("-1\n");
				}else{
					int min=INF;
					for(int j=0;j<p[str[x]-'a'+1].size();j++){
						if(abs(p[str[x]-'a'+1][j]-x)<min&&abs(p[str[x]-'a'+1][j]-x)!=0){
							min=abs(p[str[x]-'a'+1][j]-x);
						}
					}
					printf("%d\n",min);
				}
			}	
		}
	}
	return 0;
}
