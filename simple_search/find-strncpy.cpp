#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char str[100] = {0};
    char tmpstr[100] = {0};
    int  num = 0;
    int i = 0, j = 0;
    char orders[100][100] = {0};
    int begin, len;
    while(scanf("%s", str) != EOF)
    {
        scanf("%d", &num);
        for(i = 0; i < num; i++)
            scanf("%s", orders[i]);
        for(i = 0; i < num; i++)
        {
            begin = orders[i][1] - '0';
            len = orders[i][2] - '0';
            memset(tmpstr, 0, 100);
            if(orders[i][0] == '0')
            {
                strncpy(tmpstr, &str[begin], len);
                for(j = 0; j < strlen(tmpstr); j++)
                     str[begin + j] = tmpstr[len - j - 1];
                printf("%s\n", str);
            }
            else if(orders[i][0] == '1')
            {
                strncpy(&str[begin], &orders[i][3], len);
                printf("%s\n", str);
            }
        }
    }
    return 0;
}
 
/**************************************************************
    Problem: 1177
    User: MJ_kng
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:0 kb
****************************************************************/
