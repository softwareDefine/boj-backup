#include <bits/stdc++.h>
#define mod 1000000007

using ll = long long;
using namespace std;

ll n;
ll sum;

long long reverser(long long x, long long n) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return x % mod;
	}
	long long ans = reverser(x, n / 2) % mod;
	if (n % 2 == 0) {
		return ((ans * ans) % mod);
	}
	else {
		return (((ans * ans) % mod) * x) % mod;
	}
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        ll a,b;
        cin >> b >> a;
        sum = ((sum% mod) + ((a % mod)*(reverser(b,mod-2) % mod) % mod))%mod;
    }
    cout << sum;
}