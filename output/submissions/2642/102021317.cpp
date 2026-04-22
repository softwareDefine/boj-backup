#include<bits/stdc++.h>

using namespace std;

int arr[20][20];
int mp[7];

int *nxt[7][10];

void go(int i, int j, int pos, int before, int move) {
	if(i-1 >= 0 && arr[i-1][j]) {
		for(int a = 0; a < 4; a++) {
			if(nxt[pos][a][move] == before) {
				if(mp[nxt[pos][a][0]]) {
					if(arr[i-1][j] != mp[nxt[pos][a][0]]) {
						cout << 0;
						exit(0);
					}
				} else {
					mp[nxt[pos][a][0]] = arr[i-1][j];
					go(i-1, j, nxt[pos][a][0], pos, 2);
				}
				break;
			}
		}
	}
	if(j-1 >= 0 && arr[i][j-1]) {
		for(int a = 0; a < 4; a++) {
			if(nxt[pos][a][move] == before) {
				if(mp[nxt[pos][a][3]]) {
					if(arr[i][j-1] != mp[nxt[pos][a][3]]) {
						cout << 0;
						exit(0);
					}
				} else {
					mp[nxt[pos][a][3]] = arr[i][j-1];
					go(i, j-1, nxt[pos][a][3], pos, 1);
				}
				break;
			}
		}
	}
	if(j+1 < 6 && arr[i][j+1]) {
		for(int a = 0; a < 4; a++) {
			if(nxt[pos][a][move] == before) {
				if(mp[nxt[pos][a][1]]) {
					if(arr[i][j+1] != mp[nxt[pos][a][1]]) {
						cout << 0;
						exit(0);
					}
				} else {
					mp[nxt[pos][a][1]] = arr[i][j+1];
					go(i, j+1, nxt[pos][a][1], pos, 3);
				}
				break;
			}
		}
	}
	if(i+1 < 6 && arr[i+1][j]) {
		for(int a = 0; a < 4; a++) {
			if(nxt[pos][a][move] == before) {
				if(mp[nxt[pos][a][2]]) {
					if(arr[i+1][j] != mp[nxt[pos][a][2]]) {
						cout << 0;
						exit(0);
					}
				} else {
					mp[nxt[pos][a][2]] = arr[i+1][j];
					go(i+1, j, nxt[pos][a][2], pos, 0);
				}
				break;
			}
		}
	}
}

int main() {
	for(int i = 0; i < 6; i++) {
		for(int j = 0; j < 6 ; j++) {
			cin >> arr[i][j];
		}
	}
	nxt[1][0] = new int[4] {5, 2, 6, 4};
	nxt[1][1] = new int[4] {2, 6, 4, 5};
	nxt[1][2] = new int[4] {6, 4, 5, 2};
	nxt[1][3] = new int[4] {4, 5, 2, 6};
	nxt[2][0] = new int[4] {5, 3, 6, 1};
	nxt[2][1] = new int[4] {3, 6, 1, 5};
	nxt[2][2] = new int[4] {6, 1, 5, 3};
	nxt[2][3] = new int[4] {1, 5, 3, 6};
	nxt[3][0] = new int[4] {5, 4, 6, 2};
	nxt[3][1] = new int[4] {4, 6, 2, 5};
	nxt[3][2] = new int[4] {6, 2, 5, 4};
	nxt[3][3] = new int[4] {2, 5, 4, 6};
	nxt[4][0] = new int[4] {5, 1, 6, 3};
	nxt[4][1] = new int[4] {1, 6, 3, 5};
	nxt[4][2] = new int[4] {6, 3, 5, 1};
	nxt[4][3] = new int[4] {3, 5, 1, 6};
	nxt[5][0] = new int[4] {4, 3, 2, 1};
	nxt[5][1] = new int[4] {3, 2, 1, 4};
	nxt[5][2] = new int[4] {2, 1, 4, 3};
	nxt[5][3] = new int[4] {1, 4, 3, 2};
	nxt[6][0] = new int[4] {2, 3, 4, 1};
	nxt[6][1] = new int[4] {3, 4, 1, 2};
	nxt[6][2] = new int[4] {4, 1, 2, 3};
	nxt[6][3] = new int[4] {1, 2, 3, 4};
	for(int i = 0; i < 6; i++) {
		for(int j = 0; j < 6 ; j++) {
			if(arr[i][j] == 1) {
				go(i, j, 1, 5, 0);
				break;
			}
		}
	}
	cout << mp[3];
}