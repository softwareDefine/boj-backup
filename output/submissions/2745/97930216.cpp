#include <bits/stdc++.h>

using ll = long long;
using namespace std;

string n;
int b;
ll sum;

int main() {
	cin >> n >> b;
	for(int i=0; i<n.length(); i++) {
		int now = n[i] - '0';
		if(n[i] >= 'A') {
			now = n[i] - 'A' + 10;
		}
		sum += pow(b,(n.length()-i-1))*now;
	}
	cout << sum;
}