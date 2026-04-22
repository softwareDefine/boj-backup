#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <tuple>
#define inf 10000000

using namespace std;
using edge = tuple<int,int,int>;

class seg {
public:
	int arr[100100];
	int tree[1<<22];
	int construct(int start,int end,int node) {
		if(start == end){
			return tree[node] = arr[start];
		}
		int mid = (start + end) / 2;
		return tree[node] = max(construct(start, mid, node * 2), construct(mid + 1, end, node * 2 + 1));
	}
	int getMax(int start, int end,int left,int right, int node) {
		if (end < left || right < start) {
			return -inf;
		}
		if (left <= start && end <= right) {
			return tree[node];
		}
		int mid = (start + end) / 2;
		return max(getMax(start, mid, left, right, node * 2), getMax(mid + 1, end, left, right, node * 2 + 1));
	}
	void update(int start,int end,int node,int pos,int val) {
		if (pos < start || end < pos) {
			return;
		}
		if (start == end) {
			tree[node] = val;
			return;
		}
		int mid = (start + end) / 2;
		update(start, mid, node * 2, pos, val);
		update(mid + 1, end, node * 2 + 1, pos, val);
		tree[node] = max( tree[node * 2] , tree[node * 2 + 1]);
		return;
	}
};
class HLD {
public:
	void initalize(); // 초기화
	void update(int e, int k); // e번 간선의 가중치를 k로 갱신하는 연산
	int getMax(int u, int v); // 정점 u와 v사이의 경로에 속한 간선 중 최대 가중치 값
private:
	int n, c, dcnt; 
	int tSize[100100], dfsn[100100];
	vector<edge> adj[100100];
	vector<int> child[100100];
	int parent[100100], depth[100100], cn[100100];

	int eVertex[100100];
	int cHead[100100],cTail[100100];
	seg s1;
	void dfs1(int curr, int prev = -1);
	void dfs2(int curr, int prev = -1, int currDepth = 0);
};

void HLD::dfs1(int curr, int prev) {
	tSize[curr] = 1;
	for (auto p : adj[curr]) {
		int next, d, en;
		tie(next, d, en) = p;
		if (next != prev) {
			dfs1(next, curr);
			child[curr].push_back(next);
			tSize[curr] += tSize[next];
		}
	}
}

void HLD::dfs2(int curr, int prev, int currDepth) {
	int u = dfsn[curr] = dcnt++;
	cn[u] = c;
	depth[u] = currDepth;
	if (cHead[c] < 0) cHead[c] = u;
	cTail[c] = u;
	if (child[curr].empty()) {
		++c;
		return;
	}

	int chained = child[curr][0];
	for (int i = 1; i < child[curr].size(); i++) {
		int next = child[curr][i];
		if (tSize[chained] < tSize[next]) chained = next;
	}
	dfs2(chained, curr, currDepth + 1);
	parent[dfsn[chained]] = u;
	for (int next : child[curr]) {
		if (next != chained) dfs2(next, curr, currDepth + 1);
		int v = dfsn[next];
		parent[v] = u;
	}
}

void HLD::initalize() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		--u; --v;
		adj[u].push_back(edge(v, w, i));
		adj[v].push_back(edge(u, w, i));
	}
	dfs1(0);
	c = dcnt = 0;
	fill(cHead, cHead + 100100, -1);
	fill(cTail, cTail + 100100, -1);
	parent[0] = -1;
	dfs2(0);

	for (int curr = 0; curr < n; curr++) {
		int u = dfsn[curr];
		for (auto& e : adj[curr]) {
			int next, d, en;
			tie(next, d, en) = e;
			int v = dfsn[next];
			if (depth[u] < depth[v]) {
				eVertex[en] = v;
				s1.arr[v] = d;
			}
		}
	}
	s1.construct(0,n-1,1);
}

void HLD::update(int e, int k) {
	s1.update(0,n-1,1,eVertex[e], k);
}

int HLD::getMax(int u, int v) {
	int result = -inf;
	u = dfsn[u];
	v = dfsn[v];

	if (cn[u] != cn[v]) {
		while (1) {
			int uHead = cHead[cn[u]], vHead = cHead[cn[v]];
			if (depth[uHead] > depth[vHead]) {
				result = max(s1.getMax(0,n-1,uHead, u ,1), result);
				u = parent[uHead];
			}
			else {
				result = max(s1.getMax(0,n-1,vHead, v ,1), result);
				v = parent[vHead];
			}
			if (cn[u] == cn[v]) break;
			//cout << "결과 :" << result << '\n';
		}
	}
	result = max(s1.getMax(0,n-1,min(u, v) , max(u, v),1),result);

	//cout << "결과 :" << result << '\n';
	return result;
}

HLD h1;
int q;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	h1.initalize();
	cin >> q;
	for (int i = 0; i < q; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			h1.update(b, c);
		}
		else {
			cout << h1.getMax(--b, --c) << '\n';
		}
	}
}