#include <cstdio>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int change[6];
int temp;
int main() {
	for(int i=0;i<5;i++){
		scanf("%d",&change[i]);
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){
			if(change[j]>change[j+1]){
				temp=change[j];
				change[j]=change[j+1];
				change[j+1]=temp;
				for(int h=0;h<5;h++){
					printf("%d ",change[h]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}