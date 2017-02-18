#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;
struct E{
	char name[100];
	int age;
	int score;
	bool operator < (const E &b)const{
		if(score!=b.score) return score<b.score;
		int tmp=strcmp(name,b.name);
		if(tmp!=0) return name<b.name;
		else return age<b.age;
	}
}buf[100];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%s %d %d",&buf[i].name,&buf[i].age,&buf[i].score);
		}	
		sort(buf,buf+n);
		for(int i=0;i<n;i++){
			printf("%s %d %d",buf[i].name,buf[i].age,buf[i].score);
			printf("\n");
		}
		
	}
	return 0;
}