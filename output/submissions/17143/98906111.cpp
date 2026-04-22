#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int r,c,m;

typedef struct {
	int s;
	int d;
	int z;
} shark;

shark tank[200][200][200];

lint ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);
	cin >> r >> c >> m;
	for(int a=0; a<m; a++) {
		int i,j,s,d,z;
		cin >> i >> j >> s >> d >> z;
		if(d == 1) {
			s %= r*2-2;
		} else if(d == 2) {
			s %= r*2-2;
		} else if(d == 3) {
			s %= c*2-2;
		} else {
			s %= c*2-2;
		}
		tank[0][i][j] = {s,d,z};
	}
	for(int t=0; t<c; t++) {
		for(int i=1; i<=r; i++) {
			if(tank[t][i][t+1].d) {
				ans += tank[t][i][t+1].z;
				tank[t][i][t+1] = {0,0,0};
				break;
			}
		}
		for(int i=1; i<=r; i++) {
			for(int j=1; j<=c; j++) {
				switch(tank[t][i][j].d) {
				case 1:
					if(i-tank[t][i][j].s <= 1) {
						if(2-(i-tank[t][i][j].s) >= r) {
							if(tank[t+1][2*r-(2-(i-tank[t][i][j].s))][j].z < tank[t][i][j].z) {
								tank[t+1][2*r-(2-(i-tank[t][i][j].s))][j] = {tank[t][i][j].s,1,tank[t][i][j].z};
							}
						} else {
							if(tank[t+1][2-(i-tank[t][i][j].s)][j].z < tank[t][i][j].z) {
								tank[t+1][2-(i-tank[t][i][j].s)][j] = {tank[t][i][j].s,2,tank[t][i][j].z};
							}
						}
					} else {
						if(tank[t+1][i-tank[t][i][j].s][j].z < tank[t][i][j].z) {
							tank[t+1][i-tank[t][i][j].s][j] = {tank[t][i][j].s,1,tank[t][i][j].z};
						}
					}
					break;
				case 2:
					if(i+tank[t][i][j].s >= r) {
						if(2*r-(i+tank[t][i][j].s) <= 1) {
							if(tank[t+1][2-(2*r-(i+tank[t][i][j].s))][j].z < tank[t][i][j].z) {
								tank[t+1][2-(2*r-(i+tank[t][i][j].s))][j] = {tank[t][i][j].s,2,tank[t][i][j].z};
							}
						} else {
							if(tank[t+1][2*r-(i+tank[t][i][j].s)][j].z < tank[t][i][j].z) {
								tank[t+1][2*r-(i+tank[t][i][j].s)][j] = {tank[t][i][j].s,1,tank[t][i][j].z};
							}
						}
					} else {
						if(tank[t+1][i+tank[t][i][j].s][j].z < tank[t][i][j].z) {
							tank[t+1][i+tank[t][i][j].s][j] = {tank[t][i][j].s,2,tank[t][i][j].z};
						}
					}
					break;
				case 3:
				if(j+tank[t][i][j].s >= c) {
						if(2*c-(j+tank[t][i][j].s) <= 1) {
							if(tank[t+1][i][2-(2*c-(j+tank[t][i][j].s))].z < tank[t][i][j].z) {
								tank[t+1][i][2-(2*c-(j+tank[t][i][j].s))] = {tank[t][i][j].s,3,tank[t][i][j].z};
							}
						} else {
							if(tank[t+1][i][2*c-(j+tank[t][i][j].s)].z < tank[t][i][j].z) {
								tank[t+1][i][2*c-(j+tank[t][i][j].s)] = {tank[t][i][j].s,4,tank[t][i][j].z};
							}
						}
					} else {
						if(tank[t+1][i][j+tank[t][i][j].s].z < tank[t][i][j].z) {
							tank[t+1][i][j+tank[t][i][j].s] = {tank[t][i][j].s,3,tank[t][i][j].z};
						}
					}
					break;
				case 4:
				if(j-tank[t][i][j].s <= 1) {
						if(2-(j-tank[t][i][j].s) >= c) {
							if(tank[t+1][i][2*c-(2-(j-tank[t][i][j].s))].z < tank[t][i][j].z) {
								tank[t+1][i][2*c-(2-(j-tank[t][i][j].s))] = {tank[t][i][j].s,4,tank[t][i][j].z};
							}
						} else {
							if(tank[t+1][i][2-(j-tank[t][i][j].s)].z < tank[t][i][j].z) {
								tank[t+1][i][2-(j-tank[t][i][j].s)] = {tank[t][i][j].s,3,tank[t][i][j].z};
							}
						}
					} else {
						if(tank[t+1][i][j-tank[t][i][j].s].z < tank[t][i][j].z) {
							tank[t+1][i][j-tank[t][i][j].s] = {tank[t][i][j].s,4,tank[t][i][j].z};
						}
					}
					
					break;
				}
			}
		}
	}
	cout << ans;
}