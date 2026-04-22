#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
string str;
string ptr;
int t;
int n, m;
struct Node{
	int children[26];
	int cnt;
	int pi;
	Node() {
		cnt = 0;
		pi = -1;
		for (int i = 0; i < 26; i++) {
			children[i] = -1;
		}
	}
};
vector<Node> trie;
vector<string> vc;

int init() {
	Node x;
	trie.push_back(x);
	return (int)trie.size() - 1;
}

void add(string &s,int node,int idx) {
	if (idx == s.size()) {
		trie[node].cnt = 1;
		return;
	}
	int c = s[idx]-'A';
	if (trie[node].children[c] == -1) {
		int next = init();
		trie[node].children[c] = next;
	}
	add(s, trie[node].children[c], idx + 1);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> t;
	while (t--) {
		vc.clear();
		trie.clear();
		int root = init();
		cin >> n >> m;
		cin >> str;
		cin >> ptr;
		for (int i = 0; i <m; i++) {
			for (int j = i; j < m; j++) {
				string p = ptr;
				reverse(p.begin() + i, p.begin() + j + 1);
				vc.push_back(p);
			}
		}
		sort(vc.begin(), vc.end());
		vc.erase(unique(vc.begin(), vc.end()), vc.end());
		for (string& s : vc) {
			add(s, root, 0);
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
				trie[next].cnt += trie[pi].cnt;
				q.push(next);
			}
		}
		int ans = 0;
		int node = root;
		for (int i = 0; i < n; i++) {
			int c = str[i] - 'A';
			while (node != root && trie[node].children[c] == -1) {
				node = trie[node].pi;
			}
			if (trie[node].children[c] != -1) {
				node = trie[node].children[c];
			}
			ans += trie[node].cnt;
		}
		cout << ans << '\n';
	}
}