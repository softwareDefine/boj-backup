#include <iostream>
#include <vector>

using namespace std;

vector<unsigned long long> vc;
unsigned long long arr[900010];
unsigned long long sum;
unsigned long long n;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (unsigned long long i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		arr[i + n] = arr[i];
	}
	long long all = 0;
	for (unsigned long long i = 0; i < n; i++) {
		long long val = 0;
		for (unsigned long long j = i; j < i + n; j++) {
			val += arr[j];
			if (val < 0) {
				long long x = -val;
				all += (x - 1) / sum + 1;
			}
		}
	}
	cout << all;
}