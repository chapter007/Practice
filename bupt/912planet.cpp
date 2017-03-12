#include <stdio.h>
#include <string.h>

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,i=0,name_id[101]={0},score[101]={0};
		scanf("%d",&n);
		while(n--){
			char cmd[30];
			int name=0;
			int ans1=-1,ans2=-1;
			scanf("%s",cmd);
			if(strcmp(cmd,"Insert")==0){
				scanf("%d %d",&name_id[i],&score[i]);
				i++;
			}else if(strcmp(cmd,"Find")==0){
				scanf("%d",&name);
				for(int j=0;j<i;j++){
					if(name==name_id[j]){
						ans1=name_id[j];ans2=score[j];
						break;	
					}
				}
				if(ans2==-1){
					printf("No result!\n");
				}else{
					printf("name:%d score:%d\n",ans1,ans2);
				}
			}
		}
	}
	return 0;
}
