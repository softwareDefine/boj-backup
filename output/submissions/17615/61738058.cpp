#include <iostream>
#include <vector>

using namespace std;

int n,a,b;
int ans;
string str;
vector<char> vc, vc2;
int main()
{
	cin >> n;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		vc.push_back(str[i]);
		vc2.push_back(str[i]);
	}
	reverse(vc2.begin(), vc2.end());
	char chk = vc.back();
	while (!vc.empty() && vc.back() == chk) {
		vc.pop_back();
	}
	chk = vc2.back();
	while (!vc2.empty() && vc2.back() == chk) {
		vc2.pop_back();
	}
	for (int i = 0; i < vc.size(); i++) {
		if (vc[i] == 'R') {
			a++;
		}
		else {
			b++;
		}
	}
	ans = min(a, b);
	a = 0, b = 0;
	for (int i = 0; i < vc2.size(); i++) {
		if(vc2[i] == 'R'){
			a++;
		}
		else {
			b++;
		}
	}
	ans = min(ans, min(a, b));
	cout << ans;
}