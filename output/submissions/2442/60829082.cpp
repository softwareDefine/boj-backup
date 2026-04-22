#include <cstdio>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++){
		for(int j=a;j>i;j--){
			printf(" ");
		}
		for(int j=0;j<i*2-1;j++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}