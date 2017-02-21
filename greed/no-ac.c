#include <stdio.h>
#include <algorithm>
using namespace std;

struct program{
	int starttime;
	int endtime;
	bool operator < (const program &A)const{
		return endtime<A.endtime;
	}
}buf[100];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n==0) break;
		for(int i=0;i<n;i++){
			scanf("%d %d",&buf[i].starttime,&buf[i].endtime);
		}
		sort(buf,buf+n);
		int ans=0;
		int currenttime=0;
		for(int i=0;i<n;i++){
			if(currenttime<=buf[i].starttime){
				currenttime=buf[i].endtime;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
