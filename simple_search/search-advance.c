#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;
struct student{
	char no[10];
	char name[10];
	char sex[5];
	int age;
	bool operator < (const student A)const{
		return strcmp(no,A.no);
	}
}buf[1000];

int main(){
	int n,ans[1000]={-1};
	char s[10];
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%s %s %s %d",buf[i].no,buf[i].name,buf[i].sex,&buf[i].age);
		}
		sort(buf,buf+n);
		int m;
		scanf("%d",&m);
		for(int i=0;i<m;i++){	
			scanf("%s",s);
			int base=0,top=n-1;
			while(top>=base){
				int mid=(top+base)/2;
				if(strcmp(s,buf[mid].no)==0){
					ans[i]=mid;
					break;
				}
				else if(strcmp(s,buf[mid].no)>0){top=mid-1;}
				else base=mid+1;
			}
			//printf("%d\n",ans[i]);
		}

		for(int i=0;i<m;i++){
			if(ans[i]==-1){
				printf("No Answer!\n");
			}
			else printf("%s %s %s %d\n",buf[ans[i]].no,buf[ans[i]].name,buf[ans[i]].sex,buf[ans[i]].age);
		}
	}
	return 0;
}
