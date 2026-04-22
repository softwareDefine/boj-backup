#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int root;
int n;
int t;
vector<string> str;
int ans;

struct node {
	bool valid;
	int children[26];
	int cnt;
	node() {
		for (int i = 0; i < 26; i++) {
			children[i] = -1;
		}
		valid = false;
		cnt = 0;
	}
};

vector<node> vc;

int init() {
	node x;
	vc.push_back(x);
	return vc.size() - 1;
}

void add(int node, string& s, int index) {
	if (index == s.size()) { vc[node].valid = true; return; }
	int c = s[index] - 'a';
	if (vc[node].children[c] == -1) {
		int alloc = init();
		vc[node].children[c] = alloc;
		vc[node].cnt++;
	}
	int child = vc[node].children[c];
	add(child,s,index+1);
}

int search(int node, string& s, int index,int cnt) {
	if (node == -1) { return -1; }
	if (index == s.size()) { return cnt; }
	int c = s[index]-'a';
	int child = vc[node].children[c];
	if (vc[node].cnt != 1 || node == 0 || vc[node].valid == true) {
		cnt++;
	}
	return search(child, s, index + 1,cnt);
}

int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(nullptr);
	//cout.precision(3);
	while (cin >> n) {
		ans = 0;
		str.clear();
		vc.clear();
		root = init();
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			str.push_back(s);
			add(root, s, 0);
		}
		for (int i = 0; i < n; i++) {
			ans += search(root, str[i], 0, 0);
		}
		printf("%.2f\n", (float)ans / n);
	}
}