#include <iostream>
#include <string>

using namespace std;

int mod = 127;
int base = 256;

int hasher(string s) {
	int ans = 0;
	for (char ch : s) {
		ans = (ans * base + ch) % mod;
 }
	return ans;
}

int match(string &s, string &p) {
	int n = s.length(), m = p.length();
	if (n < m) return 0;
	int hash_s = hasher(s.substr(0, m));
	int hash_p = hasher(p);
	int first = 1;
	for (int i = 0; i < m - 1; i++) {
		first = (first * base) % mod;
	}
	for (int i = 0; i <= n - m; i++) {
		if (hash_p == hash_s) {
			if (s.substr(i,m) == p) {
				return 1;
			}
		}
		if (i + m < n) {
			hash_s = hash_s - (s[i] * first) % mod;
			hash_s = (hash_s + mod) % mod;
			hash_s = ((hash_s * base) % mod + s[i + m]) % mod;
		}
	}
	return 0;
}

int main()
{
	string s, p;
	cin >> s >> p;
	cout << match(s, p);
}