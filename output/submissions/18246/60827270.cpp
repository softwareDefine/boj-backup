#include <iostream>

using ll = long long;
using namespace std;

ll n, m;
ll tree[6666][6666];
ll arr[1510][1510];
ll pre[1510][1510];
ll pre2[1510][1510];
ll queryX(ll i, ll j, ll startx, ll endx, ll leftx, ll rightx);
void makeX(ll i, ll j, ll startx, ll endx, ll starty, ll endy);


void makeY(ll i,ll starty,ll endy) {
	if (starty == endy) {
		 makeX(i, 1, 0, 1500, starty, endy);
		 return;
	}
	ll mid = (starty + endy) / 2;
	makeY(i * 2, starty, mid);
	makeY(i * 2 + 1, mid + 1, endy);
	makeX(i,1,0,1500,starty,endy);
}

void makeX(ll i, ll j, ll startx, ll endx, ll starty, ll endy) {
	if (startx == endx) {
		if (starty == endy) {
			tree[i][j] = pre2[starty][startx];
		}
		else {
			tree[i][j] = max(tree[i * 2][j], tree[i*2+1][j]);
		}
		return;
	}
	ll mid = (startx + endx) / 2;
	makeX(i, j*2, startx, mid, starty, endy);
	makeX(i, j * 2+1, mid+1, endx, starty, endy);
	tree[i][j] = max(tree[i][j * 2], tree[i][j * 2 + 1]);
}

ll queryY(ll i, ll starty, ll endy, ll lefty, ll righty, ll leftx, ll rightx) {
	if (endy < lefty || starty>righty) {
		return 0;
	}
	if (lefty<= starty && endy<=righty) {
		return queryX(i, 1, 0, 1500, leftx, rightx);
	}
	ll mid = (starty + endy) / 2;
	return max(queryY(i * 2, starty, mid, lefty, righty, leftx, rightx),queryY(i * 2 + 1, mid + 1, endy, lefty, righty, leftx, rightx));
}

ll queryX(ll i, ll j, ll startx, ll endx, ll leftx, ll rightx) {
	if (endx < leftx || startx>rightx) {
		return 0;
	}
	if (leftx <= startx && endx <= rightx) {
		return tree[i][j];
	}
	ll mid = (startx + endx) / 2;
	return max(queryX(i, j * 2, startx, mid, leftx, rightx), queryX(i, j * 2 + 1, mid + 1, endx, leftx, rightx));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		ll x1, x2, y1, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		arr[y1][x1] += 1;
		arr[y2][x2] += 1;
		arr[y1][x2] += -1;
		arr[y2][x1] += -1;
	}
	for (int i = 0; i <= 1500; i++) {
		for (int j = 0; j <= 1500; j++) {
			int k = (j - 1 < 0) ? 0 : pre[i][j - 1];
			pre[i][j] = arr[i][j] + k;
		}
	}
	for (int j = 0; j <= 1500; j++) {
		for (int i = 0; i <= 1500; i++) {
			int k = (i - 1 < 0) ? 0 : pre2[i - 1][j];
			pre2[i][j] = pre[i][j]+k;
		}
	}
	makeY(1, 0, 1500);
	for (int i = 0; i < m; i++) {
		ll  y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << queryY(1, 0, 1500, y1,y2-1,x1, x2-1) << '\n';
	}
}