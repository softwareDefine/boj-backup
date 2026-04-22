#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;

struct Node {
	int pi;
	bool valid;
	int children[26];
	Node() {
		for (int i = 0; i < 26; i++) {
			children[i] = -1;
		}
		valid = false;
		pi = -1;
	}
};;
vector<Node> trie;
vector<string> vc;

int init() {
	Node x;
	trie.push_back(x);
	return (int)trie.size() - 1;
}

void add(string& s, int node, int idx) {
	if (idx == s.size()) {
		trie[node].valid = true;
		return;
	}
	int c = s[idx] - 'a';
	if (trie[node].children[c] == -1) {
		int next = init();
		trie[node].children[c] = next;
	}
	add(s, trie[node].children[c], idx + 1);
}

int main()
{
	int root = init();
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		vc.push_back(str);
		add(vc[i], root, 0);
	}
	queue<int> q;
	trie[root].pi = root;
	q.push(root);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < 26; i++) {
			int next = trie[cur].children[i];
			if (next == -1) { continue; }
			if (cur == root) {
				trie[next].pi = root;
			}
			else {
				int x = trie[cur].pi;
				while (x != root && trie[x].children[i] == -1) {
					x = trie[x].pi;
				}
				if (trie[x].children[i] != -1) {
					x = trie[x].children[i];
				}
				trie[next].pi = x;
			}
			int pi = trie[next].pi;
			trie[next].valid |= trie[pi].valid;
			q.push(next);
		}
	}
	int m;
	cin >> m;
	while (m--) {
		string s;
		cin >> s;
		int node = root;
		bool ok = false;
		for (int i = 0; i < s.size(); i++) {
			int c = s[i] - 'a';
			while (node != root && trie[node].children[c] == -1) {
				node = trie[node].pi;
			}
			if (trie[node].children[c] != -1) {
				node = trie[node].children[c];

			}
			if (trie[node].valid) {
				ok = true;
			}
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
}