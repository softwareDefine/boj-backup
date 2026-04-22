#include <iostream>
#include <queue>

using namespace std;

int n, w, l;
int arr[100010];

int main()
{
	int sum = 0;
	queue<pair<int,int>> qu;
	cin >> n >> w >> l;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	int j = 1;
	int i = 0;
	for (;j <= n; i++) {
		if (!qu.empty() && qu.front().second == i - w) {
			sum -= qu.front().first;
			qu.pop();
		}
		if (sum+arr[j] <= l&& qu.size()+1 <= w) {
			qu.push({arr[j] ,i});
			sum += arr[j];
			j++;
		}
	}
	cout << i+w;
}