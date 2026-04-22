#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n;
vector<long long> vc;

pair<long long,pair<long long, long long>>mmn = { 1000000100,{1000000100,1000000100}};

int main()
{
	cin >> n;
	for (long long i = 0; i < n; i++) {
		long long a;
		cin >> a;
		vc.push_back(a);
	}
	sort(vc.begin(), vc.end());
	for (long long i = 0; i < n; i++) {
		long long j = 0;
		long long k = vc.size() - 1;
		while (j < k) {
			if (j == i) {
				j++;
			}
			if (k == i) {
				k--;
			}
			if (abs(vc[i]+vc[j]+vc[k]) == 0) {
				mmn.first = vc[i];
				mmn.second.first = vc[j];
				mmn.second.second = vc[k];
				if (mmn.first <= mmn.second.first && mmn.first <= mmn.second.second) {
					cout << mmn.first << ' ';
					if (mmn.second.first <= mmn.second.second) {
						cout << mmn.second.first << ' ' << mmn.second.second;
					}
					else {
						cout << mmn.second.second << ' ' << mmn.second.first;
					}
				}
				else if (mmn.second.first <= mmn.second.first && mmn.second.first <= mmn.first) {
					cout << mmn.second.first << ' ';
					if (mmn.first <= mmn.second.second) {
						cout << mmn.first << ' ' << mmn.second.second;
					}
					else {
						cout << mmn.second.second << ' ' << mmn.first;
					}
				}
				else if (mmn.second.second <= mmn.second.first && mmn.second.second <= mmn.first) {
					cout << mmn.second.second << ' ';
					if (mmn.second.first <= mmn.first) {
						cout << mmn.second.first << ' ' << mmn.first;
					}
					else {
						cout << mmn.first << ' ' << mmn.second.first;
					}
				}
				return 0;
			}
			else if (vc[i] + vc[j] + vc[k] > 0) {
				if (abs(mmn.first+mmn.second.first + mmn.second.second) > abs(vc[i]+ vc[j] + vc[k])) {
					if (i != j && j != k && i != k) {
						mmn.first = vc[i];
						mmn.second.first = vc[j];
						mmn.second.second = vc[k];
					}
				}
				k--;
			}
			else if(vc[i]+vc[j]+vc[k]<0) {
				if (abs(mmn.first + mmn.second.first + mmn.second.second) > abs(vc[i] + vc[j] + vc[k])) {
					if (i != j && j != k && i != k) {
						mmn.first = vc[i];
						mmn.second.first = vc[j];
						mmn.second.second = vc[k];
					}
				}
				j++;
			}
		}
	}
	if (mmn.first <= mmn.second.first && mmn.first <= mmn.second.second) {
		cout << mmn.first << ' ';
		if (mmn.second.first <= mmn.second.second) {
			cout << mmn.second.first << ' '<< mmn.second.second;
		}
		else {
			cout << mmn.second.second << ' ' << mmn.second.first;
		}
	}
	else if (mmn.second.first <= mmn.second.first && mmn.second.first <= mmn.first) {
		cout << mmn.second.first << ' ';
		if (mmn.first <= mmn.second.second) {
			cout << mmn.first << ' ' << mmn.second.second;
		}
		else {
			cout << mmn.second.second << ' ' << mmn.first;
		}
	}
	else if (mmn.second.second <= mmn.second.first && mmn.second.second <= mmn.first) {
		cout << mmn.second.second<< ' ';
		if (mmn.second.first <= mmn.first) {
			cout << mmn.second.first << ' ' << mmn.first;
		}
		else {
			cout << mmn.first << ' ' << mmn.second.first;
		}
	}
}