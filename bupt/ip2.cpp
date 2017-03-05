#include <stdio.h>
#include <string.h>
 
int main(){
    int T;
    while(scanf("%d",&T)!=EOF){
        while(T-->0){
            int flag=-1;
            char ip[30];
            int c=1,ans=0,p=0;
            scanf("%s",ip);
            int j=strlen(ip)-1;
            while(j>=0){
                while(ip[j]!='.'&&ip[j]!=0){
                    if(ip[j]>='0'&&ip[j]<='9'){  
                        int tmp=ip[j]-'0';
                        tmp=tmp*c;
                        c*=10;
                        ans+=tmp;
                    }else{
                        ans=-1;
                        break;
                    }
                    j--;
                    //printf("test %d\n",ans);
                }
                p++;
                j--;
                //printf("test %d\n",ans);
                if(ans>=0&&ans<=255) flag=1;
                else{
                    flag=-1;
                    break;
                }
                ans=0;
                c=1;
            }
            if(flag==1&&p==4)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
