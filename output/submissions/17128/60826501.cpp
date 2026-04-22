#include <iostream>
#include <vector>

using namespace std;

vector<int> vc;
int a, b;
int sum;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		int c;
		cin >> c;
		vc.push_back(c);
	}
	for (int i = 0; i < 3; i++) {
		vc.push_back(vc[i]);
	}

	for (int j = 0; j < a; j++) {
		sum += vc[j] * vc[j + 1] * vc[j + 2] * vc[j + 3];
	}
	for (int i = 0; i < b; i++) {
		int q;
		cin >> q;
		if (q - 1 == 0) {
			sum -= vc[0] * vc[1] * vc[2] * vc[3];
			sum -= vc[a-1] * vc[0] * vc[1] * vc[2];
			sum -= vc[a-2] * vc[a-1] * vc[0] * vc[1];
			sum -= vc[a-3] * vc[a-2] * vc[a-1] * vc[0];
		}
		else if (q - 1 == 1) {
			sum -= vc[1] * vc[2] * vc[3] * vc[4];
			sum -= vc[0] * vc[1] * vc[2] * vc[3];
			sum -= vc[a - 1] * vc[0] * vc[1] * vc[2];
			sum -= vc[a - 2] * vc[a - 1] * vc[0] * vc[1];
		}
		else if (q - 1 == 2) {
			sum -= vc[2] * vc[3] * vc[4] * vc[5];
			sum -= vc[1] * vc[2] * vc[3] * vc[4];
			sum -= vc[0] * vc[1] * vc[2] * vc[3];
			sum -= vc[a - 1] * vc[0] * vc[1] * vc[2];
		}
		else {
		sum -= vc[q - 1] * vc[q] * vc[q + 1] * vc[q + 2];
		sum -= vc[q -2] * vc[q-1] * vc[q ] * vc[q + 1];
		sum -= vc[q - 3] * vc[q-2] * vc[q-1] * vc[q ];
		sum -= vc[q - 4] * vc[q-3] * vc[q -2] * vc[q -1];
		}
		vc[q - 1] *= -1;
		if ( q - 1 <3) {
			vc[q + a - 1] *= -1;
		}
		if (q - 1 == 0) {
			sum += vc[0] * vc[1] * vc[2] * vc[3];
			sum += vc[a - 1] * vc[0] * vc[1] * vc[2];
			sum += vc[a - 2] * vc[a - 1] * vc[0] * vc[1];
			sum += vc[a - 3] * vc[a - 2] * vc[a - 1] * vc[0];
		}
		else if (q - 1 == 1) {
			sum += vc[1] * vc[2] * vc[3] * vc[4];
			sum += vc[0] * vc[1] * vc[2] * vc[3];
			sum += vc[a - 1] * vc[0] * vc[1] * vc[2];
			sum += vc[a - 2] * vc[a - 1] * vc[0] * vc[1];
		}
		else if (q - 1 == 2) {
			sum += vc[2] * vc[3] * vc[4] * vc[5];
			sum += vc[1] * vc[2] * vc[3] * vc[4];
			sum += vc[0] * vc[1] * vc[2] * vc[3];
			sum += vc[a - 1] * vc[0] * vc[1] * vc[2];
		}
		else {
			sum += vc[q - 1] * vc[q] * vc[q + 1] * vc[q + 2];
			sum += vc[q - 2] * vc[q - 1] * vc[q] * vc[q + 1];
			sum += vc[q - 3] * vc[q - 2] * vc[q - 1] * vc[q];
			sum += vc[q - 4] * vc[q - 3] * vc[q - 2] * vc[q - 1];
		}
		cout << sum << '\n';
	}
}
