#include <iostream>
long long seg[4000010];
long long arr[1000010];
//int lazy[100000];
long long n, m, k;
using namespace std;
long long create(int ni,int ns, int ne ) {
	if (ns == ne) {
		return seg[ni] = arr[ne];
	}
	int nm = (ns + ne) / 2;
	return seg[ni] = create(ni * 2, ns, nm) + create(ni * 2 + 1, nm + 1, ne);
}
void update(int ni, int ns, int ne, int qi, long long qx) {
	if (qi < ns || ne < qi) {
		return;
	}
	if (ns == ne) {
		seg[ni] = qx;
		return;
	}
	int nm = (ns + ne) / 2;
	update(ni * 2, ns, nm, qi, qx);
	update(ni * 2 + 1, nm + 1, ne, qi, qx);
	seg[ni] = seg[ni * 2] + seg[ni * 2 + 1];
}
long long query(int ni, int ns, int ne, int qs, int qe) {
	if (qe < ns || ne < qs) {
		return 0;
	}
	if (qs <= ns && ne <= qe) {
		return seg[ni];
	}
	int nm = (ns + ne) / 2;
	return  query(ni * 2, ns, nm, qs, qe) + query(ni * 2 + 1, nm + 1, ne, qs, qe);
}
int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin >> n >> m >> k;
	for (long long i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	create(1,1,n);
	for (long long i = 1; i <= m+k; i++) {
		long long a,b,c;
		cin >> a >> b >>c;
		if (a == 1) {
			update(1,1,n, b, c);
		}
		else {
			cout << query(1,1,n,b,c) << "\n";
		}
	}
}