#include <stdio.h>
#include <string.h>
#define ISYEAP(x) x%100!=0&&x%4==0||x%400==0 ? 1:0

int dayOfMonth[13][2]{
	0,0,
    31,31,
    28,29,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31
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
int buf[2500][13][32];
int main(){
	Date tmp;
	int cnt=1;
	tmp.day=1;
	tmp.month=1;
	tmp.year=0;
	while(tmp.year!=2500){
		buf[tmp.year][tmp.month][tmp.day]=cnt;
		tmp.nextDay();
		cnt++;
	}
	int t;
	scanf("%d",&t);
	while(t--){
		int day,month,year;
		scanf("%d:%d:%d",&year,&month,&day);
		printf("%d\n",buf[year][month][day]-buf[year][1][1]+1);
	}
	return 0;
	
} 
