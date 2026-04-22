#include <bits/stdc++.h>

using namespace std;

string str;
int n;
int s;
int found;
string key[200];
int corr[200][200];
int nxt[200];

/*void go(int start,int j) {
	if(found) {
		return;
	}
	if(start >= str.length()) {
		found =1;
		cout << 1;
		return;
	}
	if(corr[j][start] != -1 && corr[j][start]-start == key[j].length()) {
		for(int i=0; i<n; i++) {
			go(corr[j][start],i);
		}
	}
}*/

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> str;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> key[i];
	}
	for(int j=0; j<n; j++) {
		for(int i=0; i<str.length(); i++) {
			int flag = -1;
			for(int k=0; k<key[j].length(); k++) {
				if(i+k < str.length() && str[i+k] == key[j][k]) {
					flag = i+k+1;
				} else {
					break;
				}
			}
			corr[j][i] = flag;
		}
	}
	nxt[0] = 1;
	for(int j=0; j<n; j++) {
		for(int i=0; i<str.length(); i++) {
			if(nxt[i] && key[j][i] != -1 && corr[j][i]-i == key[j].length()) {
                nxt[corr[j][i]] = 1;
			}
		}
	}
	cout << nxt[str.length()];
}