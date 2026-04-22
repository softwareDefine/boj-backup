#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const int inf = 10000000;

int n;
int minFactor[inf];

void era() {
	minFactor[0] = minFactor[1] = -1;
	for (long long i = 2; i <= 10000000; i++) {
		minFactor[i] = i;
	}
	for (long long i = 2; i*i <= 10000000; i++) {
		if (minFactor[i] == i) {
			for (int j = i * i; j <= 10000000; j += i) {
				if (minFactor[j] == j) {
					minFactor[j] = i;
				}
			}
		}
	}
}
vector<int> factor() {
	vector<int> result;
	int copy = n;
	while (copy > 1) {
		result.push_back(minFactor[copy]);
		copy /= minFactor[copy];
	}
	return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	era();
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> n;
		vector<int> result;
		result = factor();
		int szze = result.size();
		for (int j = 0; j < szze; j++) {
			cout << result[j] << " ";
		}
		cout << "\n";
	}
}