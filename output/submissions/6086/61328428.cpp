#include <iostream>
#include <vector>
#include <queue>
#define inf 1000000000

using namespace std;

int n;

struct Edge {
	int to, c, f;
	Edge* dual;
	Edge() : Edge(-1,0){}
	Edge(int to1, int  c1) : to(to1), c(c1), f(0), dual(nullptr) {}
	int spare() {
		return c - f;
	}
	void addFlow(int f1) {
		f += f1;
		dual->f -= f1;
	}
};

inline int Ctol(char c) {
	if (c <= 'Z') return c - 'A';
	return c - 'a' + 26;
}

int main()
{
	int n;
	vector<Edge*> adj[52];
	cin >> n;
	for (int i = 0; i < n; i++) {
		char u, v;
		int w;
		cin >> u >> v >> w;
		u = Ctol(u); v = Ctol(v);
		Edge*e1 = new Edge(v, w),
			*e2 = new Edge(u, 0);
		e1->dual = e2;
		e2->dual = e1;
		adj[u].push_back(e1);
		adj[u].push_back(e2);
		adj[v].push_back(e1);
		adj[v].push_back(e2);
	}
	int total = 0,
	S = Ctol('A'),
	E = Ctol('Z');
	while (1) {
		int prev[52];
		Edge* path[52] = { 0 };
		fill(prev, prev + 52, -1);
		queue<int> qu;
		qu.push(S);
		while (!qu.empty() && prev[E] == -1) {
			int curr = qu.front();
			qu.pop();
			for (Edge* e : adj[curr]) {
				int next = e->to;
				if (e->spare() > 0 && prev[next] == -1) {
					qu.push(next);
					prev[next] = curr;
					path[next] = e;
					if (next==E) break;
				}
			}
		}
		if (prev[E] == -1) break;
		
		int flow = inf;
		for (int i = E; i != S; i = prev[i]) flow = min(flow, path[i]->spare());
		for (int i = E; i != S; i = prev[i]) path[i]->addFlow(flow);
		total += flow;
	}
	cout << total;
}