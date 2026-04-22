#include <iostream>
#include <vector>

using namespace std;

int n,a,b;
string str;
vector<char> vc;
int main()
{
	cin >> n;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (vc.empty()) {
			vc.push_back(str[i]);
			continue;
		}
		if (vc.back() == str[i]) {
			continue;
		}
		vc.push_back(str[i]);
		if (str[i] == 'R') { a++; }
		else { b++; }
	}
	cout << min(a, b);
}