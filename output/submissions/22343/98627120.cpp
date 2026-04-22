#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint t;
stack<char> st;
string a, b;
int bigA[4000000] = {0, };
int bigB[4000000] = {0, };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--) {
		cin >> a >> b;
		lint suma = 0,sumb = 0;
		bool flag;
		lint weight = 0;
		lint mmxa = 0;
		lint mmxb = 0;
		bool added = 0;
		memset(bigA,0,sizeof(bigA));
		for(int i=0; i<a.size(); i++) {
			if(a[i] == '(') {
				weight++;
				mmxa = max(mmxa,weight);
				st.push('(');
				added = 0;
			}
			else if(a[i] == ')') {
				if(!st.empty() && st.top() == '(') {
					st.pop();
					if(!added) {
						bigA[weight] += 1;
						added = 1;
					}
					weight--;
				} else {
					break;
				}
			}
		}
		for(int i=0; i<4000000; i++) {
			bigA[i+1]+=bigA[i]/2;
			bigA[i]%=2;
		}
		weight = 0;
		memset(bigB,0,sizeof(bigB));
		for(int i=0; i<b.size(); i++) {
			if(b[i] == '(') {
				weight++;
				mmxb = max(mmxb,weight);
				st.push('(');
				added = 0;
			}
			else if(b[i] == ')') {
				if(!st.empty() && st.top() == '(') {
					st.pop();
					if(!added) {
						bigB[weight] += 1;
						added = 1;
					}
					weight--;
				} else {
					break;
				}
			}
		}
		for(int i=0; i<4000000; i++) {
			bigB[i+1]+=bigB[i]/2;
			bigB[i]%=2;
		}
		for(int i=max(mmxa,mmxb); i>=0; i--) {
			if(bigA[i] < bigB[i]) {
				cout << "<" << '\n';
				flag = 1;
				break;
			} else if(bigA[i] > bigB[i]) {
				cout << ">" << '\n';
				flag = 1;
				break;
			}
		}
		if(!flag){
		    cout << "=" << '\n';
		}
	}
}