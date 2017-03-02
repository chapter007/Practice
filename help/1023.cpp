#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct node
{
	char no[10];
	char name[10];
	int score;
}buf[100010];

bool cmp1(node a, node b)
{
	return strcmp(a.no,b.no)<0;
}

bool cmp2(node a,node b)
{
    if(strcmp(a.name,b.name)!=0)
        return strcmp(a.name,b.name)<0;
    else
        return strcmp(a.no,b.no)<0;
}
bool cmp3(node a,node b)
{
	if(a.score!=b.score)
		return a.score<b.score ;
    else
        return strcmp(a.no,b.no)<0;
}

int main()
{
	int n,count=0,c;
	while(scanf("%d%d",&n,&c)!=EOF&&n!=0)
	{
	    
		for(int i=0;i<n;i++)
		{
			scanf("%s%s%d",buf[i].no,buf[i].name,&buf[i].score);
		}
		count++;
		if(c==1)
			sort(buf,buf+n,cmp1);
		else if(c==2)
			sort(buf,buf+n,cmp2);
		else
			sort(buf,buf+n,cmp3);
		printf("Case %d:\n",count);
		for(int i=0;i<n;i++)
		{
			printf("%s %s %d\n",buf[i].no,buf[i].name,buf[i].score);
		}
	}
	return 0;
}

/*
3 1 学号 当若干学生具有相同姓名或者相同成绩时，则按他们的学号递增排序。
000007 James 85
000010 Amy 90
000001 Zoe 60
4 2名字 
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 90
4 3成绩 
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 90
*/


