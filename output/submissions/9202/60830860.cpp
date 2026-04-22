#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <iterator>

using ll = long long;
using namespace std;

int dx[3] = { -1,1,0 };
int dy[3] = { -1,1,0 };

struct node {
	int children[26];
	bool valid;
	int parent;
	char now;
	node() {
		valid = false;
		for (int i = 0; i < 26; i++) {
			children[i] = -1;
		}
		parent = 0;
		now = '\0';
	}
};

string chk;
string ans;
vector<node> vc;
map<string, int> mp;
int root;
int n, q;
int visited[500][500];
string str;
string ptr[5];
int mmxszze;
ll sum = 0;
int init() {
	node x;
	vc.push_back(x);
	return vc.size() - 1;
}
void add(int node,string &s,int index) {
	if (index == s.size()) { vc[node].valid = true; return; }
	int c = s[index] - 'A';
	if (vc[node].children[c] == -1) {
		int next = init();
		vc[node].children[c] = next;
		vc[next].parent = node;
		vc[next].now = c;
	}
	int chlid = vc[node].children[c];
	add(chlid, s, index + 1);
}
void initer(int tog);
void search(int x,int y,int node, char c, int index) {
	if (mmxszze < index) {
		return;
	}
	if (vc[node].valid == true)
	{
		chk.clear();
		stringstream ss;
		int parent = node;
		while (parent != 0) {
			ss << char(vc[parent].now + 'A');
			parent = vc[parent].parent;
		}
		chk = ss.str();
		reverse(chk.begin(), chk.end());
		mp[chk]++;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (dx[i] == 0 && dy[j] == 0) { continue; }
			int nx = x + dx[i];
			int ny = y + dy[j];
			//cout << dx[i] << ' ' << dy[j] << '\n';
			if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {
				int child = vc[node].children[ptr[nx][ny]-'A'];
				//cout << "실행중";
				if (child != -1 && visited[nx][ny]!=1) {
					visited[nx][ny] = 1;
					search(nx,ny,child, ptr[nx][ny], index + 1);
					visited[nx][ny] = 0;
				}
			}
		}
	}
}
void broot() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (vc[root].children[ptr[i][j] - 'A'] != -1) {
				visited[i][j] = 1;
				search(i, j, vc[root].children[ptr[i][j] - 'A'], ptr[i][j], 1);
				visited[i][j] = 0;
			}
			initer(0);
		}
	}
}
void initer(int tog) {
	if (tog == 1) {
		mp.clear();
		ans.clear();
		for (int i = 0; i < 4; i++) {
			ptr[i].clear();
		}
		mp.clear();
		sum = 0;
	}
	for (int i = 0; i <= 10; i++) {
		for (int j = 0; j <= 10; j++) {
			visited[i][j] = 0;
		}
	}
}
int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	root = init();
	vc[root].parent = -1;
	vc[root].now = '\0';
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		int ssze = str.size();
		mmxszze = max(mmxszze,ssze);
		add(root, str, 0);
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> ptr[j];
		}
		broot();
		for (auto& j : mp) {
			switch (j.first.size()) {
				case 3:
				case 4:
					sum += 1;
					break;
				case 5:
					sum += 2;
					break;
				case 6:
					sum += 3;
					break;
				case 7:
					sum += 5;
					break;
				case 8:
					sum += 11;
					break;
				default:
					break;
			}
			if (ans.empty() || (ans.size() == j.first.size())&&(ans > j.first) || ans.size()< j.first.size()) {
				ans = j.first;
			}
		}
		cout << sum << ' ';
		cout << ans;
		cout << ' ';
		cout << mp.size() << '\n';
		initer(1);
	}
}