#include<stdio.h>
#define N 2101
 
int yeap(int x)
{
    if(x%4==0&&x%100!=0||x%400==0)
        return 1;
    else
        return 0;
}
int dayofmonth[13][2]=
{
    0,0,
    31,31,
    28,29,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31
};
 
struct node
{
    int y,m,d;
    int distance;
    void nextday()
	{
	d++;
	if(d>dayofmonth[m][yeap(y)])
        {
            d=1;
            m++;
            if(m>12)
            {
                m=1;
                y++;
            }
        }
    }
}buf[N][13][32];
int main()
{
    node tmp;
    tmp.y=0;
    tmp.m=1;
    tmp.d=1;
    int count=1;
    while(tmp.y<N)
    {
        buf[tmp.y][tmp.m][tmp.d].distance=count++;
        tmp.nextday();
    }
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            int y,m,d;
            scanf("%d:%d:%d",&y,&m,&d);
            printf("%d\n",buf[y][m][d].distance-buf[y][1][1].distance+1);
        }
    }
	return 0;
}
