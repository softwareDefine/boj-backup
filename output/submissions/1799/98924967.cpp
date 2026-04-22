#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int n;
int possible[20][20];
int checker[20][20];
int mmx,cnt;

void go(int i,int j) {
	if(i+j == n*2-2) {
		if(checker[i][j] == 0) {
			cnt++;
			mmx = max(mmx,cnt);
			cnt--;
		} else {
			mmx = max(mmx,cnt);
		}
		return;
	}
	if((!(possible[i][j]) || (checker[i][j]))) {
		if(i-1 < 0 || j+1 >= n) {
			if(i+j+1 >= n) {
				go(n-1,(i+j+1)%n + 1);
			} else {
				go(i+j+1,0);
			}
		} else {
			go(i-1,j+1);
		}
		return;
	}
	for(int a = 0; i+a <n && j+a < n; a++) {
		if(checker[i+a][j+a] == 0) {
			checker[i+a][j+a] = i*j+1;
		}
	}
	cnt++;
	if(i+j+1 >= n) {
		go(n-1,(i+j+1)%n + 1);
	} else {
		go(i+j+1,0);
	}
	cnt--;
	for(int a = 0; i+a <n && j+a < n; a++) {
		if(checker[i+a][j+a] == i*j+1) {
			checker[i+a][j+a] = 0;
		}
	}
	if(i-1 < 0 || j+1 >= n) {
		if(i+j+1 >= n) {
			go(n-1,(i+j+1)%n + 1);
		} else {
			go(i+j+1,0);
		}
	} else {
		go(i-1,j+1);
	}
}

int main() {
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> possible[i][j];
		}
	}
	go(0,0);
	cout << mmx;
}