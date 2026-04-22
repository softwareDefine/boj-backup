#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int same;
long long s;
long long n;
long long sum =1;
map<char, long long> mp;
set<char> key;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	string arr;
	cin >> arr;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < 3; i++) {
		key.insert(arr[i]);
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		mp[str[0]]++;
	}
	if (key.size() == 1) {
		for (int i = 0; i < 3; i++) {
			sum *= mp[arr[i]] - i;
		}
		sum /= 6;
	}
	else if (key.size() == 2) {
		if (arr[0] == arr[1]) {
			sum *= mp[arr[0]] * (mp[arr[0]] - 1) / 2;
			sum *= mp[arr[2]];
		}
		else {
			sum *= mp[arr[1]] * (mp[arr[2]] - 1) / 2;
			sum *= mp[arr[0]];
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			sum *= mp[arr[i]];
		}
	}
	cout << sum;
}