
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 20
 
main()
{
    int t, a, b, c, d;
    char s[MAXN], k;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s); k=0;
        if(sscanf(s,"%d.%d.%d.%d%c",&a,&b,&c,&d,&k)==4){//sscanf���÷�����Ҫѧϰһ�� 
        //sscanf������������ַ���������ݣ����Ͼ��ǲ����192.168.1.1����ip�ģ�����ĸ�ȫ�����֣���kΪ4������k����� 
            if (k==0 && 0<=a && a<=255 && 0<=b && b<=255 && 0<=c && c<=255 && 0<=d && d<=255) puts("Yes");
            else puts("No");
        }
        else puts("No");
    }
    return 0;
}
