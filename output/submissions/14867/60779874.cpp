#include <iostream>
#include <set>
#include <queue>

using namespace std;
set<pair<int, int>> st;
int a, b, c, d;
int flag = 0;
queue<pair<pair<int, int>,int>> qu;
int main()
{
	cin >> a >> b >> c >> d;
	qu.push({ {0,0 }, 0});
	while (!qu.empty()) {
		int x = qu.front().first.first;
		int y = qu.front().first.second;
		int cnt = qu.front().second;
		qu.pop();
		if (x == c && y == d) {
			cout << cnt << '\n';
			flag = 1;
			break;
		}
		if (x != 0) {
			if (st.find({ 0,y }) == st.end()) {
				qu.push({ {0, y} ,cnt + 1 });
				st.insert({ 0,y });
			}
		}
		if (y != 0) {
			if (st.find({ x,0 }) == st.end()) {
				qu.push({ {x, 0} ,cnt + 1 });
				st.insert({ x,0 });
			}
		}
		if (x != a) {
			if (st.find({ a,y }) == st.end()) {
				qu.push({ {a, y} ,cnt + 1 });
				st.insert({ a,y });
			}
		}
		if (y != b) {
			if (st.find({ x,b }) == st.end()) {
				qu.push({ {x,b} ,cnt + 1 });
				st.insert({ x,b });
			}
		}
		if (x + y >= b) {
			if (st.find({ x + y - b, b }) == st.end()) {
				qu.push({ {x + y - b, b} ,cnt + 1 });
				st.insert({ x + y - b, b });
			}
		}
		else {
			if (st.find({ 0,x + y }) == st.end()) {
				qu.push({ { 0,x + y } ,cnt + 1 });
				st.insert({ 0,x + y });
			}
		}
		if (x + y >= a) {
			if (st.find({ a, x + y - a }) == st.end()) {
				qu.push({ {a, x + y - a} ,cnt + 1 });
				st.insert({ a, x + y - a });
			}
		}
		else {
			if (st.find({ x + y ,0 }) == st.end()) {
				qu.push({ { x + y ,0} ,cnt + 1 });
				st.insert({ x + y ,0 });
			}
		}
	}
	if(!flag){
		cout << -1;
	}
}