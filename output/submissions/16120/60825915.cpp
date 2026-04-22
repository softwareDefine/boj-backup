#include <iostream>
#include <stack>

using namespace std;
stack<char> st;
string str;

int main()
{
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (st.size() < 3) {
			st.push(str[i]);
			continue;
		}
		int chk = 0;
		if (str[i] == 'P') {
			if (st.top() == 'A') {
				st.pop();
				if (st.top() == 'P') {
					st.pop();
					if (st.top() == 'P') {
						chk = 1;
					}
					if (!chk) {
						st.push('P');
					}
				}
				if (!chk) {
					st.push('A');
				}
			}
			if (!chk) {
				st.push('P');
			}
		}
		else {
			st.push('A');
		}
	}
	if (st.top() == 'P' && st.size()==1) {
		cout << "PPAP";
	}
	else {
		cout << "NP";
	}
}