#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n;

vector<string> vc;

int cmp(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	return a.length() < b.length();
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		if (find(vc.begin(), vc.end(), temp) == vc.end()) {
			vc.push_back(temp);
		}
	}
	sort(vc.begin(), vc.end(), cmp);
	int szze=vc.size();
	for (int i = 0; i < szze; i++) {
		cout << vc[i] << '\n';
	}
}