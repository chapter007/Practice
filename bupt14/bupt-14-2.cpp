#include <stdio.h>
#include <algorithm>
#define N 100001

using namespace std;

int main()
{
    int T;
    while(scanf("%d",&T)!=EOF)
    {
        while(T--)
        {
            int n;
            int a[100],b[100001]= {0},c[100001]= {0};
            scanf("%d",&n);
            for(int i=0; i<n; i++)
            {
                scanf("%d",&a[i]);
            }
            for(int i=0; i<n; i++)
            {
                int tmp=a[i]-a[i+1];
                if(tmp<0)
                {
                    tmp*=-1;
                    c[tmp]++;
                }
                else
                {
                    b[tmp]++;
                }
            }
            sort(b,b+N);
            sort(c,c+N);
            if(b[N-1]>c[N-1])
                printf("%d\n",b[N-1]+1);
            else
                printf("%d\n",c[N-1]+1);
        }
    }
    return 0;
}
