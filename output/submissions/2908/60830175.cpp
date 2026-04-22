#include <stdio.h>







int main() {





	int x, y, x2, y2;    

	int f[2], m[2], l[2], i;



	scanf("%d %d", &x, &y);



	for (i = 0; i < 2; i++) {



		f[0] = x / 100;

		m[0] = (x % 100) / 10;

		l[0] = (x % 100) % 10;





		x2 = ((l[0] * 100) + (m[0] * 10) + f[0]);







		f[1] = y / 100;

		m[1] = (y % 100) / 10;

		l[1] = (y % 100) % 10;





		y2 = ((l[1] * 100) + (m[1] * 10) + f[1]);



	}







	if (x2 > y2) {

		printf("%d", x2);



	}

	else {

		printf("%d", y2);



	}



}