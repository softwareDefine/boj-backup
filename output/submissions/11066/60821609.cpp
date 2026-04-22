#include <iostream>
#include <algorithm>

using namespace std;

int t;
int arr[510];
int sum[510];
int mem[1000][1000];

int dp(int start, int end) {
	//cout << start << ' ' << end << '\n';
	if (start == end) { return 0; }
	if (mem[start][end] != 99999999) {
		return mem[start][end];
	}
	//mem[start][end] = 99999999;
	for (int i = start; i < end; i++) {
		mem[start][end] = min(mem[start][end], dp(start, i) + dp(i+1, end) + sum[end] - sum[start - 1]);
	}
	return mem[start][end];
}

int main()
{
	cin >> t;
	while (t--) {
		for (int i = 0; i < 1000; i++) {
			for (int j = 0; j < 1000; j++) {
				mem[i][j] = 99999999;
			}
		}
		for (int i = 0; i < 510; i++) {
			arr[i] = 0;
			sum[i] = 0;
		}
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		//sort(arr, arr + n, [&](auto a, auto b) {return a < b; });
		for (int i = 1; i <= n; i++) {
			sum[i] += sum[i - 1] + arr[i-1];
		}
		cout << dp(1, n) << '\n';
	}
}