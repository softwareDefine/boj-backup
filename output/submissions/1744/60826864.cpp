#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long n;
long long sum;
long long sum2;
long long cnt;
long long arr[1000010];
long long arr2[1000010];
vector<int> minuus;
vector<int> pluus;

long long cmp(long long a, long long b) {
	return a > b;
}
long long cmp2(long long a, long long b) {
	return a < b;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a <= 0) {
			minuus.push_back({a});
		}
		else if (a == 1) {
			cnt++;
		}
		else {
			pluus.push_back({ a });
		}
	}
	sort(minuus.begin(), minuus.end(),cmp2);
	sort(pluus.begin(), pluus.end(),cmp);
	if (minuus.size() % 2 == 0) {
		for (int i = 0; i < minuus.size(); i += 2) {
			sum += max(minuus[i] * minuus[i + 1], minuus[i] + minuus[i + 1]);
		}
	}
	else {
		for (int i = 0; i < minuus.size(); i += 2) {
			if (i == minuus.size()-1) {
				sum += minuus[i];
				continue;
			}
			sum += max(minuus[i] * minuus[i + 1], minuus[i] + minuus[i + 1]);
		}
	}
	if (pluus.size() % 2 == 0) {
		for (int i = 0; i < pluus.size(); i += 2) {
			sum += max(pluus[i] * pluus[i + 1], pluus[i] + pluus[i + 1]);
		}
	}
	else {
		for (int i = 0; i < pluus.size(); i += 2) {
			if (i == pluus.size() - 1) {
				sum += pluus[i];
				continue;
			}
			sum += max(pluus[i] * pluus[i + 1], pluus[i] + pluus[i + 1]);
		}
	}
	cout << sum+cnt;
}