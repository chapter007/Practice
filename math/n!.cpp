
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

    void set(int x){
        init();
        do{
            digit[size++]=x%10000;
            x/=10000;
        }while(x!=0);
    }

    void outPut(){
        for(int i=size-1;i>=0;i--){
            if(i!=size-1) printf("%04d",digit[i]);
            else printf("%d",digit[i]);
        }
        printf("\n");
    }

    bigint operator * (int x) const{
        bigint ret;
        ret.init();
        int carry=0;
        for(int i=0;i<size;i++){
            int tmp=digit[i]*x+carry;
            carry=tmp/10000;
            tmp%=10000;
            ret.digit[ret.size++]=tmp;
        }
        if(carry!=0){
                ret.digit[ret.size++]=carry;
        }
        return ret;
    }
}a;

int main(){
    int b;
    while(scanf("%d",&b)!=EOF){
        a.set(1);
        for(int i=1;i<=b;i++){
            a=a*i;
        }
        a.outPut();
    }
    return 0;
}
