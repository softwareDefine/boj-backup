#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
int query[100010];
stack<int> st;
int flag = 0;
vector<char> vc;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> query[i];
	}
	int j = 1;
	int nowindex = 1;
	for (int i = 1; i <= n; i++) {
		if (flag == 1) {
			break;
		}
		if (i!=1&& !st.empty() && query[i] == st.top() && !flag) {
			if (st.empty()) {
				flag = 1;
				cout << "NO";
				break;
			}
			if (flag) {
				break;
			}
			vc.push_back('-');
			st.pop();
		}
		else {
			while (1) {
				st.push(j);
				vc.push_back('+');
				if (j > query[i]) {
					cout << "NO";
					flag = 1;
					break;
				}
				if (query[i] == j) {
					j++;
					break;
				}
				j++;
			}
			if (flag) {
				break;
			}
			if (st.empty()) {
				flag = 1;
				cout << "NO";
				break;
			}
			st.pop();
			vc.push_back('-');
		}
	}
	if (!flag) {
		for (int i = 0; i < vc.size(); i++) {
			cout << vc[i] << '\n';
		}
	}
}