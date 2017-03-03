#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct node
{
	char no[30];
	char name[100];
	char gender[10];
	int age;
}buf[1001];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%s%s%s%d",buf[i].no,buf[i].name,buf[i].gender,&buf[i].age);	
		}	
		int m;
		scanf("%d",&m);
		char match[30];
		while(m--)
		{
			int ans=-1;
			scanf("%s",match);
			for(int i=0;i<n;i++){
				if(strcmp(buf[i].no,match)==0){
					printf("%s %s %s %d\n",buf[i].no,buf[i].name,buf[i].gender,buf[i].age);
					ans=1;
					break;
				}
			}
			if(ans==-1)
				printf("No Answer!\n");
		}
	}	
	return 0;
}
