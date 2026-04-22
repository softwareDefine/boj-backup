#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
#define inf 1000101010

using namespace std;
using ll = long long;
int q;
class seg {
private :
	ll tree[1 << 22];
public : 
	ll arr[200010];
	ll update(ll start,ll end,ll node,ll pos) {
		if (pos < start || end < pos) {
			return tree[node];
		}
		if (start == end) {
			return tree[node] = 1;
		}
		ll mid = (start + end) / 2;
		return tree[node] = max(update(start, mid, node * 2, pos),update(mid + 1, end, node * 2 + 1, pos));
	}
	ll query(ll start, ll end, ll left, ll right, ll node) {
		if (end < left || start > right) {
			return 0;
		}
		if (left <= start && end <= right) {
			return tree[node];
		}
		ll mid = (start + end) / 2;
		return max(query(start,mid,left,right,node*2),query(mid+1,end,left,right,node*2+1));
	}
};

class HLD {
public:
	void initalize();
	void update(ll u);
	ll query(ll u, ll v);
	ll parent[200010],dfsn[200010];
private:
	ll n, c, dcnt;
	ll tSize[200010];
	vector<ll> adj[200010];
	vector<ll> child[200010];
	ll depth[200010], cn[200010];
	ll cHead[200010], cTail[200010];
	seg s1;
	void dfs1(ll curr, ll prev = -1);
	void dfs2(ll curr, ll prev = -1, ll currDepth = 0);
};

void HLD::dfs1(ll curr, ll prev) {
	tSize[curr] = 1;
	for (auto& next : adj[curr]) {
		if (next != prev) {
			dfs1(next, curr); child[curr].push_back(next);
			tSize[curr] += tSize[next];
		}
	}
}

void HLD::dfs2(ll curr, ll prev, ll currDepth) {
	ll u = dfsn[curr] = dcnt++;
	cn[u] = c; depth[u] = currDepth;
	if (cHead[c] < 0) cHead[c] = u;
	cTail[c] = u;
	if (child[curr].empty()) {++c; return;}
	int chained = child[curr][0];
	for (int i = 1; i < child[curr].size(); i++) {
		int next = child[curr][i];		if (tSize[chained] < tSize[next]) chained = next;
	}
	dfs2(chained, curr, currDepth + 1);
	parent[dfsn[chained]] = u;
	for (auto &next : child[curr]) {
		if (next != chained) dfs2(next, curr, currDepth + 1);
		parent[dfsn[next]] = u;
	}
}

void HLD::initalize() {
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		ll a; cin >> a; a--;
		adj[a].push_back(i); adj[i].push_back(a);
	}
	 dfs1(0); c = dcnt = 0;
	fill(cHead, cHead + 200010, -1); fill(cTail, cTail + 200010, -1);
	parent[0] = -1; dfs2(0);
}

void HLD::update(ll u) {
	s1.update(0, n - 1, 1, dfsn[u]);
	//cout << "끊김: "<< dfsn[u];
}

ll HLD::query(ll u, ll v) {
	u = dfsn[u], v = dfsn[v];
	ll flag = 0;
	if (cn[u] != cn[v]) {
		while (1) {
			ll uHead = cHead[cn[u]], vHead = cHead[cn[v]];
			if (depth[uHead] > depth[vHead]) {
				flag = max(s1.query(0,n-1,uHead,u,1), flag);
				u = parent[uHead];
			}
			else {
				flag = max(s1.query(0,n-1,vHead,v,1), flag);
				v = parent[vHead];
			}
			if (cn[u] == cn[v]) break;
		}
	}
	flag = max(s1.query(0,n-1,min(u,v)+1,max(u,v),1), flag);
	return flag;
}

HLD h1;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	h1.initalize();
	for (int i = 0; i < q; i++) {
		ll a,b,c;
		cin >> a >> b >> c;
		--a; --b;
		if (c == 0) {
			cout << (h1.query(a, b)?"NO":"YES") << '\n';
		}
		else {
			ll chk = h1.query(a, b);
			if (!chk) {
				h1.update(a);
			}
			else {
				h1.update(b);
			}
			cout << (chk ? "NO" : "YES") << '\n';
		}
	}
}