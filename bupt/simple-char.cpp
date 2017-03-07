#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int abs(int a){
	return a>0?a:-a;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		char str[1001];
		scanf("%s",str);
		int l=strlen(str);
		int tmp[1001],k=0;
		for(int i=0;i<1001;i++) tmp[i]=0;
		for(int j=97;j<123;j++){//从a到z全部转换一遍试试 
			for(int i=0;i<l;i++){
				int x=str[i]-j;
				int y;
				if(x>0){
					y=26-x;
				}else if(x<0){
					y=26+x;
				}else if(x==0){
					continue;
				}
				if(abs(x)<y)	tmp[k]=tmp[k]+abs(x);
				else tmp[k]=tmp[k]+y;
				//printf("test-tmp %d %d\n",tmp[k],k);
			}
			//printf("test %d %d\n",tmp[k],k);
			k++;//转换完一个字母后换另一个 
		}
		sort(tmp,tmp+k);
		//for(int i=0;i<k;i++)
		printf("%d\n",tmp[0]);
	}
	return 0;
} 
