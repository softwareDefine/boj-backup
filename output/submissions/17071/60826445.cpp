#include <iostream>
#include <queue>

using namespace std;
long long visited[500101][2];
long long mmn = 9999;
long long mmnk = 9999;
long long start, dest;
long long  cnt2;

void bfs(long long start) {
	queue<pair<pair<long long, long long>, long long>> qu;	qu.push({ { start,0 },0 });
	visited[start][0] = 1;
	while (!qu.empty()) {
		long long x = qu.front().first.first;
		long long cnt = qu.front().first.second;
		long long k = qu.front().second;
		qu.pop();
		cnt2++;
		if (dest + (cnt * (cnt + 1) / 2) > 500000 || cnt > mmn) {
			continue;
		}
		if (dest + (cnt * (cnt + 1) / 2) == x || visited[dest + (cnt * (cnt + 1) / 2)][cnt%2]) {
			//cout << cnt << ' ' << k << '\n';
			mmn = min(cnt, mmn);
			break;
		}
		if (2 * x <= 500000 && !visited[x * 2][(cnt + 1) % 2] && dest + ((cnt + 1) * (cnt + 2) / 2) <= 500000 && cnt + 1 < mmn) {
			visited[x*2][(cnt + 1) % 2] = 1;
			qu.push({ { 2 * x,cnt + 1 },k + 1 });
		}
		if (x - 1 >= 0 && !visited[x - 1][(cnt + 1) % 2] && dest + ((cnt + 1) * (cnt + 2) / 2) <= 500000 && cnt + 1 < mmn) {
			visited[x-1][(cnt + 1) % 2] = 1;
			qu.push({ { x - 1,cnt + 1 },k + 1 });
		}
		if (x + 1 <= 500000 && !visited[x + 1][(cnt+1)%2] && dest + ((cnt + 1) * (cnt + 2) / 2) <= 500000 && cnt + 1 < mmn) {
			visited[x+1][(cnt+1) % 2] = 1;
			qu.push({ { x + 1,cnt + 1 },k + 1 });
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> start >> dest;
	bfs(start);
	if (mmn == 9999) { cout << "-1"; }
	else { cout << mmn; }
}