#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int n;
pair<lint,lint> arr[300000];
lint cnt;
lint total;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i].first;
	}
	for(int i=1; i<n; i++) {
		lint cnt = 0;
		if(arr[i-1].first > arr[i].first) {
			arr[i].second = arr[i-1].second;
			while(arr[i-1].first  > arr[i].first * pow(2,cnt)) {
				cnt++;
			}
			arr[i].second += (cnt);
		} else if(arr[i-1].first < arr[i].first) {
			arr[i].second = arr[i-1].second;
			while(arr[i-1].first * pow(2,cnt) <= arr[i].first ) {
				cnt++;
			}
			//cout << cnt;
			arr[i].second -= (cnt-1);
			arr[i].second = max(0LL,arr[i].second);
		} else {
            arr[i].second = arr[i-1].second;
		}
		//cout << arr[i].second << ' '; 
		total += arr[i].second;
	}
	//cout << '\n';
	cout << total;
}