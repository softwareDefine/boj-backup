#include <iostream>
#include <stack>
#include <string>

using namespace std;

int n;
int now;
int mmx;
int nmmx;
int cnt;
bool index[1000001];
string str;
stack<pair<char,int>> st;
int main()
{
	cin >> n;
	cin >> str;
	for (int i = 0; i < n; i++) {
		if (st.empty()) {
			st.push({ str[i] ,i});
		}
		else {
			if (st.top().first == '(') {
				if (str[i] == ')') {
					index[st.top().second] = true;
					index[i] = true;
					st.pop();
				}
				else {
					st.push({ str[i] ,i });
				}
			}
			else {
				st.push({ str[i],i });
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (index[i] == true) {
			cnt++;
		}
		else {
			cnt = 0;
		}
		mmx = max(cnt, mmx);
	}
	cout << mmx;
}