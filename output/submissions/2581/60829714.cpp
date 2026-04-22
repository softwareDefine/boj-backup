#include <iostream>

using namespace std;

int n, m;
int fibo[10010];
int flag, sum;
int mmn;

int main()
{
	cin >> n >> m;
	for (int i = 2; i <= m;i++) {
		if (fibo[i] == 1) {
			continue;
		}
		for (int j = i*2 ; j <= m; j += i) {
			fibo[j] = 1;
		}
		
	}
	for (int i = n; i <= m; i++) {
		if (i == 1) {
			continue;
		}
		if (fibo[i] == 0) {
			if (flag == 0) {
				mmn = i;
				flag = 1;
			}
			sum += i;
		}
		
	}
	if (sum == 0) {
		cout << -1;
	}
	else {
		cout << sum << '\n';
		cout << mmn;
	}
}