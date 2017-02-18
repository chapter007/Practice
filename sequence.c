#include <stdio.h>

//delete the min num(suppose is unique) and return the deleted num,the blank position will be replaced by the last num

int delete_min(int *l);
int main(){
	int l[10]={1,2,4,3,2,5,6,7,8,9};
	int min=delete_min(l);
	printf("the min is %d\n",min);
	for(int i=0;i<10;i++){
		printf("%d ",l[i]);
	}
	return 0;
}
int delete_min(int *l){
	int min,position;
	min=l[0];
	position=0;
	for(int i=0;i<10;i++){
		if(min>l[i]){
			min=l[i];
			position=i;
		}
	}
	l[position]=l[9];
	return min;
}
