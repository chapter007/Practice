#include <stdio.h>
 
void printWelcome(int len)
{
       printf("��ӭ��ӭ -- %d\n", len);
}
 
void printGoodbye(int len)
{
       printf("�Ϳ��Ϳ� -- %d\n", len);
}
 
void callback(int times, void (* print)(int))
{
       int i;
       for (i = 0; i < times; ++i)
       {
              print(i);
       }
       printf("\n�Ҳ�֪������ӭ�ͻ����Ϳ�!\n\n");
}
int main(void)
{
	   callback(10, printWelcome);
       callback(10, printGoodbye);
       printWelcome(5);
       return 0;
}
