











#include <stdio.h>

#include <string.h>

/*

예를 들어, 세준이의 최고점이 70이고, 수학점수가 50이었으면 수학점수는 50/70*100이 되어 71.43점이 된다.

*/

int main(){

	

	int max = 0, score[1000] = {0, }, i, j, n;

	double sum = 0.0;

	

	scanf("%d", &n);



	for(i = 0; i < n; i++){

		

		scanf("%d", &score[i]);

		

		max < score[i] ? (max = score[i]) : max;

	}

	

	for(i = 0; i < n; i++){

		

		sum += (double)score[i] / (double)max * 100.0;

	}

	

	printf("%.2lf", sum / (double)n);

}