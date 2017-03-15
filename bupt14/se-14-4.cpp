#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#define N 501

using namespace std;

int n,m,j,mark[N];
char res[100];

struct student{
	char name[30];
	char sex[20];
	char birthday[30];
	int y,mo,d;
}s[N];

void find_name(char name[]){
	for(int i=0;i<n;i++){
		if(strcmp(name,s[i].name)==0){
			//cout<<name;
			mark[i]++;
		}
	}
}

void find_sex(char sex[]){
	for(int i=0;i<n;i++){
		if(strcmp(sex,s[i].sex)==0){
			mark[i]++;
		}else if(mark[i]==1){
			mark[i]=0;
		}
	}
}

void find_birth(char birth[]){
	int y,mo,d,sy,smo,sd;
	 
	if(sscanf(birth,"%d/%d/%d",&y,&mo,&d)==3){
		for(int i=0;i<n;i++){
			sscanf(s[i].birthday,"%d/%d/%d",&sy,&smo,&sd);
			if(y==sy&&mo==smo&&d==sd){
				mark[i]++;
			}else if(mark[i]==1){
				mark[i]=0;
			}
		}
	}else{
		//有*的
		char a[10],b[10],c[10];
		sscanf(birth,"%[^/]/%[^/]/%[^/]/",a,b,c);
		y=atoi(a);mo=atoi(b);d=atoi(c);
		//cout<<y<<mo<<d;
		for(int i=0;i<n;i++){
			sscanf(s[i].birthday,"%d/%d/%d",&sy,&smo,&sd);
			if(y==0&&mo==smo&&d==sd){
				mark[i]++;
			}else if(y==sy&&mo==0&&d==sd){
				mark[i]++;
			}else if(y==sy&&mo==smo&&d==0){
				mark[i]++;
			}else if(y==0&&mo==0&&d==sd){
				mark[i]++;
			}else if(y==0&&mo==smo&&d==0){
				mark[i]++;
			}else if(y==sy&&mo==0&&d==0){
				mark[i]++;
			}else if(y==0&&mo==0&&d==0&&mark[i]==1){
				mark[i]++;
			}else if(mark[i]==1){
				mark[i]=0;
			}
		}
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++){
			cin>>s[i].name>>s[i].sex>>s[i].birthday;
		}
		getchar();
		while(m--){
			char name[30],sex[20],birthday[30];
			char cmd[100]={0};
			memset(mark,0,sizeof(mark));
			gets(cmd);
			int l=strlen(cmd);
			for(int i=0;cmd[i]!=0;i++){
				if(cmd[i]=='N'&&cmd[i-1]!='\''){
					memset(res,0,sizeof(res));
					j=0;
					int k=i;bool flag=false;
					while(k<l){
						if(cmd[k-1]=='\''||flag){
							res[j]=cmd[k];
							flag=true;
							if(cmd[k+1]=='\''){
								flag=false;
								break;	
							}
							j++;
						}
						k++;
					}
					find_name(res);
					//break;
				}else if(cmd[i]=='S'&&cmd[i-1]!='\''){//会读取好几个值 
					memset(res,0,sizeof(res));
					j=0;
					int k=i;bool flag=false;
					while(k<l){
						if(cmd[k-1]=='\''||flag){
							res[j]=cmd[k];
							flag=true;
							if(cmd[k+1]=='\''){
								flag=false;
								break;	
							}
							j++;
						}
						k++;
					}
					//cout<<res;
					find_sex(res);
					//break;		
				}else if(cmd[i]=='B'&&cmd[i-1]!='\''){
					memset(res,0,sizeof(res));
					j=0;
					int k=i;bool flag=false;
					while(k<l){
						if(cmd[k-1]=='\''||flag){
							res[j]=cmd[k];
							flag=true;
							if(cmd[k+1]=='\'') {
								flag=false;
								break;	
							}
							j++;
						}
						k++;
					}
					//cout<<res;
					find_birth(res);
				}
			}
			
			int max=0;
			for(int i=0;i<N;i++){
				if(mark[i]>max) max=mark[i];
			}
			//cout<<max;
			if(max!=0){
				for(int i=0;i<N;i++){
				if(mark[i]==max){
					printf("%s\n",s[i].name);
					}
				}
			}else{
				printf("NULL\n");
			}
		}
	}
	return 0;
}

/*
1
5 6
Michael Male 1990/02/28
Amy Female 1992/04/03
Tom Male 1991/12/15
Lynn Female 1991/04/09
Zheng Male 1990/04/20

Name='Amy'
Name='Betty'
//Sex='Female' Birthday='/04/09'
//Sex='Female' Birthday='*//*'
//Name='Michael' Sex='Female'
//Name='Michael' Sex='Male' Birthday='1990/02/*'
*/
