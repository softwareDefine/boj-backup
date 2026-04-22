#include <bits/stdc++.h>

using namespace std;

int n;

int arr[10][30][30];
vector<int> vc[30];

int mmx;

void go(int now,int dir) {
	if(now == 6) {
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            mmx = max(mmx,arr[now-1][i][j]);
	        }
	    }
		return;
	}
	for(int i=0; i<30; i++) {
		vc[i].clear();
	}
	if(dir == 0) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(arr[now-1][i][j]) {
					vc[i].push_back(arr[now-1][i][j]);
				}
			}
		}
		for(int i=0; i<n; i++) {
			int point = 0;
			for(int j=0; j<vc[i].size(); j++) {
				if(j != vc[i].size()-1 && vc[i][j]== vc[i][j+1]) {
					arr[now][i][point++] = vc[i][j]*2;
					j++;
				}else{
                    arr[now][i][point++] = vc[i][j];
                }
			}
		}
	} else if(dir == 1) {
		for(int j=0; j<n; j++) {
			for(int i=0; i<n; i++) {
				if(arr[now-1][i][j]) {
					vc[j].push_back(arr[now-1][i][j]);
				}
			}
		}
		for(int j=0; j<n; j++) {
			int point = 0;
			for(int i=0; i<vc[j].size(); i++) {
				if(i != vc[j].size()-1 && vc[j][i] == vc[j][i+1]) {
					arr[now][point++][j] = vc[j][i]*2;
					i++;
				}else{
                    arr[now][point++][j] = vc[j][i];
                }
			}
		}
	} else if(dir == 2) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(arr[now-1][i][j]) {
					vc[i].push_back(arr[now-1][i][j]);
				}
			}
		}
		for(int i=0; i<n; i++) {
			int point = 0;
			for(int j=vc[i].size()-1; j>=0; j--) {
				if(j != 0 && vc[i][j]== vc[i][j-1]) {
					arr[now][i][point++] = vc[i][j]*2;
					j--;
				}else{
                    arr[now][i][point++] = vc[i][j];
                }
			}
		}
	} else {
		for(int j=0; j<n; j++) {
			for(int i=0; i<n; i++) {
				if(arr[now-1][i][j]) {
					vc[j].push_back(arr[now-1][i][j]);
				}
			}
		}
		for(int j=0; j<n; j++) {
			int point = 0;
			for(int i=vc[j].size()-1; i>=0; i--) {
				if(i != 0 && vc[j][i] == vc[j][i-1]) {
					arr[now][point++][j] = vc[j][i]*2;
					i--;
				}else{
                    arr[now][point++][j] = vc[j][i];
                }
			}
		}
	}
	// for(int i=0;i<n;i++){
	//     for(int j=0;j<n;j++){
	//         cout << arr[now][i][j] << ' ';
	//     }
	//     cout << '\n';
	// }
    //    cout << '\n';
	for(int i=0; i<4; i++) {
		go(now+1,i);
		for(int a=0; a<n; a++) {
			for(int b=0; b<n; b++) {
				arr[now+1][a][b] = 0;
			}
		}
	}
}

int main() {
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> arr[0][i][j];
		}
	}
	for(int i=0;i<4;i++){
	    go(1,i); 
        for(int a=0; a<n; a++) {
			for(int b=0; b<n; b++) {
				arr[1][a][b] = 0;
			}
		}
	}
	cout << mmx;
}