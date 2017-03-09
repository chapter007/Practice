#include <stdio.h>
#include <string.h>
#include <algorithm>
#define N 100000

using namespace std;

char str[N];
int d[1000];

int abs(int a){
	return a>0?a:-a;
}
void clean(){
	for(int i=0;i<N;i++){
		str[i]=0;
	}
}

void clean_d(){
	for(int i=0;i<1000;i++){
		d[i]=0;
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int m;
		clean();
		//clean_d();
		scanf("%s",str);
		scanf("%d",&m);
		while(m--){
			char cmd[30],rcmd[30],a;
			int k=0;
			scanf("%s %c",cmd,&a);
			//printf("%s %c\n",cmd,a);
			if(strcmp(cmd,"INSERT")==0){
				int l=strlen(str);
				str[l]=a;
				//printf("%s\n",str);
			}else if(strcmp(cmd,"QUERY")==0){
				int x=a-'0',ans=-1;
				//printf("test-query %d\n",x);
				clean_d();
				int len=strlen(str);
				int top=len-1,base=0;
				/*while(top>=base){
					int mid=(top+base)/2;
					if(str[mid]==str[x]&&mid!=x){
						d[k]=abs(mid-x);
						k++;
					}else if(mid>x) top=mid-1;
					else base=mid+1;
				}*/
				for(int i=0;i<len;i++){//直接查找会超时 
					if(str[i]==str[x]&&i!=x){
						d[k]=abs(i-x);
						k++;
					}
				}
				sort(d,d+k);
				for(int i=0;i<k;i++){
					if(d[i]>0){
						ans=d[i];
						break;
					}
				}
				printf("%d\n",ans);
			}	
		}
	}
	return 0;
}
