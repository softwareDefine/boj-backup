#include <iostream>

using namespace std;

long long n;
long long segment[4000010];
long long sum;

//node 노드 위치
// st ed 현재 함수가 담당하는 범위
// mmn mmx 구하고자하는 범위
//(1,n,1,x-1)
long long query(long long st, long long ed, long long node,long long mmn,long long mmx) {
	if (mmx < st || mmn > ed) {
		return 0;
	}
	if (mmn <=st && ed <=mmx) {
		return segment[node];
	}
	int med = (st+ed)/2;
	return query(st, med, node * 2, mmn, mmx) + query(med + 1, ed, node * 2 + 1, mmn, mmx);
}
//pos 바꾸고자 하는 값
//node 노드 위치
// st ed 구하고자 하는 범위
// (1,n,1,x)
long long update(long long st, long long ed, long long node, long long pos) {
	if (pos < st || ed  < pos) {
		return segment[node];
	}
	if (st == ed) {
		return segment[node] += 1;
	}
	int med = (st + ed) / 2;
	return segment[node] = update(st, med, node * 2, pos) + update(med + 1, ed, node * 2 + 1, pos);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		long long x;
		cin >> x;
		sum += x - 1 - query(1, n, 1,1, x-1);
		update(1, n, 1, x);
	}
	cout << sum;
}