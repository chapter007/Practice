#include<iostream>
#include<cstdio>
using namespace std;

char a[55][55];
char b[55][55];
int m,n;

void rotate()
{
    int i,j;
    for(i=0; i<m; i++)   //˳ʱ����ת90�Ⱥ󱣴浽b������
    {
        for(j=0; j<n; j++)
            b[j][m-1-i]=a[i][j];
    }
    for(i=0; i<n; i++)   //�����a����
    {
        for(j=0; j<m; j++)
            a[i][j]=b[i][j];
        a[i][j]='\0';
    }

    int tmp=m;    //�ǵý���m,n
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
            d=d/90;     //�ж�Ҫ��ת�Ĵ���
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
