#include <stdio.h>
#include <vector>

using namespace std;


vector<int> A;

int main()
{
    int T;
    scanf("%d",&T);
    
        while(T--)
        {
            int n;
            int a;
            scanf("%d",&n);
            A.clear();
            for(int i=0; i<n; i++)
            {
                scanf("%d",&a);
                A.push_back(a);
            }//input
            if(A.size()<=2){
            	printf("%d\n",A.size());
			}else{
				int s=2;
				int ans=2;
				for(int i=2;i<A.size();i++){
				s=(A[i]-A[i-1]==A[i-1]-A[i-2]?s+1:2);
				if(ans<s) ans=s;
			}
			printf("%d\n",ans);	
			}
        }
    
    return 0;
}
