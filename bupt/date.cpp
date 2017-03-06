#include <stdio.h>
#include <string.h>
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
	30,30,
	31,31,
	30,30,
	31,31,
	30,30
};
struct Date{
	int day;
	int month;
	int year;
	void nextday(){
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
};
int buf[2500][13][35];
int main(){
	Date tmp;
	int cnt=0;
	tmp.day=1;
	tmp.month=1;
	tmp.year=0;
	while(tmp.year!=2500){
		buf[tmp.year][tmp.month][tmp.day]=cnt;
		cnt++;
		tmp.nextday();
	}
	int t;
	int date2[20];
	scanf("%d",&t);
	while(t--){
		char date[20];
		scanf("%s",date);
		for(int i=0;i<20;i++) date2[i]=0;
		int l=strlen(date);
		int j=l-1,k=0;
		for(int i=0;date[i]!=0;i++){
			int ans=0,c=1;
				while(date[j]!=':'&&date[j]!=0){
					int tmp=date[j]-'0';
					tmp*=c;
					c*=10;
					ans+=tmp;
					j--;	
				}
				if(ans>0){
					//printf("%d ",ans);//分离出来年月日 
					date2[k]=ans;
					k++; 
				}
				j--;
			}
		printf("%d\n",buf[date2[2]][date2[1]][date2[0]]-buf[date2[2]][1][1]+1);

	}
	return 0;
	
} 
