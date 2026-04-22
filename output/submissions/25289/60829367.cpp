#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[1000010];
int lis[1000010];
int mmx;
int sum;
vector<int> li;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = -100; i <= 100; i++) {
		for (int j = 0; j < 1000010; j++) {
			lis[j] = 0;
		}
		for (int j = 0; j < n; j++) {
			lis[i + arr[j]+1000]=lis[arr[j]+ 1000]+1;
		}
		for (int j = 0; j < 1000010; j++) {
			mmx = max(lis[j], mmx);
		}
	}
	cout << mmx;
}