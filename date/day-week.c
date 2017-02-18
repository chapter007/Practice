#include <stdio.h>
#include <string.h>
#define ISYEAP(x) x%100!=0&&x%4==0||x%400==0?1:0

int dayOfMonth[13][2]{
	0,0,
	31,31,
	28,29,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
	30,30,
};
char week[7][10]{
	"Sun",
	"Mon",
	"Tue",
	"Wen",
	"Thu",
	"Fri",
	"Sat",
};
char month[13][20]{
	"",
	"Jan",
	"Feb",
	"March",
	"April",
	"May",
	"June",
	"July",
	"Aug",
	"Sep",
	"Oct",
	"Nov",
	"Dec",
};
struct Date{
	int day,month,year;
	void nextDay(){
		day++;
		if(day>dayOfMonth[month][ISYEAP(year)]){
			day=1;
			month++;	
		
			if(month>12){
				month=1;
				year++;	
			}
		}
	}
};
int buf[5001][13][32];
int Abs(int x){
	return x<0?-x:x;	
}

int main(){
	Date tmp;
	tmp.day=1;
	tmp.month=1;
	tmp.year=0;
	int cnt=0;
	while(tmp.year!=5001){
		buf[tmp.year][tmp.month][tmp.day]=cnt;
		tmp.nextDay();
		cnt++;
	}
	int y1,m1,d1;
	char m2[10];
	while(scanf("%4d %s %2d",&y1,&m2,&d1)!=EOF){
		for(int i=1;i<=12;i++){
			if(strcmp(m2,month[i])==0) m1=i;
		}
		//printf("%4d%2d%2d\n",y1,m1,d1);
		int day=buf[y1][m1][d1]-buf[2017][02][19];
		day+=0;
		int j=(day%7+7)%7;
		//printf("%d %d\n",day,j);
		printf("%s\n",week[j]);
	}
	return 0;

}
