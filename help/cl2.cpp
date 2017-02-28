#include<stdio.h>
#include<algorithm>
using namespace std;

long long a[100001];
int main()
{
    int  n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        sort(a,a+n);
        int c=0,i;
        long long tmp=a[c];
        for(i=1;i<n;i++)
        {
            if(tmp==a[i])
            {
                i=i+2;
                c=i-1;
                tmp=a[c];
            }
            else
            {
                printf("%lld\n",a[c]);
                break;
            }
        }
    }
    return 0;
}
