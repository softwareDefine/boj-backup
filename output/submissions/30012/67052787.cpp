#include <stdio.h>

#include <math.h>

int s, n,l,k;

int e[30010];

int mmn = 9999999,mmnx;

int main()

{

	scanf("%d %d", &s, &n);	for (int i = 0; i < n; i++) {

		scanf("%d", e + i);

	}

	scanf("%d %d", &k, &l);

	for (int i = 0; i < n; i++) {

		int len = abs(e[i] - s);

		if (len >= k * 2) {

			if (mmn > l * (len - k * 2)) {

				mmn = l * (len - k * 2);

				mmnx = i;

			}

		}

		else {

			if (mmn > (k * 2 - len)) {

				mmn = (k * 2 - len);

				mmnx = i;

			}

		}

	}

	printf("%d %d", mmn, mmnx+1);

}