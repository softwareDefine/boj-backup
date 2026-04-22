#include <iostream>

using namespace std;
long long n;
long long arr[100010];
long long d[100010];
long long p[100010];
long long prefix[100010];
long long cnt;
long long allsum;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		allsum += arr[i];
	}
	prefix[1] = arr[1];
	for (int i = 2; i <= n; i++) {
		prefix[i] = prefix[i - 1] + arr[i];
	}
	// d 즉 i 부분 dp 부분
	for (int j = 1; j <= n;j++) {
		d[j]=d[j-1]+(prefix[j]*4==allsum);
	}
	// p 즉 k 부분 dp부분
	for (int j = n-1; j >= 1; j--) {
		p[j] = p[j + 1] + (prefix[j] * 4 == 3 * allsum);
	}
	for (int j = 2; j <= n-1; j++) {
		if (prefix[j] * 2 == allsum) {
			cnt += d[j - 1] * p[j + 1];
		}
	}
	cout << cnt;
}