#include <iostream>
#include <vector>
#include <algorithm>

using ll = unsigned long long;
using namespace std;

typedef struct Cor {
	ll x1, y1, d1, x2, y2, d2;
}cora;

int arr[110][110][110];
ll n;
ll sum;
ll g;
vector<ll> corx;
vector<ll> cory;
vector<ll> cord;
vector<cora> vc;
int main()
{
	cin >> n >> g;
	for (int i = 0; i < n; i++) {
		ll x1, y1, d1, x2, y2, d2;
		cin >> x1 >> y1 >> d1 >> x2 >> y2 >> d2;
		corx.push_back(x1);
		corx.push_back(x2);
		cory.push_back(y1);
		cory.push_back(y2);
		cord.push_back(d1);
		cord.push_back(d2);
		vc.push_back({ x1,y1,d1,x2,y2,d2 });
	}
	sort(corx.begin(), corx.end());
	sort(cory.begin(), cory.end());
	sort(cord.begin(), cord.end());
	corx.erase(unique(corx.begin(), corx.end()), corx.end());
	cory.erase(unique(cory.begin(), cory.end()), cory.end());
	cord.erase(unique(cord.begin(), cord.end()), cord.end());
	for (int i = 0; i < n; i++) {
		vc[i].x1 = lower_bound(corx.begin(), corx.end(), vc[i].x1) - corx.begin();
		vc[i].x2 = lower_bound(corx.begin(), corx.end(), vc[i].x2) - corx.begin();
		vc[i].y1 = lower_bound(cory.begin(), cory.end(), vc[i].y1) - cory.begin();
		vc[i].y2 = lower_bound(cory.begin(), cory.end(), vc[i].y2) - cory.begin();
		vc[i].d1 = lower_bound(cord.begin(), cord.end(), vc[i].d1) - cord.begin();
		vc[i].d2 = lower_bound(cord.begin(), cord.end(), vc[i].d2) - cord.begin();
	}
	for (int i = 0; i < n; i++) {
		for (int j = vc[i].d1; j < vc[i].d2; j++) {
			for (int k = vc[i].y1; k < vc[i].y2; k++) {
				for (int z = vc[i].x1; z < vc[i].x2; z++) {
					arr[j][k][z] += 1;
				}
			}
		}
	}
	for (int i = 0; i < cord.size() - 1; i++) {
		for (int j = 0; j < cory.size() - 1; j++) {
			for (int k = 0; k < corx.size() - 1; k++) {
				if (arr[i][j][k] >= g) {
					sum += (cord[i + 1] - cord[i]) * (cory[j + 1] - cory[j]) * (corx[k + 1] - corx[k]);
				}
			}
		}
	}
	cout << sum;
}