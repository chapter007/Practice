#include <stdio.h>
#include <string.h>

int main(){
	int n,m;
	int buf[201],hash[201];
	while(scanf("%d %d",&n,&m)!=EOF){
		memset(buf,0,sizeof(buf));
		memset(hash,0,sizeof(hash));
		for(int i=0;i<n;i++){
			scanf("%d",&buf[i]);
			hash[buf[i]]++;
		}
		for(int i=0;buf[i]>0;i++){
				if(hash[buf[i]]>1)
					printf("%d\n",hash[buf[i]]-1);
				else
					printf("BeiJu\n");
		}
	}
	return 0;
}
