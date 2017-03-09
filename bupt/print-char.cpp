#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		//printf("1.test-input %d\n",T);
		char c,str[1000];
		cin>>c>>str;
		//printf("2.test-input %d\n",T);
		int ans=0;
		for(int i=0;str[i]!=0;i++){
			if(str[i]==c){
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
