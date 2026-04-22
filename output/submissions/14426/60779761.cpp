#include <iostream>
#include <vector>

using namespace std;
int ans;
int n,m;
string str;

struct node {
	int children[26];
	bool valid;
	node() {
		for (int i = 0; i < 26; i++) { children[i] = -1; }
		valid = false;
	}
};

vector<node> vc;
int root;

int init() {
	node x;
	vc.push_back(x);
	return vc.size() - 1;
}

void add(int node, string& s, int index) {
	if (index == s.length()) { vc[node].valid = true; return; }
	int c = s[index] - 'a';
	if (vc[node].children[c] == -1) {
		int next = init();
		vc[node].children[c] = next;
	}
	int child = vc[node].children[c];
	//cout << char(c+'a') << child << ' ';
	add(child, s, index + 1);
}

bool search(int node,string &s,int index) {
	if(node == -1){return false;}
	if (index == s.length()) { return true; }
	int c = s[index] - 'a';
	int child = vc[node].children[c];
	//cout << char(c + 'a') << child << ' ';
	return search(child, s, index + 1);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	root = init();
	for(int i=0;i<n;i++){
		cin >> str;
		add(root, str, 0);
		//cout << '\n';
	}
	for (int i = 0; i < m; i++) {
		cin >> str;
		ans += search(root, str, 0);
		//cout << '\n';
	}
	cout << ans;
}