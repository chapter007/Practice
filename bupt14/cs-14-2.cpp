#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#define N 51
#define M 1001

using namespace std;

int buf[N][N],tb[N][N];
int n,m;

void rotate(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			tb[j][n-i-1]=buf[i][j];//��buf���ֵת�浽tmp�� 
		}
	}
//	
//		for(int i=0;i<m;i++){
//			for(int j=0;j<n;j++){
//				printf("%d",tb[i][j]);
//			}
//			printf("\n");
//		}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			buf[i][j]=tb[i][j];//��ת����
		}
	}
	int x=m;
	m=n;
	n=x;
}
void print(){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				printf("%d",buf[i][j]);
			}
			printf("\n");
		}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int angle;
		string tmp[N];
		memset(buf,-1,sizeof(buf));
		memset(tb,-1,sizeof(tmp));
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
		scanf("%d",&angle);//�����������ʼ�������
		int ang=angle/90;
		while(ang!=0){
			rotate();
			ang--;
		}
		print();
	}
	return 0;
}
