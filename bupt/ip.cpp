#include <stdio.h>
#include <string.h>


int main(){
	int T;
	scanf("%d",&T);
		while(T--){
			int flag=-1;
			int ip1,ip2,ip3,ip4;
			char str[30],k=0;
			scanf("%s",str);
			if(sscanf(str,"%d.%d.%d.%d%c",&ip1,&ip2,&ip3,&ip4,&k)==4){
				if(k==0&&ip1>=0&&ip1<=255&&ip2>=0&&ip2<=255&&ip3>=0&&ip3<=255&&ip4>=0&&ip4<=255) 
					flag=1;
			}
			//printf("k- %d\n",k);
			
			if(flag==1)
				printf("Yes\n");
			else
				printf("No\n");
		}
	
	return 0;
}

