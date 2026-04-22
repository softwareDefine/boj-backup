#include <iostream>
#define mod 1000000007

using ll = long long;
using namespace std;
int n;
ll arr[500010];
ll rar[500010];
ll sum;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) { cin >> arr[i]; rar[i] = arr[i]; arr[i] = (arr[i - 1]%mod + arr[i]%mod)%mod; }
	for (int i = 2; i <= n; i++) {
		sum += (arr[i-1] * rar[i])%mod;
	}
	cout << sum % mod;
}