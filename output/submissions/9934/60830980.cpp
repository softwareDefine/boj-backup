#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> vc[100];
int n;
int arr[100010];
int base;

void work(int now,int depth,int mid) {
	//cout << arr[now] << '\n';
	if (mid == 1 || mid == base || depth == n-1) {
		vc[depth].push_back(arr[now]);
		return;
	}
	work(now-(mid+1)/2,depth + 1, (mid+1)/2);
	vc[depth].push_back(arr[now]);
	work(now+(mid+1)/2,depth + 1, (mid+1)/2);
}

int main()
{
	cin >> n;
	base = pow(2, n) - 1;
	for (int i = 1; i <=base; i++) { cin >> arr[i]; }
	work((base+1)/2,0, (base+1) / 2);
	for (int i = 0; i < n; i++) {
		for (auto& k : vc[i]) {
			cout << k << ' ';
		}
		cout << '\n';
	}
}