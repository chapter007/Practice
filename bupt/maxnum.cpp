#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
	int t;
	int num[1001];
	scanf("%d",&t);
	while(t--){
		int n;
		for(int i=0;i<1001;i++) num[i]=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&num[i]);
		}//input;
		sort(num,num+n);
		for(int i=n-1;i>0;i--){
			if(num[i]!=num[i-1]){
				printf("%d %d\n",num[i],num[i-1]);
				break;		
			}
		}
	}
	return 0;
}
