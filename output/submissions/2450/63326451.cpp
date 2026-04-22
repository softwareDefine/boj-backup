#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector<int> brr;
int n;
int arr[100010];
int chk[4];
int sum, mmn = 9999999;
vector<tuple<int, int, int>> vc;
int go[4][4];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			for (int k = 1; k < 4; k++) {
				if (i == j || j == k || i == k) {
					continue;
				}
				vc.push_back({ i, j, k });
			}
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		chk[arr[i]]++;
	}
	for (int t = 0; t < 6; t++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				go[i][j] = 0;
			}
		}
		sum = 0;
		brr.clear();
		for (int i = 0; i < chk[get<0>(vc[t])]; i++) {
			brr.push_back(get<0>(vc[t]));
		}
		for (int i = 0; i < chk[get<1>(vc[t])]; i++) {
			brr.push_back(get<1>(vc[t]));
		}
		for (int i = 0; i < chk[get<2>(vc[t])]; i++) {
			brr.push_back(get<2>(vc[t]));
		}
		for (int i = 0; i < n; i++) {
			go[brr[i]][arr[i]]++;
		}
		int temp = min(go[1][2], go[2][1]);
		go[1][2] -= temp;
		go[2][1] -= temp;
		sum += temp;
		temp = min(go[2][3], go[3][2]);
		go[2][3] -= temp;
		go[3][2] -= temp;
		sum += temp;
		temp = min(go[1][3], go[3][1]);
		go[1][3] -= temp;
		go[3][1] -= temp;
		sum += temp;
		sum += go[2][1] + go[3][1] + go[3][2] + go[1][2] + go[2][3] + go[1][3];
		mmn = min(sum, mmn);
	}
	cout << mmn;
}