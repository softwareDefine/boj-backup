#include <iostream>
#include <math.h>


using ll = long long;
using namespace std;

int n;
int cont[21];
ll po[21];
ll ans = 0;
void DnC(int w, int d, int h) {
bool flag = 0;
	if (w == 0 || d == 0 || h == 0) {
		return;
	}
    int mmn = min(w,min(d,h));
	int cnt = log2(mmn);
	for (int i = cnt; i >= 0; i--) {
		if (cont[i] > 0) {
			cnt = i;
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		cout << "-1";
		exit(0);
	}
	ll a = po[cnt];
	cont[cnt]--;
	ans++;
	DnC(w - a, d, h);
	DnC(a,d, h - a);
	DnC(a, d-a,  a);
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int w, d, h;
	for (int i = 0; i < 21; i++) {
		po[i] = pow(2, i);
	}
	cin >> w >> d >> h;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		cont[a] = b;
	}
	DnC(w, d, h);
	cout << ans;
}