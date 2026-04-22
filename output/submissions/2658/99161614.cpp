#include <bits/stdc++.h>

using namespace std;

string mp[20];
string chkmp[20];

vector<int> column;
int mid;
vector<int> row;
vector<pair<int,int>> ans;

int main() {
	for(int i=0; i<10; i++) {
		cin >> mp[i];
		chkmp[i] = mp[i];
	}
	for(int t=0; t<=3; t++) {
		int flag = 0;
		column.clear();
		row.clear();
		for(int i=0; i<10; i++) {
			int cnt = 0;
			for(int j=0; j<10; j++) {
				if(mp[i][j] == '1') {
					cnt++;
				}
			}
			column.push_back(cnt);
		}
		while(!column.empty() && !column[0]) {
			column.erase(column.begin());
		}
		while(!column.empty() && !column[column.size()-1]) {
			column.pop_back();
		}
		for(int j=0; j<10; j++) {
			int cnt = 0;
			for(int i=0; i<10; i++) {
				if(mp[i][j] == '1') {
					cnt++;
				}
			}
			row.push_back(cnt);
		}
		while(!row.empty() && !row[0]) {
			row.erase(row.begin());
		}
		while(!row.empty() && !row[row.size()-1]) {
			row.pop_back();
		}
		int start = 0;
		for(int i=0; i<=column.size()/2; i++) {
			if(column[column.size()/2-i] != column[column.size()/2+i]) {
				flag = 1;
				break;
			}
			if(i != column.size()/2 && column[i] != ++start) {
				flag = 1;
				break;
			}
		}
		if(column.size() < 3) {
			flag = 1;
		}
		start = 1;
		for(int i=0; i<row.size()-1; i++) {
			if(row[i] != start) {
				flag = 1;
				break;
			}
			start+=2;
		}
		if(row.size()*2 -1 != column.size()){
		    flag = 1;
		}
		if(!flag) {
			for(int j=0; j<10; j++) {
				for(int i=0; i<10; i++) {
					if(mp[i][j] == '1') {
						int ti = i+1;
						int tj = j+1;
						for(int k=0; k<t; k++) {
							int tti=10-tj+1;
							int ttj = ti;
							ti = tti;
							tj = ttj;
						}
						ans.push_back({ti,tj});
						i = 12;
						j = 12;
					}
				}
			}
			for(int i=0; i<10; i++) {
				for(int j=0; j<10; j++) {
					if(mp[i][j] == '1') {
						int ti = i+1;
						int tj = j+1;
						for(int k=0; k<t; k++) {
							int tti=10-tj+1;
							int ttj = ti;
							ti = tti;
							tj = ttj;
						}
						ans.push_back({ti,tj});
						i = 12;
						j = 12;
					}
				}
			}
			for(int i=0; i<10; i++) {
				for(int j=0; j<10; j++) {
					if(mp[10-i-1][j] == '1') {
						int ti = 10-i;
						int tj = j+1;
						for(int k=0; k<t; k++) {
							int tti=10-tj+1;
							int ttj = ti;
							ti = tti;
							tj = ttj;
						}
						ans.push_back({ti,tj});
						i = 12;
						j = 12;
					}
				}
			}
			break;
		}
		for(int i=0; i<10; i++) {
			for(int j=0; j<10; j++) {
				chkmp[i][j]= mp[10-j-1][i];
			}
		}
		for(int i=0; i<10; i++) {
			for(int j=0; j<10; j++) {
				mp[i][j] = chkmp[i][j];
			}
		}
	}
	if(!ans.empty()) {
		sort(ans.begin(),ans.end());
		for(auto [i,j] : ans) {
			cout << i << ' ' << j << '\n';
		}
		return 0;
	}
    for(int t=0; t<=3; t++) {
		int flag = 0;
		column.clear();
		row.clear();
		for(int i=0; i<10; i++) {
			int cnt = 0;
			for(int j=0; j<10; j++) {
				if(mp[i][j] == '1') {
					cnt++;
				}
			}
			column.push_back(cnt);
		}
		while(!column.empty() && !column[0]) {
			column.erase(column.begin());
		}
		while(!column.empty() && !column[column.size()-1]) {
			column.pop_back();
		}
		for(int j=0; j<10; j++) {
			int cnt = 0;
			for(int i=0; i<10; i++) {
				if(mp[i][j] == '1') {
					cnt++;
				}
			}
			row.push_back(cnt);
		}
		while(!row.empty() && !row[0]) {
			row.erase(row.begin());
		}
		while(!row.empty() && !row[row.size()-1]) {
			row.pop_back();
		}
		int start = 1;
		for(int i=0; i<column.size()-1; i++) {
			if(column[i] != start) {
				flag = 1;
				break;
			}
			start+=1;
		}
		if(column.size() < 2) {
			flag = 1;
		}
		start = 1;
		for(int i=0; i<row.size()-1; i++) {
			if(row[i] != start) {
				flag = 1;
				break;
			}
			start+=1;
		}
		if(row.size() < 2) {
			flag = 1;
		}
		if(row.size() != column.size()){
		    flag = 1;
		}
		if(!flag) {
			for(int j=0; j<10; j++) {
				for(int i=0; i<10; i++) {
					if(mp[i][j] == '1') {
						int ti = i+1;
						int tj = j+1;
						for(int k=0; k<t; k++) {
							int tti=10-tj+1;
							int ttj = ti;
							ti = tti;
							tj = ttj;
						}
						ans.push_back({ti,tj});
						i = 12;
						j = 12;
					}
				}
			}
			for(int i=0; i<10; i++) {
				for(int j=0; j<10; j++) {
					if(mp[i][j] == '1') {
						int ti = i+1;
						int tj = j+1;
						for(int k=0; k<t; k++) {
							int tti=10-tj+1;
							int ttj = ti;
							ti = tti;
							tj = ttj;
						}
						ans.push_back({ti,tj});
						i = 12;
						j = 12;
					}
				}
			}
			for(int i=0; i<10; i++) {
				for(int j=9; j>=0; j--) {
					if(mp[10-i-1][j] == '1') {
						int ti = 10-i;
						int tj = j+1;
						for(int k=0; k<t; k++) {
							int tti=10-tj+1;
							int ttj = ti;
							ti = tti;
							tj = ttj;
						}
						ans.push_back({ti,tj});
						i = 12;
						j = -1;
					}
				}
			}
			break;
		}
		for(int i=0; i<10; i++) {
			for(int j=0; j<10; j++) {
				chkmp[i][j]= mp[10-j-1][i];
			}
		}
		for(int i=0; i<10; i++) {
			for(int j=0; j<10; j++) {
				mp[i][j] = chkmp[i][j];
			}
		}
	}
	if(!ans.empty()) {
		sort(ans.begin(),ans.end());
		for(auto [i,j] : ans) {
			cout << i << ' ' << j << '\n';
		}
		return 0;
	}
	cout << 0;
}