// a-524.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <bitset>

using namespace std;

int n,k;
bitset<1133500> bit[160];
int score[160][160];
int arr[160];
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	cin >> k;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		int acc = 0;
		for (int j = i; j <= n; j++) {
			sum += arr[j];
			acc += sum;
			score[i][j] = acc;
		}
	}
	if (k > score[1][n]) {
		cout << k << '\n';
		return 0;
	}
	bit[0].set(0, 1);
	for (int i = 1; i <= n; i++) {
		bit[i].set(score[1][i], 1);
		for (int j = 0; j < n; j++) {
			bit[i] |= bit[j] << score[j + 2][i];
		}
	}
	while (true) {
		if (bit[n].test(k) == 0) {
			cout << k;
			break;
		}
		k += 1;
	}
	return 0;
}