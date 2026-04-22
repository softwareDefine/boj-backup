#include <bits/stdc++.h>
using namespace std;
using lint = long long;

struct Edge {
    lint next;   // to
    lint w;      // weight
    lint idx;    // edge index
};

struct FibNode {
    lint key;       // distance
    int v;          // vertex id
    int degree;
    bool mark;
    FibNode *parent, *child, *left, *right;
    FibNode(lint k, int _v)
        : key(k), v(_v), degree(0), mark(false),
          parent(nullptr), child(nullptr), left(this), right(this) {}
};

struct FibHeap {
    FibNode* mn = nullptr;
    size_t nNodes = 0;

    static void _addRight(FibNode* a, FibNode* b) {
        // insert node b to the right of a in circular doubly list
        b->left = a;
        b->right = a->right;
        a->right->left = b;
        a->right = b;
    }

    static void _removeFromList(FibNode* x) {
        x->left->right = x->right;
        x->right->left = x->left;
        x->left = x->right = x;
    }

    static void _mergeRootLists(FibNode*& a, FibNode* b) {
        if (!a) { a = b; return; }
        if (!b) return;
        // splice b into a
        FibNode* ar = a->right;
        FibNode* bl = b->left;
        a->right = b;
        b->left = a;
        ar->left = bl;
        bl->right = ar;
    }

    FibNode* insert(lint key, int v) {
        FibNode* x = new FibNode(key, v);
        _mergeRootLists(mn, x);
        if (!mn || x->key < mn->key) mn = x;
        ++nNodes;
        return x;
    }

    void _link(FibNode* y, FibNode* x) {
        // remove y from root list and make it a child of x
        _removeFromList(y);
        y->parent = x;
        if (!x->child) {
            x->child = y;
            y->left = y->right = y;
        } else {
            _addRight(x->child, y);
        }
        x->degree++;
        y->mark = false;
    }

    void _consolidate() {
        if (!mn) return;
        // upper bound on degree: log_phi(n) < 60 for n up to ~1e18, use 64
        const int MAXD = 64;
        vector<FibNode*> A(MAXD, nullptr);

        // collect root list nodes first (since we'll mutate the list)
        vector<FibNode*> roots;
        FibNode* cur = mn;
        if (cur) {
            do { roots.push_back(cur); cur = cur->right; } while (cur != mn);
        }

        for (FibNode* w : roots) {
            FibNode* x = w;
            int d = x->degree;
            while (A[d]) {
                FibNode* y = A[d];
                if (y == x) break;
                if (y->key < x->key) swap(x, y);
                _link(y, x);
                A[d] = nullptr;
                d++;
            }
            A[d] = x;
        }

        mn = nullptr;
        for (FibNode* x : A) {
            if (!x) continue;
            x->parent = nullptr;
            x->left = x->right = x;
            _mergeRootLists(mn, x);
            if (!mn || x->key < mn->key) mn = x;
        }
    }

    FibNode* extract_min() {
        FibNode* z = mn;
        if (!z) return nullptr;

        // add children of z to root list
        if (z->child) {
            vector<FibNode*> kids;
            FibNode* c = z->child;
            do { kids.push_back(c); c = c->right; } while (c != z->child);
            for (FibNode* x : kids) {
                x->parent = nullptr;
                _removeFromList(x);
                x->left = x->right = x;
                _mergeRootLists(mn, x);
            }
            z->child = nullptr;
        }

        // remove z from root list
        if (z->right == z) {
            mn = nullptr;
        } else {
            FibNode* next = z->right;
            _removeFromList(z);
            mn = next;
            _consolidate();
        }
        --nNodes;
        return z;
    }

    void _cut(FibNode* x, FibNode* y) {
        // remove x from y's child list
        if (y->child == x) {
            if (x->right == x) y->child = nullptr;
            else y->child = x->right;
        }
        _removeFromList(x);
        y->degree--;
        x->parent = nullptr;
        x->left = x->right = x;
        x->mark = false;
        _mergeRootLists(mn, x);
        if (!mn || x->key < mn->key) mn = x;
    }

    void _cascadingCut(FibNode* y) {
        FibNode* z = y->parent;
        if (z) {
            if (!y->mark) y->mark = true;
            else {
                _cut(y, z);
                _cascadingCut(z);
            }
        }
    }

    void decrease_key(FibNode* x, lint nk) {
        if (!x) return;
        if (nk > x->key) return; // ignore bad calls
        x->key = nk;
        FibNode* y = x->parent;
        if (y && x->key < y->key) {
            _cut(x, y);
            _cascadingCut(y);
        }
        if (!mn || x->key < mn->key) mn = x;
    }

    bool empty() const { return mn == nullptr; }

    ~FibHeap() {
        // (Optional) Leak-safe cleanup could be added; omitted for brevity.
    }
};

static const lint INF = (lint)4e18;

// -------- Problem specific ----------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    lint n, m;
    cin >> n >> m;

    vector<vector<Edge>> edge(n + 1);
    edge.reserve(n + 1);

    for (int i = 0; i < m; i++) {
        lint a, b, t;
        cin >> a >> b >> t;
        edge[a].push_back({b, t, i});
        edge[b].push_back({a, t, i});
    }

    auto dijkstra_with_ban = [&](lint banned_idx) -> lint {
        vector<lint> dist(n + 1, INF);
        vector<FibNode*> handle(n + 1, nullptr);

        FibHeap hp;
        for (int v = 1; v <= (int)n; ++v) {
            handle[v] = hp.insert(INF, v);
        }
        dist[1] = 0;
        hp.decrease_key(handle[1], 0);

        while (!hp.empty()) {
            FibNode* nd = hp.extract_min();
            if (!nd) break;
            int u = nd->v;
            lint du = nd->key;
            handle[u] = nullptr; // extracted
            if (du > dist[u]) { delete nd; continue; }
            if (u == n) { // 목적지 최단거리 확정되면 조기 종료 가능
                delete nd;
                break;
            }
            for (const auto& e : edge[u]) {
                if (e.idx == banned_idx) continue; // 금지 간선 스킵
                int v = (int)e.next;
                lint w = e.w;
                if (dist[v] > du + w) {
                    dist[v] = du + w;
                    if (handle[v]) {
                        hp.decrease_key(handle[v], dist[v]);
                    }
                }
            }
            delete nd;
        }
        return dist[n];
    };

    lint base = dijkstra_with_ban(-1);
    vector<lint> blocked(m, INF);

    for (int i = 0; i < m; i++) {
        blocked[i] = dijkstra_with_ban(i);
        if (blocked[i] >= INF/2) {
            cout << -1;
            return 0;
        }
    }

    lint ans = 0;
    for (int i = 0; i < m; i++) {
        ans = max(ans, blocked[i] - base);
    }
    cout << ans;
    return 0;
}
