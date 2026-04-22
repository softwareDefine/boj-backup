#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int k;

vector<char> rel;
vector<int> vc;
vector<int> mmx;
vector<int> mmn;

int used[10];

int locked;

void go(int now, int idx) {
	if(idx == k) {
		mmx.clear();
		for(auto num : vc) {
    		if(!locked){
    		   mmn.push_back(num);
    		}
		    mmx.push_back(num);
		}
		locked = 1;
		return;
	}
	if(rel[idx] == '<') {
		for(int i = now+1; i <= 9; i++) {
			if(!used[i]) {
				used[i] = 1;
				vc.push_back(i);
				go(i, idx+1);
				vc.pop_back();
				used[i] = 0;
			}
		}
	} else {
		for(int i = 0; i < now; i++) {
			if(!used[i]) {
				used[i] = 1;
				vc.push_back(i);
				go(i, idx+1);
				vc.pop_back();
				used[i] = 0;
			}
		}
	}
}

int main() {
	cin >> k;
	rel.resize(k);
	for(auto &element : rel) {
		cin >> element;
	}
	for(int i = 0; i <= 9; i++) {
		used[i] = 1;
		vc.push_back(i);
		go(i, 0);
		vc.pop_back();
		used[i] = 0;
	}
	for(auto element : mmx){
	    cout << element;
	}
	cout << '\n';
	for(auto element : mmn){
	    cout << element;
	}
	cout << '\n';
	return 0;
}