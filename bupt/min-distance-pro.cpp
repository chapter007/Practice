#include<stdio.h>
#include<string.h>
#include<vector>
#include<stdlib.h>
using namespace std;
int main()
{
    int N;
    scanf("%d",&N);
    for(int k=1;k<=N;k++)
    {
        vector<int> * p;
        p=new vector<int> [27];//´ú±í26¸ö×ÖÄ¸
        char s[100005];
        memset(s,0,sizeof(s));
        getchar();
        scanf("%s",s);
        int len=strlen(s);
        for(int i=0;i<len;i++)
            p[s[i]-'a'+1].push_back(i);
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            getchar();
            char tmp[20];
            scanf("%s",tmp);
            if(strcmp(tmp,"INSERT")==0)
            {
                char ch;
                getchar();
                scanf("%c",&ch);
                s[len]=ch;
                p[ch-'a'+1].push_back(len);
                len++;
                s[len]='\0';
            }
            else if(strcmp(tmp,"QUERY")==0)
            {
                int x;
                scanf("%d",&x);
                if(p[s[x]-'a'+1].size()==1)
                    printf("-1\n");
                else
                {
                    int min=0x7ffff;
                    for(int j=0;j<p[s[x]-'a'+1].size();j++)
                        if(abs(p[s[x]-'a'+1][j]-x)<min&&abs(p[s[x]-'a'+1][j]-x)!=0)
                            min=abs(p[s[x]-'a'+1][j]-x);
                    printf("%d\n",min);
                }
            }
            else
                ;
        }
    }
    //system("pause");
    return 0;
}
