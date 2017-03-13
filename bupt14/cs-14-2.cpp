#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#define N 51
#define M 1001

using namespace std;

int buf[N][N];

void print(int n,int m,int a){
	if(a==0){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				printf("%d",buf[i][j]);
			}
			printf("\n");
		}
	}else if(a==90){
		for(int i=0;i<n;i++){
			for(int j=m-1;j>=0;j--){
				printf("%d",buf[j][i]);
			}
			printf("\n");
		}
	}else if(a==180){
		for(int i=n-1;i>=0;i--){
			for(int j=0;j<m;j++){
				printf("%d",buf[i][j]);
			}
			printf("\n");
		}
	}else if(a==270){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				printf("%d",buf[j][i]);
			}
			printf("\n");
		}
	}
	
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m,angle;
		string tmp[N];
		memset(buf,-1,sizeof(buf));
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++){
			cin>>tmp[i];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<tmp[i].size();j++){
				int d=tmp[i][j]-'0';
				buf[i][j]=d;
			}
		}
		scanf("%d",&angle);//输入结束，开始处理输出
		if(angle==0){
			print(n,m,0);
		}else if(angle==90){
			print(m,n,90);
		}else if(angle==180){
			print(n,m,180);
		}else if(angle==270){
			print(m,n,270);
		}
	}
	return 0;
}
