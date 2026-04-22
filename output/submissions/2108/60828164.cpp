#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

int n;
int arr[1000100];
int sum = 0;
int check[1000100];
int mmx = -9999999;
int mmx2 = -9999999;
int mmn = 9999999;
int idx;
map<int, int> mp;
vector<int> vc;
int cmp(int a, int b) {
	return a > b;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mmx = max(mmx, arr[i]);
		mmn = min(mmn, arr[i]);
		sum += arr[i];
		check[arr[i]+5000]++;
		if (mp.find(arr[i]) != mp.end()) {
			mp[arr[i]]++;
		}
		else {
			mp.insert({arr[i],0});
		}
	}
	sort(arr, arr + n);
	if (round((float)sum / n) == -0) {
		cout << "0" << '\n';
	}
	else {
		cout << round((float)sum / n) << '\n';
	}
	cout << arr[n / 2] << '\n';
	for (auto i : mp) {
		if (i.second > mmx2) {
			mmx2 = max(mmx2, i.second);
			while (!vc.empty()) {
				vc.pop_back();
			}
			vc.push_back(i.first);
		}
		else if (i.second == mmx2) {
			mmx2 = max(mmx2, i.second);
			vc.push_back(i.first);
		}
	}
	sort(vc.begin(), vc.end());
	if (vc.size()<=1) {
		 cout << vc[0] << '\n';
	}
	else {
		cout << vc[1] << '\n';
	}
	cout << mmx - mmn << '\n';
	
}