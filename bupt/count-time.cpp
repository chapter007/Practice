#include <stdio.h>
//题意理解错误，题目是要求第一个时间点到第二个时间点需要多长时间！！！审题务必要清楚 
struct time{
	int h,m;
	void next(){
		m++;
		if(m==60){
			m=0;
			h++;
		}
	}
	time operator - (const time &A) const{
		time ret;
		if(m<=A.m&&h<=A.h){
			ret.h=A.h-h;
			ret.m=A.m-m;
		}else if(m<A.m&&h>A.h){
			ret.m=m+60-A.m;
			ret.h=h-1-A.h;
		}else if(m>A.m&&h<A.h){
			ret.h=A.h-h-1;
			ret.m=A.m+60-m;
		}else if(m>=A.m&&h>=A.h){
			ret.h=h-A.h;
			ret.m=m-A.m;
		}
		return ret;
	}
};

int main(){
	int t;
	scanf("%d",&t);
	/*time tmp;
	tmp.h=0;
	tmp.m=0;
	int cnt=0;
	while(tmp.h<50){
		buf[tmp.h][tmp.m]=cnt;
		tmp.next();
		cnt++;
	}*/
	while(t--){
		time t1,t2;
		scanf("%d:%d",&t1.h,&t1.m);
		scanf("%d:%d",&t2.h,&t2.m);
		time t3= t1-t2;
		if(t1.h<t2.h) t1.h+=24;
		else t2.h+=24;
		//printf("changed t1 %d:%d\n",t1.h,t1.m);
		time t4=t1-t2;
		//printf("test t3 %d:%d\n",t3.h,t3.m);
		//printf("test t4 %d:%d\n",t4.h,t4.m);
		int cnt=t3.h*60+t3.m;
		int cnt2=t4.h*60+t4.m;
		if(cnt>cnt2){
			printf("%d\n",cnt2);
		}else{
			printf("%d\n",cnt);
		}
	}
	return 0;
}
