#include <stdio.h>
#include <string.h>
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
}s[N];

void find_name(char name[]){
	
	for(int i=0;i<n;i++){
		//cout<<s[i].name;
		if(strcmp(name,s[i].name)==0){
			//cout<<name;
			mark[i]=1;
			break;
		}
	}
}

void find_sex(char sex[]){
	for(int i=0;i<n;i++){
		if(sex==s[i].sex){
			mark[i]=1;
			break;
		}
		if(sex!=s[i].sex&&mark[i]==1){
			mark[i]=0;
			break;
		}
	}
}

void find_birth(char birth[]){
	int y,mo,d,sy,smo,sd;
	 
	if(sscanf(birth,"%d/%d/%d",&y,&mo,&d)==3){
		for(int i=0;i<n;i++){
			sscanf(s[i].birthday,"%d/%d/%d",&sy,&smo,&sd);
			if(y==sy&&mo==smo&&d==sd){
				mark[i]=1;
				break;
			}else if(mark[i]==1){
				mark[i]=0;
			}
		}
	}else{
		//сп*╣д
		char a[10],b[10],c[10];
		sscanf(birth,"%s/%s/%s",a,b,c);
		cout<<a;
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		memset(mark,0,sizeof(mark));
		for(int i=0;i<n;i++){
			cin>>s[i].name>>s[i].sex>>s[i].birthday;
		}
		while(m--){
			char name[30],sex[20],birthday[30];
			char cmd[100];
			cin>>cmd;
			int l=strlen(cmd);
			for(int i=0;cmd[i]!=0;i++){
				if(cmd[i]=='N'){
					memset(res,0,sizeof(res));
					j=0;
					int k=0;bool flag=false;
					while(k<l){
						if(cmd[k-1]=='\''||flag){
							res[j]=cmd[k];
							flag=true;
							if(cmd[k+1]=='\'') flag=false;
							j++;
						}
						k++;
					}
					find_name(res);
				}else if(cmd[i]=='S'){
					memset(res,0,sizeof(res));
					j=0;
					int k=0;bool flag=false;
					while(k<l){
						if(cmd[k-1]=='\''||flag){
							res[j]=cmd[k];
							flag=true;
							if(cmd[k+1]=='\'') flag=false;
							j++;
						}
						k++;
					}
					//cout<<res;
					find_sex(res);			
				}else if(cmd[i]=='B'){
					memset(res,0,sizeof(res));
					j=0;
					int k=0;bool flag=false;
					while(k<l){
						if(cmd[k-1]=='\''||flag){
							res[j]=cmd[k];
							flag=true;
							if(cmd[k+1]=='\'') flag=false;
							j++;
						}
						k++;
					}
					//cout<<res;
					find_birth(res);
				}
			}
			
			bool ok=false;
			for(int i=0;i<N;i++){
				if(mark[i]){
					printf("%s\n",s[i].name);
					ok=true;
				}
			}
			if(!ok) printf("NULL\n");
			memset(mark,0,sizeof(mark));
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
