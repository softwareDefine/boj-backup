#include <stdio.h>



int main(){

	

	int i, x, y, z, total = 1;

	int digit[10] = {0, };



	scanf("%d %d %d", &x, &y, &z);

	

	total = x * y * z;



	

	while(total > 0){

		

		x = total % 10;



		digit[x] += 1;



		total /= 10;

	}



	for(i = 0; i < 10; i++) {



		printf("%d\n", digit[i]);

	}



}


