#include <stdio.h>
#include <queue>

using namespace std;

int num[4500],a[2500],b[2500];
queue<int> Q;

int mix(int k){
	int ans=1;
	for(int i=0;i<k;i++) ans=2*ans;
	return ans;
}

void convert(int a[],int mi){
	for(int i=0;i<mi;i++){
				a[i]=i;
	}
	int j=0;
	for(int i=0;i<mi;i++){
		//printf("%d ",a[i]);
		if(a[i]%2==0){
		a[j]=a[i];
		j++;
	}else{
		Q.push(a[i]);
		}
	}
	while(!Q.empty()){
		//printf("a[i] is %d \n",a[i]);	
		a[j]=Q.front();
		j++;
		Q.pop();
	}		
}

void convert2(int a[],int mi){
	for(int i=mi/2;i<mi;i++){
				a[i]=i;
	}
	int j=mi/2;
	for(int i=mi/2;i<mi;i++){
		//printf("%d ",a[i]);
		if(a[i]%2==0){
		a[j]=a[i];
		j++;
	}else{
		Q.push(a[i]);
		}
	}
	while(!Q.empty()){
		//printf("a[i] is %d \n",a[i]);	
		a[j]=Q.front();
		j++;
		Q.pop();
	}
		
}

int main(){
	int T;
	while(scanf("%d",&T)!=EOF){
		while(T--){
			int k;
			scanf("%d",&k);
			int mi=mix(k);
			//printf("???%d",mi);
			
			for(int i=0;i<mi;i++){
				scanf("%d",&num[i]);
			}
			convert(a,mi); 
			convert(b,mi/2);
			convert2(b,mi);
			for(int i=0;i<mi;i++){
				printf("%d ",num[a[b[i]]]);
			}
			printf("\n");
			
		}
	}
	return 0;
}
