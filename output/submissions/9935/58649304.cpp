#include <iostream>
#include <stack>
#include <vector>

using namespace std;

string str;
string ptr;
stack<char> st;
vector<char> vc;
int cnt = 0;

int main()
{
	cin >> str;
	cin >> ptr;
	for (int i = 0; i < str.size(); i++) {
		st.push(str[i]);
		if (!st.empty() && st.top() == ptr[ptr.size()-1]) {
			int cnt = 0;
			bool flag = 0;
			for (int i = 0; i < ptr.size(); i++) {
				if (!st.empty() && ptr[ptr.size()-cnt - 1]==st.top()) {
					st.pop();
					cnt++;
				}
				else {
					flag = 1;
				}
			}
			if (flag) {
				for (int i = ptr.size() - cnt - 1; i < ptr.size(); i++) {
					st.push(ptr[i]);
				}
			}
		}
	}
	if (st.empty()) {
		cout << "FRULA";
	}
	else {
		while (!st.empty()) {
			vc.push_back(st.top());
			st.pop();
		}
	}
	reverse(vc.begin(), vc.end());
	for (auto& i : vc) {
		cout << i;
	}
}