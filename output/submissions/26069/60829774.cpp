// a-292.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <set>

using ll = long long;
using namespace std;

ll n;
set<string> st;
int main()
{
	cin >> n;
	int i;
	int now;
	st.insert("ChongChong");
	for (i = 1; i <= n; i++) {
		string a, b;
		cin >> a >> b;
		if (st.find(a) != st.end()) {
			st.insert(b);
		}
		if (st.find(b) != st.end()) {
			st.insert(a);
		}
	}
	cout << st.size();
}