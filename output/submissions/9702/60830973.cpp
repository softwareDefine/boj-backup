#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

int t;
int n;
ll sum;
vector<int> vc;
int arr[100010];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> t;
	for (int al = 1; al <= t; al++) {
		vc.clear();
		sum = 0;
		for (int i = 0; i < n; i++) {
			arr[i] = 0;
		}
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < n; i++) {
			vc.clear();
			for (int j = i; j < n; j++) {
					if (vc.empty()) {
						vc.push_back(arr[j]);
					}
					else {
						if (vc.back() < arr[j]) {
							vc.push_back(arr[j]);
						}
						else {
							int index = lower_bound(vc.begin(), vc.end(), arr[j]) - vc.begin();
							vc[index] = arr[j];
						}
					}sum += vc.size();
				}
			}
		cout << "Case #" << al << ": " << sum << '\n';
		}
	}
	