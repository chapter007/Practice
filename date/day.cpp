#include <stdio.h>
#define ISYEAP(x) x%100!=0&&x%4==0||x%400==0 ? 1:0

int dayofmonth[13][2]{
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

int buf[5001][13][32];

struct date{
	int day,month,year;
	void next(){
		day++;
		if(day>dayofmonth[month][ISYEAP(year)]){
			day=1;
			month++;
			if(month>12){
				month=1;
				year++;
			}
		}
	}
}da;

void init(){
	da.day=1;
	da.month=1;
	da.year=0;
}
int main(){
	int y,d,cnt=1;
	init();
	while(da.year!=5001){
		buf[da.year][da.month][da.day]=cnt;
		da.next();
		cnt++;
	}
	while(scanf("%d %d",&y,&d)!=EOF){
		for(int i=1;i<13;i++){
			for(int j=1;j<32;j++){
				//printf("%d %d %d\n",buf[y][1][1]+d,i,j);
				if(buf[y][1][1]+d-1==buf[y][i][j]){
					printf("%.4d-%.2d-%.2d\n",y,i,j);
				}
			}
		}
	}
	return 0;
}
