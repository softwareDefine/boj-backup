#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int n;

int mp[2000][2000];

set<int> A;
set<int> B;

vector<int> tmp;

int main() {
	cin >> n;
	while(1) {
		int u, v;
		cin >> u >> v;
		if(u == v && v == -1) {
			break;
		}
		mp[u][v] = 1;
		mp[v][u] = 1;
	}
	if(n ==1 ){
	    cout << -1 << '\n';
	    return 0;
	}
	for(int i = 1; i <= n; i++) {
		tmp.clear();
		int nowGroup = -1;
		if(A.empty()) {
			A.insert(i);
			nowGroup = 0;
		}
		for(int j = 1; j <= n; j++) {
			if(i == j) {
				continue;
			}
			if(!mp[i][j]) {
				if(nowGroup == 0) {
					B.insert(j);
				} else if(nowGroup == 1) {
					A.insert(j);
				} else {
					tmp.push_back(j);
				}
			}
		}
		if(nowGroup == -1) {
			int used = 0;
			if(tmp.empty()) {
				A.insert(i);
				continue;
			}
			for(auto element : A) {
				if(!mp[element][tmp[0]]  && element != tmp[0]) {
					A.insert(i);
					used =1;
					break;
				}
			}
			for(auto element : B) {
				if(!mp[element][tmp[0]] && element != tmp[0]) {
					if(used) {
						cout << -1 << '\n';
						return 0;
					}
					B.insert(i);
					break;
				}
			}
		}
// 		for(auto element : A) {
// 			cout << element << ' ';
// 		}
// 		cout << "-1\n";
// 		for(auto element : B) {
// 			cout << element << ' ';
// 		}
// 		cout << "-1\n\n";
	}
	cout << 1 << '\n';
	for(auto element : A) {
		cout << element << ' ';
		if(B.empty() && element == 1){
		    cout << "-1\n";
		}
	}
	cout << "-1\n";
	if(!B.empty()){
	for(auto element : B) {
		cout << element << ' ';
	}
	cout << "-1\n";
	}
	return 0;
}