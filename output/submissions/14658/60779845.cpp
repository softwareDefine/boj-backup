#include <iostream>

using namespace std;

int n, m, l, k;

int starx[110];
int stary[110];
int cnt;
int mmx;
int main()
{
	cin >> n >> m >> l >> k;
	for (int i = 0; i < k; i++) {
		cin >> starx[i] >> stary[i];
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			cnt = 0;
			for (int h = 0; h < k; h++) {
				if (((starx[h] >= starx[i])&&(starx[h] <= starx[i]+l ))&&((stary[h] >= stary[j]) && (stary[h]<= stary[j]+l ))) {
					cnt++;
				}
			}
			mmx = max(mmx, cnt);
		}
	}
	cout << k-mmx;
}