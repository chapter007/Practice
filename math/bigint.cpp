#include <stdio.h>
#include <string.h>

struct bigint{
    int digit[1000];
    int size;
    void init(){
        size=0;
        for(int i=0;i<1000;i++)
            digit[i]=0;
    }
    void set(char str[]){
        init();
        int length=strlen(str);
        for(int i=length-1,j=0,t=0,c=1;i>=0;i--){
            t+=(str[i]-'0')*c;
            j++;
            c*=10;
            if(j==4||i==0){
                digit[size++]=t;
                j=0;
                t=0;
                c=1;
            }
        }
    }
    void outPut(){
        for(int i=size-1;i>=0;i--){
            if(i!=size-1) printf("%04d",digit[i]);
            else printf("%d",digit[i]);
        }
        printf("\n");
    }

    bigint operator + (const bigint &A) const{
        bigint ret;
        ret.init();
        int carry=0;
        for(int i=0;i<A.size||i<size;i++){
            int tmp=A.digit[i]+digit[i]+carry;
            carry=tmp/10000;
            tmp%=10000;
            ret.digit[ret.size++]=tmp;
        }
        if(carry!=0){
            ret.digit[ret.size++]=carry;
        }
        return ret;
    }

}a,b,c;

int main(){
    char stra[1000],strb[1000];
    while(scanf("%s %s",stra,strb)!=EOF){
        a.set(stra);
        b.set(strb);
        c=a+b;
        c.outPut();
    }
    return 0;
}
