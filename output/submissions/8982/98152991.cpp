#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n;

vector<pair<lint,lint>> point;
vector<pair<lint,lint>> block;
vector<pair<lint,lint>> revised;
lint k;
bool hole[10000];

map<pair<lint,lint>,pair<lint,lint>> mp;

lint sum;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i=0; i<n; i++) {
		lint x,y;
		cin >> x >> y;
		point.push_back({x,y});
	}
	cin >> k;
	for(int i=0; i<k; i++) {
		lint x,y, nx,ny;
		cin >> x >> y >> nx >> ny;
		mp[{x,y}] = {nx,ny};
	}
	lint nowx = 0,nowy = 0;
	for(int i=1; i<n; i++) {
		if(!(i%2)) {
			nowx += point[i].first - point[i-1].first;
			block.push_back({point[i].first - point[i-1].first,nowy});
			revised.push_back({point[i].first - point[i-1].first,nowy});
			if(mp.find(point[i-1]) != mp.end()) {
				hole[block.size()-1] = 1;
			}
		}
		else {
			nowy += point[i].second - point[i-1].second;
		}
	}
	for(int i=0; i<block.size(); i++) {
		if(hole[i]) {
			lint now = block[i].second;
			lint j = i;
			while(j >= 0) {
				now = min(now,block[j].second);
				revised[j].second = min(revised[j].second,block[j].second-now);
				j--;
			}
			j = i+1;
			now = block[i].second;
			while(j < n) {
				now = min(now,block[j].second);
				revised[j].second = min(revised[j].second,block[j].second-now);
				j++;
			}
		}
	}
	for(auto [wide,height] : revised) {
		//cout << wide << ' ' << height << '\n';
		sum += wide*height;
	}
	cout << sum;
}