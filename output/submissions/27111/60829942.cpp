#include <iostream>
#include <set>

using namespace std;

int n;
int cnt;
set<pair<int,int>> st;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
			int b;
		cin >> a >> b;
		if (b == 0) {
			if (st.find({ a,1 }) == st.end()) {
				cnt++;
			}
			else {
				st.erase({ a,1 });
			}
		}
		else {
			if (st.find({ a,1 }) != st.end()) {
				cnt++;
			}
			else {
				st.insert({ a,1 });
			}
		}
	}
	cnt += st.size();
	cout << cnt;
}