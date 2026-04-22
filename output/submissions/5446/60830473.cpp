#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

struct node {
	bool valid;
	int children[160];
	vector<int> cnt;
	bool inerase;
	bool erased;
	node() {
		valid = false;
		inerase = false;
		for (int i = 0; i < 160; i++) {
			children[i] = -1;
		}
		erased = false;
	}
};

string str;
int root;
int n;
int m;
int t;
vector<node> vc;
vector<string> vcs;
int cnt;

int init() {
	node x;
	vc.push_back(x);
	return vc.size() - 1;
}

void add(int node, string& s, int index) {
	if (index == s.size()) {
		vc[node].valid = true; return;
	}
	int c = (int)s[index];
	if (vc[node].children[c] == -1) {
		int next = init();
		vc[node].children[c] = next;
		vc[node].cnt.push_back(next);
	}
	int child = vc[node].children[c];
	//cout << child << '\n';
	add(child, s, index+1);
}

void erase(int node, string& s, int index) {
	vc[node].inerase = true;
	int c = (int)s[index];
	int child = vc[node].children[c];
	//cout << child << '\n';
	if (child!=-1) {
		erase(child, s, index+1);
	}
}

int search(int node, string& s, int index) {
	if (vc[node].erased) { return 0; }
	if (index == s.size()) {
		if (vc[node].inerase == false) { vc[node].erased = true;  }return 1;
	}
	int c = (int)s[index];
	if (vc[node].inerase == false) {
		//cout << "실행";
		vc[node].erased = true;
		return 1;
	}
	int child = vc[node].children[c];
	//cout << (char)(c);
	return search(child, s, index + 1);
}

int main()
{
	cin >> t;
	while(t--) {
		vc.clear();
		vcs.clear();
		root = init();
		cnt = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> str;
			vcs.push_back(str);
			add(root ,str, 0);
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> str;
			erase(root, str, 0);
		}
		for (int i = 0; i < vcs.size(); i++) {
			cnt += search(root,vcs[i],0);
		}
		cout << cnt << '\n';
	}
}