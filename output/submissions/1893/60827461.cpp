#include <iostream>
#include <map>
#include <vector>
#include <string.h>

using namespace std;

int t;
string seq;
string ptr;
string str;
char ptrpr[50010];
map<char, int> mp;
vector<int> ans;
int fail[500010];

void preprocessing(string &ptr) {
	int n = ptr.size();
	int j = 0;
	for (int i = 1; i < n; i++) {
		while (j > 0 && ptr[i] != ptr[j]) { j = fail[j - 1]; }
		if (ptr[i] == ptr[j]) {
			fail[i] = ++j;
		}
		else {
			fail[i] = 0;
		}
	}
}

int kmp(string& str, char* ptrpr) {
	int cnt = 0;
	int n = str.size();
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && str[i] != ptrpr[j]) { j = fail[j - 1]; }
		if (str[i] == ptrpr[j]) {
			if (j == ptr.size() - 1) {
				cnt++;
				j = fail[j];
			}
			else {
				j++;
			}
		}
	}
	if (cnt >= 2 || !cnt) {
		return -1;
	}
	else {
		return 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> t;
	while (t--) {
		ans.clear();
		mp.clear();
		memset(fail, 0, sizeof(fail));
		memset(ptrpr, '\0', sizeof(ptrpr));
		cin >> seq;
		for (int i = 0; i < seq.size(); i++) {
			mp.insert({ seq[i],i });
		}
		cin >> ptr;
		preprocessing(ptr);
		cin >> str;
		for (int i = 0; i <= seq.size()-1; i++) {
			for (int j = 0; j < ptr.size(); j++) {
				ptrpr[j] = seq[(mp[ptr[j]]+i)%seq.size()];
			}
			int chk = kmp(str, ptrpr);
			if (chk != -1) {
				ans.push_back(i);
			}
		}
		if (!ans.size()) {
			cout << "no solution" << '\n';
			continue;
		}
		else if (ans.size() >= 2) {
			cout << "ambiguous: ";
		}
		else {
			cout << "unique: ";
		}
		for (auto a : ans) {
			cout << a << ' ';
		}
		cout << '\n';
	}
}