#include<iostream>
#include<cstdio>
using namespace std;

char a[55][55];
char b[55][55];
int m,n;

void rotate()
{
    int i,j;
    for(i=0; i<m; i++)   //顺时针旋转90度后保存到b数组里
    {
        for(j=0; j<n; j++)
            b[j][m-1-i]=a[i][j];
    }
    for(i=0; i<n; i++)   //保存回a数组
    {
        for(j=0; j<m; j++)
            a[i][j]=b[i][j];
        a[i][j]='\0';
    }

    int tmp=m;    //记得交换m,n
    m=n;
    n=tmp;
}

int main()
{
    int tes;
    int i,j;

    while(~scanf("%d",&tes))
    {
        while(tes--)
        {
            scanf("%d%d",&m,&n);
            for(i=0; i<m; i++)
                scanf("%s",a[i]);

            int d;
            scanf("%d",&d);
            d=d/90;     //判断要旋转的次数
            while(d--)
                rotate();
            for(i=0; i<m; i++)
                printf("%s\n",a[i]);
        }
    }
    return 0; 
}

/*
2
2 3
111
000
90
3 3
111
101
111
180
*/
