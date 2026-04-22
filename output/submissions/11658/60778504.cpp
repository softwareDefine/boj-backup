#include <iostream>

using ll = long long;
using namespace std;

ll tree[4000][4000];
ll arr[1100][1100];
ll n,m;

ll queryX(ll i, ll j, ll start, ll end, ll leftx, ll rightx);
void updateX(ll i, ll j, ll start, ll end, ll idxi, ll idxj, ll var);
void makeX(ll i, ll j, ll start, ll end, ll starty, ll endy);


void makeY(ll i, ll start, ll end) {
	if (start == end) {
		makeX(i, 1, 0, n - 1, start,end);
		return;
	}
	ll mid = (start + end) / 2;
	makeY(i * 2, start, mid);
	makeY(i * 2 + 1, mid + 1, end);
	makeX(i, 1, 0, n - 1, start, end);
}

void makeX(ll i, ll j, ll start, ll end,ll starty,ll endy) {
	if (start == end) {
		if (starty == endy) {
			tree[i][j] = arr[starty][start];
		}
		else {
			tree[i][j] = tree[i*2][j] + tree[i*2+1][j];
		}
		return;
	}
	ll mid = (start + end) / 2;
	makeX(i, j * 2, start, mid,starty,endy);
	makeX(i, j * 2 + 1, mid + 1, end,starty,endy);
	tree[i][j] = tree[i][j * 2] + tree[i][j * 2 + 1];
}

void updateY(ll i, ll start, ll end, ll idxi, ll idxj, ll var) {
	if (idxi < start || end < idxi) {
		return;
	}
	if (start == end) {
		updateX(i, 1, 0, n-1, idxi, idxj, var);
		return;
	}
	ll mid = (start + end) / 2;
	updateY(i * 2, start, mid, idxi, idxj, var);
	updateY(i * 2 + 1, mid + 1, end, idxi, idxj, var);
	updateX(i, 1, 0, n-1, idxi, idxj, var);
}

void updateX(ll i, ll j, ll start, ll end, ll idxi, ll idxj, ll var) {
	if (idxj < start || end < idxj) {
		return;
	}
	if (start == end) {
		tree[i][j] += var;
		return;
	}
	ll mid = (start + end) / 2;
	updateX(i, j * 2, start, mid, idxi, idxj, var);
	updateX(i, j * 2 + 1, mid + 1, end, idxi, idxj, var);
	tree[i][j] = tree[i][j * 2] + tree[i][j * 2 + 1];
}

ll queryY(ll i, ll start,ll end,ll lefty, ll righty, ll leftx, ll rightx) {
	if (end < lefty || righty < start) {
		return 0;
	}
	if (lefty <= start && end <= righty) {
		return queryX(i, 1, 0, n-1, leftx, rightx);
	}
	ll mid = (start + end) / 2;
	return queryY(i * 2, start, mid, lefty, righty, leftx, rightx) + queryY(i * 2 + 1, mid + 1, end, lefty, righty, leftx, rightx);
}
ll queryX(ll i, ll j, ll start, ll end, ll leftx, ll rightx) {
	if (end <leftx || rightx < start) {
		return 0;
	}
	if (leftx<= start && end <= rightx) {
		return tree[i][j];
	}
	ll mid = (start + end) / 2;
	return queryX(i, j * 2, start, mid, leftx, rightx) + queryX(i, j * 2+1, mid+1, end, leftx, rightx);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	makeY(1, 0, n - 1);
	for (int i = 0; i < m; i++) {
		ll a;
		cin >> a;
		if (a == 1) {
			ll x1, y1, x2, y2;
			cin >> y1 >> x1 >> y2 >> x2;
			cout << queryY(1, 0, n - 1, y1-1, y2-1, x1-1, x2-1) << '\n';
		}
		else {
			ll x, y, var;
			cin >> y >> x >> var;
			updateY(1, 0, n - 1, y-1, x-1, var-arr[y-1][x-1]);
			arr[y-1][x-1] = var;
		}
	}
}