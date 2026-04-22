#include <iostream>
#include <vector>

using namespace std;
constexpr int szze = 1 << 17;
int n, q;
int in[1000010];
vector<int> vc[1000010];
int out[1000010];
int tree[szze << 1];
int cnt = 0;


//레이지 세그를 모르는 상태라 강의자료를 참고함 추후 레이지로 바꿀 예정
void add(int l, int r, int v) {
	for (l |= szze, r |= szze; l <= r; l >>= 1, r >>= 1) {
		if (l & 1) tree[l++] += v;
		if (~r & 1) tree[r--] += v;
	}
}

int get(int x) {
	int ret = 0;
	for (x |= szze; x; x >>= 1) { ret += tree[x]; }
	return ret;
}

void dfs(int v) {
	in[v] = ++cnt;
	for (auto i : vc[v]) {
		dfs(i);
	}
	out[v] = cnt;
	//cout << v << ' ' << in[v] << ' ' << out[v] << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		vc[max(0,p)].push_back(i);
	}
	dfs(1);
	for (int i = 1; i <= q; i++) {
		int a;
		cin >> a;
		if (a == 1) {
			int b, c;
			cin >> b >> c;
			add(in[b], out[b], c);
		}
		else {
			int b;
			cin >> b;
			cout << get(in[b]) << '\n';
		}
	}
}