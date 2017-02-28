#include <stdio.h>
#include <algorithm>
#define N 100001

using namespace std;
long long a[N];

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
        for(int i=0;i<n;i+=3){
            if(a[i]!=a[i+2]){
                printf("%lld\n",a[i]);
                break;
            }
        }
    }
    return 0;
}
