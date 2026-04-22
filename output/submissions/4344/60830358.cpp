









#include <stdio.h>



int main(){

	

	int t_c, N, i, j, k, score[1001] = {0, };

		

	scanf("%d", &t_c);

	

	for(i = 0; i < t_c; i++){

		

		int sum = 0, cnt = 0;

		double avg = 0.0;

		

		scanf("%d", &N);



		for(j = 0; j < N; j++){

			

			scanf("%d", &score[j]);

			sum += score[j];

		}

		

		avg = (double)sum / (double)N; // 반 평균

		

		for(k = 0; k < N; k++){

			

			if(avg < score[k])

				cnt++;

		}

		

		avg = (double)cnt / (double)N;

		

		printf("%.3lf%\n", avg * 100);

	}

}